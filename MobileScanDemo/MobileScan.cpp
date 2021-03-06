#include "MobileScan.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>
#include <QDateTime>
CMobileScan::CMobileScan(QWidget *parent):QWidget(parent)
{
    char szLogName[256] = { "/Afc/Log/DeviceCommomFunc_MobileScan.log" };
    char szLogInstanceName[256] = {"DeviceCommomFunc_MobileScan" };
    if(!m_CommonFuncLog.InitLogInstance("/Afc/Config/SLELog.ini", szLogInstanceName))
    {
            m_CommonFuncLog.SetConfigureFile("/Afc/Config/SLELog.ini", szLogInstanceName, szLogName, 10485760, 10, "DEBUG");
    }
    m_CommonFuncLog.LogInfo("%s.%s()-[%d]*******************************************************************", __FILE__, __FUNCTION__, __LINE__);
    m_CommonFuncLog.LogInfo("%s.%s()-[%d]*                                                                 *", __FILE__, __FUNCTION__, __LINE__);
    m_CommonFuncLog.LogInfo("%s.%s()-[%d]* DeviceCommomFunc_MobileScan(Compile Date) = [%s %s]	     *",             __FILE__, __FUNCTION__, __LINE__, __DATE__, __TIME__);
    m_CommonFuncLog.LogInfo("%s.%s()-[%d]*                                                                 *", __FILE__, __FUNCTION__, __LINE__);
    m_CommonFuncLog.LogInfo("%s.%s()-[%d]*******************************************************************", __FILE__, __FUNCTION__, __LINE__);

    m_MobileScan = new CMobileScanPayCommonFunc(&m_CommonFuncLog);
    m_bIsConnet = false;
    m_bIsInTrans = false;
    m_bIsInit = false;
    m_bThread = false;
    m_bThreadExit = false;

    pthread_mutex_init(&m_EvenThreadMutex,NULL);

    sem_init(&m_DataSem,0,0);
    sem_init(&m_PaymentSem,0,0);
    sem_init(&m_FailureSem,0,0);

    memset(&m_stStatus,0,sizeof(m_stStatus));
    InitWidgets();

    QObject::connect(m_ConnetBtn,SIGNAL(clicked()),this,SLOT(on_click_Connet_Btn()));
    QObject::connect(m_DisconnetBtn,SIGNAL(clicked()),this,SLOT(on_click_Disconnet_Btn()));
    QObject::connect(m_PaymentBeginBtn,SIGNAL(clicked()),this,SLOT(on_click_PaymentBegin_Btn()));
    QObject::connect(m_CancelPaymentBtn,SIGNAL(clicked()),this,SLOT(on_click_CancelPayment_Btn()));
    QObject::connect(m_GetStatusBtn,SIGNAL(clicked()),this,SLOT(on_click_GetStatus_Btn()));
    QObject::connect(this,SIGNAL(New_QRCode_has_Created()),this,SLOT(create_QRCode_and_Show()));
}
void CMobileScan::QRCodeDataNotify(const void *pData)
{
    if(NULL != pData)
        strcpy(m_szQRCodeData,(char *)pData);
    sem_post(&m_DataSem);
}

void CMobileScan::PaymentNotify(const void *pData)
{
    if(NULL != pData)
        memcpy(&m_stPayResult,pData,sizeof(m_stPayResult));
    sem_post(&m_PaymentSem);
}

void CMobileScan::FailtureNotify(const void *pData)
{
//    if(NULL != pData)
//        return;
    sem_post(&m_FailureSem);
}

void CMobileScan::on_click_Connet_Btn()
{
    if(m_bIsConnet)
    {
        m_TextShow->append("已连接");
        return;
    }

    if(m_MobileScan->Connect(NULL))
    {
        m_TextShow->append("连接成功");
        m_MobileScan->RegEventHandler((CIWebPayEvenHandler*)this);
        char Addr[100];
        sprintf(Addr,"%p",this);
        m_TextShow->append(Addr);
        m_bIsConnet = true;
    }
    else
    {
        m_TextShow->append("连接失败");
        m_bIsConnet = false;
    }
    if(!m_bThread)
    {
        int iRet = pthread_create(&m_EventThreadId,NULL,EventCatchThread,(void*)this);
        if(0 != iRet)
        {
            qDebug() << iRet;
            m_bThread = false;
            m_TextShow->append("创建EventCatchThread线程失败" + QString("%1").arg(iRet));
        }
        else
        {
            m_bThread = true;
            m_TextShow->append("创建EventCatchThread线程成功");
        }
    }
}

