#ifndef SYNCCLOCKDEF_H_
#define SYNCCLOCKDEF_H_

/*关于时间概念的一些说明:
 *GMT 时间:	格林尼治时间,国际标准时间,中国位于东八区,时间为GMT + 8
 *UTC 时间:	通用协调时间,可以认为跟GMT 是一个概念
 *时间戳  :	NTP 服务器上的时间戳是从1900 年 1 月 1 日 0 点 0 分开始到现在的秒数(UTC 时间).
 *			而PC 机上的时间戳为1970 年 1 月 1 日 0 点 0 分 开始至今的秒数(程序中的time(NULL)返回的是UTC 时间).
 *			所以,要对PC 机的时间戳和时钟服务器时间戳进行校准时,需要在PC 机的时间戳基础上加上 1970-1900 的秒数:
 *			3600s * 24h * (365days * 70years + 17days)

 *NTP 协议相关:
 *T1	:请求数据包离开客户端的时间戳
 *T2	:请求数据包到达服务器的时间戳(由服务器返回)
 *T3	:反馈数据包从服务器返回的时间戳(由服务器返回)
 *T4	:反馈数据包到达客户端的时间戳

 *	客户端(发起请求)					服务器(提供反馈)
 *	T1--------------------------------->T2
 *	T4<---------------------------------T3
	
 *客户机与服务器间的时间差 = ((T2 - T1) + (T3 - T4)) >> 1
 *传输延时 = ((T2 - T1) - (T3 - T4)) >> 1 (假设来跟去的传输延时是一样的)
 *NTP packet = NTP header + Four TimeStamps = 48byte 

 *NTP header : 16byte
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 

 *|LI | VN |Mode | Stratum | Poll | Precision |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 
 *LeapYearIndicator : 2bit (闰年标志)
 *VersionNumber : 3bit (版本号)
 *Stratum : 8bit (服务器层次)
 *Mode : 3 bit 
 *PollInterval : 8 bit 
 *Percision : 8bit 

 *| Root Delay | 
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
 *Root delay : 32bit 

 *| Root Dispersion |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 
 *Root Dispersion : 32bit 

 *| Reference Identifier | 
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 
 *Reference Identifier : 32bit

 *Four TimeStamps : 32byte
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 

 *| Reference Timestamp |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 
 *Reference Timestamp : 64bit

 *| Originate Timestamp |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- 
 *Originate Timestamp : 64bit

 *| Receive Timestamp |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
 *Receive Timestamp : 64bit

 *| Transmit Timestamp | 
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
 *Transmit Timestamp : 64bit 

 *| Authenticator (optional) (96) |
 *+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

*/
#define LI 0
#define VN 3
#define MODE 3
#define STRATUM 0
#define POLL 4 
#define PREC -6

//#define 	_SVID_SOURCE 					/*如果使用的是glib2，先定义这个宏，才能使用stime(tim_t *ptm)*/
#define 	FROM_00_TO_70	0x83aa7e80	/*3600s * 24h * (365days * 70years + 17days )*/
#define	NTP_PORT			123			/* npt port */

//时钟报警标志. 0: 不同步；1：同步，不报警; 2：同步，报警；3：不同步，故障报警。
#define	CLOCK_NO_SYCN				0
#define	CLOCK_SYCN_NO_ALARM		1
#define	CLOCK_SYCN_ALRAM			2
#define	CLOCK_NO_SYCN_FAULT_ALARM 3

#define NTPFRAC(x) (4294 * (x) + ((1981 * (x))>>11))
#define USEC(x) (((x) >> 12) - 759 * ((((x) >> 10) + 32768) >> 16))

struct ntptime 
{
    unsigned int coarse;
    unsigned int fine;
};

#endif /*SYNCCLOCKDEF_H_*/
