// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include"afxmt.h"

#include "Image\CxImage/ximage.h"
//#include "OpenCV2CXimage.h"

#define WIDTHBYTES(bits) ((DWORD)(((bits)+31) & (~31)) / 8)
#define BYTESPERLINE(width, bits) ((((width)*(bits) + 31)/32)*4)

#define GRAYVALUE(pBuffer, nWidth, nHeight, x, y)  pBuffer[(nHeight-1-y)*BYTESPERLINE(nWidth, 8) + x]
#define SETGRAYVALUE(pBuffer, nWidth, nHeight, x, y, nValue) (pBuffer[(nHeight-1-y)*BYTESPERLINE(nWidth, 8) + x] = nValue)

#define  ZOOM_IMAGEIGNORE(newX, newY, newImg, srcX, srcY, srcImg) newImg->SetPixelColor(newX,newImg->GetHeight()-1-newY, srcImg->GetPixelColor(srcX, srcImg->GetHeight() - 1- srcY))

#define  GETGRAYVALUE1(img, x, y)  img->info.pImage[min(max((img->GetHeight()-1-y)*BYTESPERLINE(img->GetWidth(), 8) + x, 0), (img->GetHeight()-1)*BYTESPERLINE(img->GetWidth(), 8) + img->GetWidth()-1)]
#define  GETGRAYVALUE2(img, x, y)  img.info.pImage[min(max((img.GetHeight()-1-y)*BYTESPERLINE(img.GetWidth(), 8) + x, 0), (img.GetHeight()-1)*BYTESPERLINE(img.GetWidth(), 8) + img.GetWidth()-1)]

#define  ZOOM_IMAGENEW(newIndex, newBuffer, srcIndex, srcBuffer) newBuffer[newIndex] = srcBuffer[srcIndex]

//
//#define BYTESPERLINE(width, bits) ((((width)*(bits) + 31)/32)*4)
//#define GRAYVALUE(pBuffer, nWidth, nHeight, x, y)  pBuffer[(nHeight-1-y)*BYTESPERLINE(nWidth, 8) + x]
//#define SETGRAYVALUE(pBuffer, nWidth, nHeight, x, y, nValue) (pBuffer[(nHeight-1-y)*BYTESPERLINE(nWidth, 8) + x] = nValue)
#define  nEPS 8 //������ط�Χ

#define MAX_CHARS    120  
#include <math.h>


