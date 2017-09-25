// ImgProcess.h : ImgProcess DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "ImageProcess.h"
#include "CurImage.h"
struct OMR_ZUID
{
    int nPage;
    int nID;
    int nABFlag;
    OMR_ZUID()
    {
        nABFlag = -1;
    }
};




// CImgProcessApp
// �йش���ʵ�ֵ���Ϣ������� ImgProcess.cpp
//
class CImgProcessApp : public CWinApp
{
public:
    CImgProcessApp();
    // ��д
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
    DECLARE_MESSAGE_MAP()
};

//��ȡ��Ϳ�ܶ�
bool NP_GetDensity(IplImage* pSrcIn, CvRect cvRectIn, int iThres);
int NP_GetZhanKong(IplImage* pSrcIn, CvRect cvRectIn, int iThres, float& flzkOut);
int GetOption1(IplImage* pSrcIn, vector<CvRect> cvRectInVec,
    int Color, vector<int> uiPixVec,
    int uiType, std::wstring &csOptOutVec,
    int uiThread);

/*
����˵��: ��ȡĿ��ͼ���������
���ؽ��:  TRUE �ɹ�  FALSE��ʧ��
����˵��:
rectArea:   ĳһ����OMR��������
modelArray: ģ�嵱��OMR����������Ϣ
modelsize:  ģ���о��θ���
dstArry:    ���ȡĿ���������
*/
BOOL ZYJ_GetRectArray(int nOmrType, vector<RECTARRAY> &dstArray, int nRecType, int nZuID, CxImage *srcImg, CurImage *imgPara); //��ȡ�͹��������                                                                                                                     
BOOL ZYJ_IsUnFilling(RECTARRAY &srcRect, int nThreshold, CxImage *srcImg); //����˵��: �ж�ĳһ���������Ƿ���Ϳ,��Ҫ���δ��Ϳ
/*
����˵��:��ȡ���ζ�λ��
����˵��:
rectArea:         ͼ���Ͼ��ο�ѡ����
nModelRectWidth:  ģ���ж�λ����ο��
nModelRectHeight: ģ���ж�λ����θ߶�
dstRect         : ����Ŀ�궨λ�����
*/
bool ZYJ_GetRectLocalPoint(NEWRECT rectArea, int nModelRectWidth, int nModelRectHeight, int nIndex, int nRectType, NEWRECT &dstRect, CxImage *srcImg, CurImage *ImgPara); //
																																										  /*
																																										  ����˵��:��ȡ�͹���ʶ����
																																						  */
bool ZYJ_GetOmrResult(vector<RECTARRAY> &srcRects, int nSize, /*int nSelCheck, */vector<RECTARRAY> modelRectArry, int &nFillAverGray);

CRect &NewRect2Rect(NEWRECT newRect);
NEWRECT &Rect2NewRect(CRect rect);
bool GetRectArry(vector<RECTARRAY> &v_DstRectArray, vector<CRect> v_allRects, vector<RECTARRAY> v_modelRects);
bool GetRectArry_1(vector<RECTARRAY> &v_DstRectArray, vector<RECTARRAY> v_curRectArray, vector<RECTARRAY> v_modelRects, CxImage *srcImg, int nThreshold);

double GetGrayDensity(NEWRECT rectArea, int nThrshold, CxImage *srcImg, int &nAverValue);

bool MergeNewImage(CxImage img1, CxImage img2, CString strNewImg);
void sort(vector<RECTARRAY> &v_dstArrays);
bool GetModelRectArray(RECTARRAY rectArray, vector<RECTARRAY> modelRectArray, RECTARRAY &dstModelRArray);
NEWRECT GetRectArea(const RECTARRAY *v_modelrArray, CxImage *srcImg);
NEWRECT GetRectArea1(NEWRECT rect1, int nOmrSize, CxImage *srcImg);

DWORD GetFileType1(const CString strImgPath);
int GetBlackColor(CxImage cxImage);

bool GetCurImgInfo(CxImage *srcImg, const char * cFilePath, const int nPage, const int nOmrType, const int nThreshold, const int nRecType, int nABFlag, CurImage &curImgPara);

//�и����ת�� 2017.01.12
void GetCropRect(CRect rectModel, double dTransfer[6], CRect &dstRect);