void CMobileScan::on_click_Disconnet_Btn()
{
    if(!m_bIsConnet)
    {
        m_TextShow->append("未连接");
        return ;
    }
    m_MobileScan->Disconnect();
    m_TextShow->append("断开连接");
    m_bIsConnet = false;

    if(m_bThread)
    {
        m_bThread = false;
        while(!m_bThreadExit)
        {
            usleep(300);
        }
        void * pThread_exit;
        pthread_join(m_EventThreadId,&pThread_exit);
        pthread_mutex_destroy(&m_EvenThreadMutex);
        m_TextShow->append("EventCatchThread线程销毁成功");
    }
}

void CMobileScan::on_click_PaymentBegin_Btn()
{
    memset(&m_stTranInfo,0,sizeof(m_stTranInfo));
    if(!m_bIsConnet)
    {
        m_TextShow->append("未连接");
        return ;
    }
    if(m_PayMethodEdit->text().isEmpty())
    {
        m_TextShow->append("请输入支付方式");
        return ;
    }
    if(m_EndStationEdit->text().isEmpty())
    {
        m_TextShow->append("票价购票");
        m_stTranInfo.dwDesStationID = 0;
    }
    else
    {
        m_TextShow->append("站点购票");
        m_stTranInfo.dwDesStationID = m_EndStationEdit->text().toInt();
    }
    if(m_bIsInTrans)
    {
         m_TextShow->append("交易中");
         return;
    }
    memset(&m_stTranInfo,0,sizeof(m_stTranInfo));

    m_stTranInfo.emPaySubMethod = (EM_PAYMENT_SUB_METHOD)m_PayMethodEdit->text().toInt();
    m_stTranInfo.iUnitPrice = m_PriceEdit->text().toInt();
    m_stTranInfo.iCountFromPassenger = m_TicketCountEdit->text().toInt();
    strcpy(m_stTranInfo.szBeginDate,QDateTime::currentDateTime().toString("yyyyMMdd").toStdString().c_str());
    strcpy(m_stTranInfo.szBeginTime,QDateTime::currentDateTime().toString("hhmmss").toStdString().c_str());

    m_iNeedPayAmount = m_TicketCountEdit->text().toInt() * m_PriceEdit->text().toInt();
    if(!m_MobileScan->paymentBegin((void *)&m_stTranInfo))
    {
        m_bIsInTrans = false;
        m_TextShow->append("提交订单失败");
        return;
    }
    else
    {
        m_bIsInTrans = true;
        m_TextShow->append("提交订单成功");
    }
}

void CMobileScan::on_click_GetStatus_Btn()
{
    if(!m_bIsConnet)
    {
        m_TextShow->append("未连接");
        return ;
    }
    m_MobileScan->GetDeviceStatus((void*)&m_stStatus);
    m_TextShow->append(QString("通用状态:%1").arg(m_stStatus.emCommonState));
    if(m_stStatus.iErrorCodeNumber > 0)
    {
        for(int i = 0 ;i < m_stStatus.iErrorCodeNumber; i++)
            m_TextShow->append(QString("故障码:%1%2").arg(m_stStatus.stErrorCode[i].iErrorCode).arg(m_stStatus.stErrorCode[i].czAdditionalInfo));
    }
}

void CMobileScan::on_click_CancelPayment_Btn()
{
    if(!m_bIsConnet)
    {
        m_TextShow->append("未连接");
        return ;
    }
    if(!m_bIsInTrans)
    {
        m_TextShow->append("没有交易可以取消");
        return ;
    }
    else if(m_bIsBusy)
    {
        m_TextShow->append("交易正忙");
        return ;
    }
    strcpy(m_stTranInfo.szEndDate,QDateTime::currentDateTime().toString("yyyyMMdd").toStdString().c_str());
    strcpy(m_stTranInfo.szEndTime,QDateTime::currentDateTime().toString("hhmmss").toStdString().c_str());

    if(!m_MobileScan->cancelPayment((void*)&m_stTranInfo))
    {
        m_TextShow->append("取消交易失败");
    }
    else
    {
        m_TextShow->append("取消交易成功");
        m_bIsInTrans = false;
        m_bIsBusy = false;
        HidePic();
    }
}
void CMobileScan::create_QRCode_and_Show()
{
    QPixmap pix(QString("%1/%2").arg(FILEPATH).arg(FILENAME));
    pix = pix.scaled(m_QRCodeLabel->width(),m_QRCodeLabel->height(),Qt::KeepAspectRatio);
    m_QRCodeLabel->setPixmap(pix);
    m_QRCodeLabel->show();

    if(EM_PAYMENT_SUB_METHOD_ALIPAY == m_stTranInfo.emPaySubMethod)
    {
        m_AliPay->show();
        m_AliPay->raise();
        m_WechatPay->hide();
    }
    else
    {
        m_WechatPay->show();
        m_WechatPay->raise();
        m_AliPay->hide();
    }
}

