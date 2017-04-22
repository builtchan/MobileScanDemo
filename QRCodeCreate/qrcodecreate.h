/*
 * qrcodecreate.h
 *
 *  Created on: Apr 22, 2017
 *      Author: root
 */

#ifndef QRCODECREATE_H_
#define QRCODECREATE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

#define WORD unsigned short int
#define DWORD unsigned int
#define OUT_FILE_PIXEL_PRESCALER	3											// Prescaler (number of pixels in bmp file for each QRCode pixel, on each dimension)
#define PIXEL_COLOR_R				0											// Color of bmp pixels
#define PIXEL_COLOR_G				0
#define PIXEL_COLOR_B				0
#define BI_RGB			0L

#pragma pack(push, 2)

typedef struct
{
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
	DWORD      biSize;
	DWORD       biWidth;
	DWORD       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	DWORD       biXPelsPerMeter;
	DWORD       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

bool GenerateQRCode(const char* pData,char*pFilePath,char*pFileName,char *pFaultInfo);



#endif /* QRCODECREATE_H_ */
