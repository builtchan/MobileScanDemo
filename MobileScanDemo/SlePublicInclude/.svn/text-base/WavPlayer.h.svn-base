/*
 * 说明：仅支持未经压缩的WAV格式文件
 *       支持多线程并发调用
 * wugang 2013.05.22
 * */

#ifndef CWAVPLAYER_H_
#define CWAVPLAYER_H_

#define ALSA_PCM_NEW_HW_PARAMS_API

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <alsa/asoundlib.h>

#define WAV_NO_CMD	0
#define WAV_IMM_STOP	1
#define WAV_FIN_STOP	2
#define WAV_IMM_PLAY	3
#define WAV_FIN_PLAY	4


typedef struct _RIFF_HEADER 
{ 
	char szRiffID[4];  // 'R','I','F','F' 
	unsigned long dwRiffSize; 
	char szRiffFormat[4]; // 'W','A','V','E' 
}RIFF_HEADER;
 
 

typedef struct _WAVE_FORMAT 
 { 
	unsigned short wFormatTag; 
	unsigned short wChannels; 
	unsigned long dwSamplesPerSec; 
	unsigned long dwAvgBytesPerSec; 
	unsigned short wBlockAlign; 
	unsigned short wBitsPerSample; 
}WAVE_FORMAT; 

typedef struct _FMT_BLOCK 
{ 
	char  szFmtID[4]; // 'f','m','t',' ' 
	unsigned long  dwFmtSize; 
	WAVE_FORMAT wavFormat; 
}FMT_BLOCK; 
 
typedef struct _FACT_BLOCK 
 { 
  char  szFactID[4]; // 'f','a','c','t' 
  unsigned long  dwFactSize; 
 unsigned long  data; 
 }FACT_BLOCK; 
 
typedef struct _DATA_BLOCK 
 { 
  char szDataID[4]; // 'd','a','t','a' 
  unsigned long dwDataSize; 
 }DATA_BLOCK; 

typedef struct _PLAY_PARAM
{
	FILE * wavfp;
	long offset;
	WAVE_FORMAT format;
	unsigned long dataSize;
	int playTimes;
	int playDelay;
	int playFlag;
	bool newPlay;
}PLAY_PARAM;

class CWavPlayer
{
public:
	CWavPlayer();
	virtual ~CWavPlayer();
	
	//初始化，只调用1次
	bool Init();
	
	//退出释放资源，只调用1次
	bool Destroy();
	
	//播放WAV文件
	//wavFilePath: WAV文件路径
	//times:播放次数，0表示永远播放，直到再次调用play
	//delay:多次播放时的间隔时间，以100ms为单位
	//flag:0：立即中断当前的播放，开始新的播放；1：等待当前播放单元完成后，开始新的播放
	bool Play(const char * wavFilePath, int times=1, int delay=0, int flag=0);
	
	//停止当前的播放
	//flag:0：立即中断当前的播放；1：等待当前播放单元完成后
	bool Stop(int flag=0);
	
	static void * playThread(void *arg);
private:
	PLAY_PARAM param;
	PLAY_PARAM paramBak;
	bool inited;
	bool enqClose;
	pthread_mutex_t mutex;
	sem_t sem;
	pthread_t thread;

private:
	snd_pcm_t * pcmHandle;
	snd_pcm_hw_params_t * pcmParams;
	snd_pcm_uframes_t pcmFrames;
	unsigned int playSize;	//播放用的参数
	char * playBuffer;	//WAV数据缓存

	int getCmdType();
	bool preparePlay();
	void stopCurrentPlay();
	bool playFrames();
	bool continuePlay(int curTimes);
};

#endif /*CWAVPLAYER_H_*/