void * CMobileScan::EventCatchThread(void *arg)
{
    CMobileScan* pMobileScan = (CMobileScan*)arg;
    while(pMobileScan->m_bThread)
    {
        if(!sem_trywait(&pMobileScan->m_DataSem))
        {
            pthread_mutex_lock(&pMobileScan->m_EvenThreadMutex);
            pMobileScan->m_TextShow->append("m_DataSem");
            pMobileScan->m_TextShow->append("QRCode:" + QString("%1").arg(pMobileScan->m_szQRCodeData));
            char szFaultInfo[256] = {0};
            if(!GenerateQRCode(pMobileScan->m_szQRCodeData,FILEPATH,FILENAME,szFaultInfo))
            {
                pMobileScan->m_TextShow->append("生成二维码失败");
            }
            else
            {
                pMobileScan->m_TextShow->append("生成二维码成功");
                emit pMobileScan->New_QRCode_has_Created();
            }
            pthread_mutex_unlock(&pMobileScan->m_EvenThreadMutex);
        }
        if(!sem_trywait(&pMobileScan->m_PaymentSem))
        {
            pthread_mutex_lock(&pMobileScan->m_EvenThreadMutex);
            pMobileScan->m_bIsBusy = true;
            pMobileScan->m_TextShow->append("m_PaymentSem");
            QString string = QString("szOrderNo:%1\n szUserName:%2\n szAmount:%3\n szPaymentAccount:%4\n szPaymentResult:%5\n szPaymentDesc:%6").\
                    arg(pMobileScan->m_stPayResult.szOrderNo).arg(pMobileScan->m_stPayResult.szUserName).\
                    arg(pMobileScan->m_stPayResult.szAmount).arg(pMobileScan->m_stPayResult.szPaymentAccount)\
                    .arg(pMobileScan->m_stPayResult.szPaymentResult).arg(pMobileScan->m_stPayResult.szPaymentDesc);
            pMobileScan->m_TextShow->append(string);

            if(QString(pMobileScan->m_stPayResult.szAmount).toInt() == pMobileScan->m_iNeedPayAmount)
            {
                strcpy(pMobileScan->m_stTranInfo.szEndDate,QDateTime::currentDateTime().toString("yyyyMMdd").toStdString().c_str());
                strcpy(pMobileScan->m_stTranInfo.szEndTime,QDateTime::currentDateTime().toString("hhmmss").toStdString().c_str());
                pMobileScan->m_stTranInfo.iTransCount = pMobileScan->m_TicketOutEdit->text().toInt();
                pMobileScan->m_MobileScan->confirmPayment((void*)&pMobileScan->m_stTranInfo);
                pMobileScan->m_bIsInTrans = false;
                pMobileScan->HidePic();
            }
            pMobileScan->m_bIsBusy = false;
            pthread_mutex_unlock(&pMobileScan->m_EvenThreadMutex);
        }
        if(!sem_trywait(&pMobileScan->m_FailureSem))
        {
            pMobileScan->m_bIsBusy = true;
            pMobileScan->m_TextShow->append("m_FailureSem");
            pMobileScan->m_stTranInfo.iTransCount = 0;
            strcpy(pMobileScan->m_stTranInfo.szEndDate,QDateTime::currentDateTime().toString("yyyyMMdd").toStdString().c_str());
            strcpy(pMobileScan->m_stTranInfo.szEndTime,QDateTime::currentDateTime().toString("hhmmss").toStdString().c_str());
            pMobileScan->m_MobileScan->confirmPayment((void*)&pMobileScan->m_stTranInfo);
            pMobileScan->m_bIsBusy = false;
            pMobileScan->m_bIsInTrans = false;
            pMobileScan->HidePic();
        }
    }
    pMobileScan->m_bThreadExit  = true;
    return NULL;
}

void CMobileScan::HidePic()
{
    m_AliPay->hide();
    m_QRCodeLabel->hide();
    m_WechatPay->hide();
}

CMobileScan::~CMobileScan()
{
    if(m_bIsConnet)
       m_MobileScan->Disconnect();

    if(m_bThread)
    {
        m_bThread = false;
        while(!m_bThreadExit)
        {
            usleep(300);
        }
        void * pThread_exit;
        pthread_join(m_EventThreadId,&pThread_exit);
        pthread_mutex_destroy(&m_EvenThreadMutex);
    }
    delete m_ConnetBtn;
    delete m_DisconnetBtn;
    delete m_PaymentBeginBtn;
    delete m_CancelPaymentBtn;
    delete m_GetStatusBtn;
    delete m_PayMethodLabel;
    delete m_EndStationLabel;
    delete m_PriceLabel;
    delete m_TicketCountLabel;
    delete m_TicketOutLabel;
    delete m_PayMethodEdit;
    delete m_EndStationEdit;
    delete m_PriceEdit;
    delete m_TicketCountEdit;
    delete m_TicketOutEdit;
    delete m_TextShow;
    delete m_QRCodeLabel;
    delete m_AliPay;
    delete m_WechatPay;
}

