#ifndef MOBILESCAN_H
#define MOBILESCAN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QPixmap>

#include "CLogOper2.h"
#include "MobileScanCommonFunc.h"
#include "MobileScanPayCommonDef.h"
#include "IWebPayEvenHandler.h"
#include "qrcodecreate.h"
#include "qrencode.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define FILEPATH "/root/johnson/MobileScan/MobileScanDemo/Pic"
#define FILENAME "PayInfo.bmp"

#define ALIPAY "/root/johnson/MobileScan/MobileScanDemo/Pic/alipay.png"
#define WECHATPAY "/root/johnson/MobileScan/MobileScanDemo/Pic/wechat.png"

class CMobileScan : public QWidget ,public CIWebPayEvenHandler
{
    Q_OBJECT

public:
    CMobileScan(QWidget *parent = 0);
    ~CMobileScan();

public:
    CLogOper2 m_CommonFuncLog;

    CMobileScanPayCommonFunc *m_MobileScan;

    bool m_bIsConnet;
    bool m_bIsInit;
    bool m_bIsInTrans;
    bool m_bIsBusy;

    int m_iNeedPayAmount;
private:
    ST_TVM_PASSENGER_TRANS m_stTranInfo;  //交易记录

    ST_SNAP_QRCODE_PAY_RESULT_RESP m_stPayResult;  //支付结果
    char m_szQRCodeData[1025];                   //二维码信息

    ST_MOBILESCAN_STATUS m_stStatus;            //状态

    bool m_bThread;                             //线程运行标记
    bool m_bThreadExit;                         //线程退出标记
    pthread_t m_EventThreadId;                  //线程ID
    pthread_mutex_t m_EvenThreadMutex;          //线程锁

    sem_t m_DataSem;                            //接收到数据信号量
    sem_t m_PaymentSem;                         //支付信号量
    sem_t m_FailureSem;                         //错误信号量

private:
    static void * EventCatchThread(void *arg);  //线程

//控件
private:
    QPushButton *m_ConnetBtn;            //连接
    QPushButton *m_DisconnetBtn;            //断开连接
    QPushButton *m_PaymentBeginBtn;         //开始交易
    QPushButton *m_CancelPaymentBtn;        //取消交易
    QPushButton *m_GetStatusBtn;        //获取状态

    QLabel *m_PayMethodLabel;            //支付方式
    QLineEdit *m_PayMethodEdit;

    QLabel *m_StartStationLabel;         //起点站
    QLineEdit *m_StartStationEdit;

    QLabel *m_EndStationLabel;           //终点站
    QLineEdit *m_EndStationEdit;

    QLabel *m_PriceLabel;                //单价
    QLineEdit *m_PriceEdit;

    QLabel *m_TicketCountLabel;          //张数
    QLineEdit *m_TicketCountEdit;

    QLabel *m_TicketOutLabel;          //实际出票张数
    QLineEdit *m_TicketOutEdit;

    QLabel *m_QRCodeLabel;              //二维码展示
    QLabel *m_AliPay;
    QLabel *m_WechatPay;

    QPixmap m_PixMap;

    QTextEdit *m_TextShow;

private:
    void InitWidgets();

    void HidePic();

protected:
    void QRCodeDataNotify(const void * pData);
    void PaymentNotify(const void * pData);
    void FailtureNotify(const void * pData);

public slots:
    void on_click_Connet_Btn();
    void on_click_Disconnet_Btn();
    void on_click_PaymentBegin_Btn();
    void on_click_CancelPayment_Btn();
    void on_click_GetStatus_Btn();
    void create_QRCode_and_Show();

signals:
    void New_QRCode_has_Created();
};

#endif // MOBILESCAN_H
