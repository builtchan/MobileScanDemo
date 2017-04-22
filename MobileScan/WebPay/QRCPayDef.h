/*
 * QRCPayDef.h
 *
 *  Created on: 2017-4-12
 *      Author: root
 */

#ifndef QRCPAYDEF_H_
#define QRCPAYDEF_H_

#define PAYMENT_VENDER_UNIONPAY		  						  1//银联，0001～0FFF为银行/银联通道，含基金公司支付通道
#define PAYMENT_VENDER_ALIPAY								1001//支付宝
#define PAYMENT_VENDER_WENXIN							1002//微信
#define PAYMENT_VENDER_LAKALA							1003//拉卡拉
#define PAYMENT_VENDER_CHINAMOBILE					1004//中国移动
#define PAYMENT_VENDER_WO									1005//沃
#define PAYMENT_VENDER_ESURFING						1006//天翼，1001～1FFF为第三方支付公司

typedef enum
{
	EM_OPERATION_SUCCESS = 0,//操作成功,继续执行下一步
	EM_PARA_ERROR = 1,//参数错误,直接执行S1-005订单执行故障
	EM_NO_PAYMENT_RESULT = 2,//未收到支付结果通知（支付中）,轮询执行S1-002支付结果查询请求
	EM_PAYMENT_ERROR = 3,//支付失败,直接执行S1-005订单执行故障
	EM_ORDER_CODE_ERROR = 4,//订单号码错误,直接执行S1-005订单执行故障
	EM_TOKEN_ERROR = 5,//Token错误,直接执行S1-005订单执行故障
	EM_ILLEGAL_DEVICE = 6,//非法设备编码,直接执行S1-005订单执行故障
	EM_NO_ORDER_PAYMENT = 7,//订单未支付,直接执行S1-005订单执行故障
	EM_TICKET_TAKEN = 8,//订单已取票,直接执行S1-005订单执行故障
	EM_ORDER_LOCKED = 9,//订单锁定,直接执行S1-005订单执行故障
	EM_ORDER_REFUND = 10,//订单已退款,直接执行S1-005订单执行故障
	EM_FILE_REC_SUCCESS = 11,//文件接收成功
	EM_FILE_LENGTH_ERROR = 12,//文件长度错
	EM_FILE_CHECK_ERROR = 13,//文件校验错
	EM_FILE_NOT_FOUND = 14,//文件未找到
	EM_NO_PREPAY_URL = 15,//未收到第三方预支付链接
	EM_SYSTEM_ERROR = 9999,//系统错误,直接执行S1-005订单执行故障
}EM_RESP_CODE;

typedef enum
{
	EM_ORDER_CANCEL = 1,//乘客取消订单
	EM_PREPAY_URL_OVERTIME = 2,//S1 -018 预支付链接获取超时
	EM_PAYMENT_RESULT_OVERTIME = 3,//获取支付结果超时
	EM_PART_TICKET_OUT_FAULT = 4,//部分出票失败
	EM_ALL_TICKET_OUT_FAULT = 5,//全部出票失败
	EM_QUERY_OVERTIME = 6,//查询超时
	EM_PAYMENT_CANCEL = 7,//撤销支付
}EM_ERROR_CODE;

struct ST_REQ_BASE
{
	char szReqSysDate[15];
	char szOperationCode[7];
	char szCityCode[5];
	char szDeviceId[11];
	char szChannelType[3];
};

struct ST_RESP_BASE
{
	EM_RESP_CODE emRespCode;
	char szRespCodeMemo[1001];
};

struct ST_ORDER_COMMIT_REQ
{
	char szPaymentVender[5];			//支付通道编码
	char szPickupStationCode[5];		//起点站代码
	char szGetoffStationCode[5];		//终点站代码
	char szSingleTicketPrice[7];		//单程票票价
	char szSingleTicketNum[3];			//购买数量
	char szSingleTicketType[2];			//是否时站点购票
};

struct ST_ORDER_COMMIT_RESP
{
	char szPartnerNo[4];
	char szOrderNo[31];
	char szSubject[256];
	char szBody[256];
	char szPayType[5];
	char szAmount[7];
	char szAccount[33];
	char szNotifyUrl[256];
	char szMerchantCert[129];
	int iTimeOut;
};

struct ST_ORDER_EXECUTE_RESULT_REQ
{
	char szOrderNo[31];					//唯一订单号
	int iTakeSingleTicketNum;			//实际交易数
	char szTakeSingleTicketDate[15];  	//交易日期
};

struct ST_ORDER_EXECUTE_FAULT_REQ
{
	char szOrderNo[31];
	int iTakeSingleTicketNum;
	char szFaultOccurDate[15];
	char szFaultSlipSeq[33];
	EM_ERROR_CODE emErrorCode;
	char szErrorMessage[256];
};

struct ST_SNAP_QRCODE_PREPAY_URL_QUERY_RESP
{
	char szOrderNo[31];
	char szDeviceId[11];
	char szQrCode[1025];
};

struct ST_SNAP_QRCODE_PAY_RESULT_REQ
{
	char szOrderNo[31];
	char szQrCode[1025];
};

struct ST_SNAP_QRCODE_PAY_RESULT_RESP
{
	char szOrderNo[31];
	char szPaymentDate[15];
	char szAmount[33];
	char szPaymentAccount[129];
	char szPaymentResult[17];
	char szPaymentDesc[256];
	char szUserName[101];
};

#endif /* QRCPAYDEF_H_ */