void CMobileScan::InitWidgets()
{
    int iLeft = 0, iTop = 0;
    m_ConnetBtn = new QPushButton(this);
    m_ConnetBtn->setText("连接");
    m_ConnetBtn->setGeometry(iLeft,iTop,50,30);
    iLeft += 50;
    m_GetStatusBtn = new QPushButton(this);
    m_GetStatusBtn->setText("状态");
    m_GetStatusBtn->setGeometry(iLeft,iTop,50,30);
    iLeft += 50;
    m_DisconnetBtn = new QPushButton(this);
    m_DisconnetBtn->setText("断开连接");
    m_DisconnetBtn->setGeometry(iLeft,iTop,100,30);
    iLeft += 100;
    m_PaymentBeginBtn = new QPushButton(this);
    m_PaymentBeginBtn->setText("交易开始");
    m_PaymentBeginBtn->setGeometry(iLeft,iTop,100,30);
    iLeft += 100;
    m_CancelPaymentBtn = new QPushButton(this);
    m_CancelPaymentBtn->setText("取消交易");
    m_CancelPaymentBtn->setGeometry(iLeft,iTop,100,30);

    m_TextShow = new QTextEdit(this);
    m_TextShow->setGeometry(400,0,400,400);

    QRegExp regExp("([1-2]{1}$)");

    iLeft = 0;
    iTop += 40;
    m_PayMethodEdit = new QLineEdit(this);
    m_PayMethodEdit->setText("2");
    m_PayMethodEdit->setGeometry(iLeft,iTop,50,30);
    m_PayMethodEdit->setValidator(new QRegExpValidator(regExp, this));

    iTop += 30;
//    m_StartStationEdit = new QLineEdit(this);
//    m_StartStationEdit->setGeometry(iLeft,iTop,50,30);
//    iTop += 30;
    m_EndStationEdit = new QLineEdit(this);
    m_EndStationEdit->setGeometry(iLeft,iTop,50,30);
    iTop += 30;
    m_PriceEdit = new QLineEdit(this);
    m_PriceEdit->setText("200");
    m_PriceEdit->setGeometry(iLeft,iTop,50,30);
    iTop += 30;
    m_TicketCountEdit = new QLineEdit(this);
    m_TicketCountEdit->setText("1");
    m_TicketCountEdit->setGeometry(iLeft,iTop,50,30);
    iTop += 30;
    m_TicketOutEdit = new QLineEdit(this);
    m_TicketOutEdit->setText("1");
    m_TicketOutEdit->setGeometry(iLeft,iTop,50,30);

    iLeft = 50;
    iTop = 40;
    m_PayMethodLabel = new QLabel(this);
    m_PayMethodLabel->setText("支付方式(1:微信2:支付宝)");
    m_PayMethodLabel->setGeometry(iLeft,iTop,200,30);
    iTop += 30;
    m_EndStationLabel = new QLabel(this);
    m_EndStationLabel->setText("终点站");
    m_EndStationLabel->setGeometry(iLeft,iTop,200,30);
    iTop += 30;
    m_PriceLabel = new QLabel(this);
    m_PriceLabel->setText("票价");
    m_PriceLabel->setGeometry(iLeft,iTop,200,30);
    iTop += 30;
    m_TicketCountLabel = new QLabel(this);
    m_TicketCountLabel->setText("张数");
    m_TicketCountLabel->setGeometry(iLeft,iTop,200,30);

    iTop += 30;
    m_TicketOutLabel = new QLabel(this);
    m_TicketOutLabel->setText("实际出票张数");
    m_TicketOutLabel->setGeometry(iLeft,iTop,200,30);

    m_PixMap.load(ALIPAY);
    m_AliPay = new QLabel(this);
    m_AliPay->setGeometry(280,280,40,40);
    m_PixMap = m_PixMap.scaled(m_AliPay->width(),m_AliPay->height(),Qt::KeepAspectRatio);
    m_AliPay->setPixmap(m_PixMap);
    m_AliPay->hide();

    m_PixMap.load(WECHATPAY);
    m_WechatPay = new QLabel(this);
    m_WechatPay->setGeometry(280,280,40,40);
    m_PixMap = m_PixMap.scaled(m_AliPay->width(),m_AliPay->height(),Qt::KeepAspectRatio);
    m_WechatPay->setPixmap(m_PixMap);
    m_WechatPay->hide();

    m_QRCodeLabel = new QLabel(this);
    m_QRCodeLabel->setGeometry(200,200,200,200);
}

