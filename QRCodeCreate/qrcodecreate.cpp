/*
 * qrcodecreate.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: root
 */
#include "qrcodecreate.h"

bool GenerateQRCode(const char* pData,char*pFilePath,char*pFileName,char *pFaultInfo)
{
	char szInfo[1000]={0};
	char szPath[256]={0};

	if(NULL == pFaultInfo)
		return false;

	if(NULL == pFilePath || NULL == pFileName)
	{
		strcpy(pFaultInfo,"NULL == pFilePath || NULL == pFileName");
		return false;
	}
	sprintf(szPath,"%s/%s",pFilePath,pFileName);
	if(NULL != pData)
		sprintf(szInfo, "%s\n",pData);

//	if(strlen(szInfo) >= 400) return false;
//	if(strlen(szInfo) == 0) return false;

	unsigned int	unWidth, x, y, l, n, unWidthAdjusted, unDataBytes;
	unsigned char*	pRGBData, *pSourceData, *pDestData;
	QRcode*			pQRC;
	FILE*			f;
	pQRC = QRcode_encodeString(szInfo, 0, QR_ECLEVEL_H, QR_MODE_8, 1);
	if(NULL == pQRC)
	{
		strcpy(pFaultInfo,"NULL == pQRC");
		return false;
	}

	unWidth = pQRC->width;
	unWidthAdjusted = unWidth * OUT_FILE_PIXEL_PRESCALER * 3;
	if (unWidthAdjusted % 4)	unWidthAdjusted = (unWidthAdjusted / 4 + 1) * 4;
	unDataBytes = unWidthAdjusted * unWidth * OUT_FILE_PIXEL_PRESCALER;

	// Allocate pixels buffer
	if (!(pRGBData = (unsigned char*)malloc(unDataBytes)))
	{
		QRcode_free(pQRC);
		strcpy(pFaultInfo,"malloc failed");
		return false;
	}

	// Preset to white
	memset(pRGBData, 0xff, unDataBytes);

	// Prepare bmp headers
	BITMAPFILEHEADER kFileHeader;
	kFileHeader.bfType = 0x4d42;  // "BM"
	kFileHeader.bfSize =	sizeof(BITMAPFILEHEADER) +
							sizeof(BITMAPINFOHEADER) +
							unDataBytes;
	kFileHeader.bfReserved1 = 0;
	kFileHeader.bfReserved2 = 0;
	kFileHeader.bfOffBits =	sizeof(BITMAPFILEHEADER) +
							sizeof(BITMAPINFOHEADER);

	BITMAPINFOHEADER kInfoHeader;
	kInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	kInfoHeader.biWidth = unWidth * OUT_FILE_PIXEL_PRESCALER;
	kInfoHeader.biHeight = -((int)unWidth * OUT_FILE_PIXEL_PRESCALER);
	kInfoHeader.biPlanes = 1;
	kInfoHeader.biBitCount = 24;
	kInfoHeader.biCompression = BI_RGB;
	kInfoHeader.biSizeImage = 0;
	kInfoHeader.biXPelsPerMeter = 0;
	kInfoHeader.biYPelsPerMeter = 0;
	kInfoHeader.biClrUsed = 0;
	kInfoHeader.biClrImportant = 0;


	// Convert QrCode bits to bmp pixels
	pSourceData = pQRC->data;
	for(y = 0; y < unWidth; y++)
	{
		pDestData = pRGBData + unWidthAdjusted * y * OUT_FILE_PIXEL_PRESCALER;
		for(x = 0; x < unWidth; x++)
		{
			if (*pSourceData & 1)
			{
				for(l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
				{
					for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
					{
						*(pDestData +		n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_B;
						*(pDestData + 1 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_G;
						*(pDestData + 2 +	n * 3 + unWidthAdjusted * l) =	PIXEL_COLOR_R;
					}
				}
			}
			pDestData += 3 * OUT_FILE_PIXEL_PRESCALER;
			pSourceData++;
		}
	}


	// Output the bmp file
	f = fopen(szPath, "wb");
	if(NULL != f)
	{
		fwrite(&kFileHeader, sizeof(BITMAPFILEHEADER), 1, f);
		fwrite(&kInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
		fwrite(pRGBData, sizeof(unsigned char), unDataBytes, f);

		fclose(f);
	}

	// Free data
	free(pRGBData);
	QRcode_free(pQRC);
	return true;
}
