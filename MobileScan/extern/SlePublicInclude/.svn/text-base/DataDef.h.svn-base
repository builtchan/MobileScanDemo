/*
 * XmlFileProc.h
 *
 *  Created on: 2016-7-13
 *      Author: root
 *      维修界面结构体 数据定义
 */

#ifndef XMLFILEPROC_H_
#define XMLFILEPROC_H_

typedef struct __DATA_QUERY_SYSTEM_STATUS__{
	char  mItemName[24];
	char  mItemStatus[24];
}ST_OPER_UI_DATA_QUERY_SYSTEM_STATUS;

typedef struct __TPU_STATUS__
{
	int mChangeFlag;
	int mResultCode;						//测试执行结果，用于无action类型的菜单测试(初始化/错误重置/状态请求)
	int mOverFlag;							//0测试未完成，1测试完成

	int mDeviceCommonStatus;				//设备通用状态
	int mFaultCodeNum;						//故障码计数
	char mFaultCodeInfo[256];					//故障码

	char mMainVer[256];							//主软件版本
	char mMainVerDate[256];						//主软件版本日期
	char mApiVer[256];							//Api识别版本
	char mApiVerDate[256];						//Api识别版本日期
	char mRfDrvVer[256];						//Rf驱动识别版本
	char mRfDrvVerDate[256];					//Rf驱动识别版本日期
	char mSamDrvVer[256];						//Sam驱动识别版本
	char mSamDrvVerDate[256];					//Sam驱动识别版本日期

	char mResultMsg[256];						//测试执行结果，用于action类型的配置子菜单测试(票箱解锁/RFID测试/综合测试)
}ST_OPER_UI_TPU_STATUS;


typedef struct  {
	int mChangeFlag;
	char mIPADDR[64];
	char mNETMASK[64];
	char mGATEWAY[64];
} ST_OPER_UI_IP_INFO;

typedef struct  {
	int mChangeFlag;
	char mRunDate[64];
	char mResultMsg[64];
	int mResultCode;
}ST_OPER_UI_RUN_DATE_INFO;



typedef struct
{
	char mParamId[24];
	char mParamTypeCn[64];
	char mDataBaseParamInfo[64];
	char mTpuCurParamInfo[64];
	char mIsNeedUpdate[64];
}ST_OPER_UI_TPU_PARAM_VALUE;

typedef struct
{
	ST_OPER_UI_TPU_PARAM_VALUE mTpuParamUpdates[12];

	int iTpuParamUpdateCount;
}ST_OPER_UI_TPU_PARAM;


typedef struct
{
	int mChangeFlag;
	int mResultCode;
	int mOverFlag;
	char mParamId[24];									//参数ID
	char mParamTypeCn[64];								//参数描述
	char mDataBaseParamInfo[64];						//数据库中参数版本信息
	char mTpuCurParamInfo[64];							//TPU内部参数版本信息
	char mIsNeedUpdate[64];							//是否需要升级
	char mUpdateStatus[512];							//升级状态
}ST_OPER_UI_TPU_PARAM_UPDATE;

//add by mabin 20170321
typedef struct _CSSCOINSTATUS_ {
	int mChangeFlag;
	int mResultCode;						//测试执行结果，用于无action类型的菜单测试(初始化/错误重置/状态请求)
	int mOverFlag;							//0测试未完成，1测试完成

	int mDeviceCommonStatus;				//设备通用状态

	int mAcceptState;						//当前是否允许现金投入
	int mCanAcceptCash;						//当前接收功能是否OK
	int mCanChangeCash;						//当前找零功能是否OK

	int mCashWdBoxOnePhysicsStatus;			//现金回收箱1物理状态
	int mCashWdBoxTwoPhysicsStatus;			//现金回收箱2物理状态

	int mLoopChangeBoxOnePhysicsStatus;		//循环找零箱1物理状态
	int mLoopChangeBoxTwoPhysicsStatus;		//循环找零箱2物理状态

	int mSpareChangeBoxOnePhysicsStatus;	//备用找零箱1物理状态
	int mSpareChangeBoxTwoPhysicsStatus;	//备用找零箱2物理状态

	int mChangeSupplyBoxOnePhysicsStatus;	//找零补充箱1物理状态
	int mChangeSupplyBoxTwoPhysicsStatus;	//找零补充箱2物理状态

	int mChangeWasteBoxOnePhysicsStatus;	//找零废钞回收箱1物理状态
	int mChangeWasteBoxTwoPhysicsStatus;	//找零废钞回收箱2物理状态(没有)

	int mRealFinishNum;						//压箱/退还/找零测试实际完成数量

	int mFaultCodeNum;						//故障码计数
	char mFaultCodeInfo[100];					//故障码

	char mMainVersion[100];						//主版本
	char mMainVersionDate[100];					//主板本日期
	char mHopperOneVersion[100];				//Hopper1版本(发行单元部件版本)
	char mHopperTwoVersion[100];				//Hopper2版本(发行单元部件版本)
	char mRfidVersion[100];						//Rfid版本(发行单元部件版本)

	char mRfidInfo[256];						//Rfid信息
	char mResultMsg[100];						//测试执行结果，用于action类型的配置子菜单测试(票箱解锁/RFID测试/综合测试)
} ST_CSSCOINSTATUS;
//add end 20170321
typedef struct _PRINTERSTATUS_ {
	int mChangeFlag;
	int mResultCode;						//测试执行结果，用于无action类型的菜单测试(初始化/错误重置/状态请求)
	int mOverFlag;							//0测试未完成，1测试完成

	int mDeviceCommonStatus;				//设备通用状态
	int mFaultCodeNum;						//故障码计数
	char mFaultCodeInfo[100];					//故障码

	char mMainVersion[100];						//主版本
	char mMainVerDate[100];						//主版本日期

	char mResultMsg[100];						//测试执行结果，用于action类型的配置子菜单测试(显示器颜色测试)
} ST_PRINTERSTATUS;

typedef struct _CSSDIOSTATUS_ {
	int mChangeFlag;
	int mResultCode;						//测试执行结果，用于无action类型的菜单测试(初始化/错误重置/状态请求)
	int mOverFlag;							//0测试未完成，1测试完成

	int mDeviceCommonStatus;				//设备通用状态
	int mFaultCodeNum;						//故障码计数
	char mFaultCodeInfo[100];					//故障码

	char mMainVersion[100];						//主版本
	char mMainVersionDate[100];					//主版本日期

	char mResultMsg[100];						//测试执行结果，用于action类型的配置子菜单测试(显示器颜色测试)
} ST_CSSDIOSTATUS;

#endif /* XMLFILEPROC_H_ */
