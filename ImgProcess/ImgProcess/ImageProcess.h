<<<<<<< HEAD
#pragma once 
#pragma pack(1)

#include "stdafx.h"
#include "xml/Markup.h"
#include "include/zyj-dllexport.h"
#include <vector> 
#include "Image/CxImage/ximage.h"
using namespace std;
//#include "include/kadmos.h"

struct OMRRECT{
	CRect rect;
	int nCount;
	OMRRECT()
	{
		nCount = 0;
		rect.SetRect(0,0,0,0);
	}
};

//#include "../../../../code/bin/"
class CImageProcess
{
public:
	CImageProcess(void);

public: 
	~CImageProcess(void);
	CString GetCurrentFolderPath();            //��ȡ��ǰ���������ļ���·��
	BOOL IsPointInRect(CPoint p1, CRect rect); //�ж�ĳ���Ƿ�����Ӧ�ľ�������
	CPoint GetMidPoint(CPoint p1, CPoint p2);  //��ȡ����֮���е�
	double GetTrangleAreaPoints(CPoint p1, CPoint p2, CPoint p3); //��ȡ�����ε����
	double GetAnglePoints(CPoint pCross, CPoint p1, CPoint p2);
	static double GetLength(CPoint p1, CPoint p2);
	CRect NewRect2Rect(NEWRECT newRect);
	void GetBlackCount(const CxImage *img, CRect rectArea,int nThreshold,int &nCount); //��ȡͼ���кڵ�ĸ���   pany 2016.03.18
	void GetRatio(NEWPOINT pLocal[3], NEWPOINT pCenter, double &dHRatio, double &dVRatio); //��ȡĳ���ض�λ�����������ϵı���
	void GetNewPoint(NEWPOINT pCurLocal[3], double dHRatio, double dVRatio, NEWPOINT &pCenter);
	
	//��ȡ���������ͱ߿�
	bool GetValidRect(int nType, const CxImage *img, vector<CRect> &v_allRects, int nThreshold, CSize dstSiz); //��ȡ��Ч��������δ��Ϳ����
	bool GetAllPoint(CxImage *img, vector<CPoint> &v_allPoints, CPoint pStart, int nThreshold, int &nCount); //��ȡĳ����ΧnStep��С�������ٽ���
	bool GetRect(vector<CPoint> v_allPoints, CRect &dstRect); //���ݾۼ����ȡ����
	//bool loadSrcImg(CString strPath, DWORD DwType, int nThreshold);

	//��ȡ��վ������ͱ߿� 2015.12.22
	bool  GetEnclosedRects(int nType, CxImage *img, vector<CRect> &v_allRects, int nThreshold, CSize dstSize); //��ȡ��յľ��� 

	//��ȡ��д����α߿�  2016.07.28
	bool GetIcrRects(CxImage srcImg, CSize dstSize, int nThreshold, vector<CRect> &v_allRects);

	//��ȡ����ֱ��
	BOOL GetHLine(CPoint pExtream[2], CPoint pStart, CRect rectArea, CSize dstSize,const CxImage *img, int nThreshold, int nMaxGapLen);
	//��ȡ����ֱ��
	BOOL GetHLine_OMR(CPoint pExtream[2], CPoint pStart, CRect rectArea, CSize dstSize,const CxImage *img, int nThreshold, int nMaxGapLen);
	BOOL GetRectFromPoint(CRect &dstRect, CPoint pStart, CRect rectArea, CSize dstsize,const CxImage *img, int nThreshold);
 
   //ͬ��ͷ���ʶ��
   BOOL GetRectFromTwoRects(CRect &dstRect, CRect rect[2], CRect rectArea, CSize dstSize, CxImage *img, int nThreshold);
   void GetAllRectsFromRects(vector<CRect>&v_dstRects, CRect rect[2], CRect rectArea, CSize dstSize, CxImage *img, int nThreshold);

   //��ȡ�����ζ�λ��
   BOOL GetTriAngleLocalPoint(CxImage *img, const CSize dstSize, const int nThreshold, NEWTRIANGLE &dstTriangle);	
	
   //��ȡ
   BOOL GetPointsCenter(vector<CPoint> v_allPoints, CPoint &pCenter);

   //ʶ��������� 2016.01.22
   //��ȡʶ����
   //CString GetOcrResult(CxImage *img);
   
   //��ȡ������ھ����������
   bool GetTitleRect(CxImage *img, vector<TITLENO> v_modelTitleNo, int nThrshold, vector<TITLENO> &v_dstTitleNo);
	
   BOOL GetHLine1(CPoint pExtream[2],CPoint pStart, CRect rectArea, const CxImage *img,CSize minSize, CSize maxSize, const int nThreshold);
   BOOL GetRectFromPoint1(CRect &dstRect, CPoint pStart, CRect rectArea,const CxImage *img, CSize minSize, CSize maxSize, int nIndex, const int nThreshold,  const CxImage* pSrcImg);
   BOOL GetRectFromRect1(CRect &dstRect,
	   CRect rectArea,  
	   const CxImage *img,
	   CSize minSize,
	   CSize maxSize,
	   int nIndex,
	   const CxImage *pSrcImg,
	   const int nThreshold);

   //��ȡ���ζ�λ�����
   bool GetRectPoint(CRect &dstRect, 
					 const CxImage *srcImg,
					 const int nIndex, 
					 const CRect rectArea,
					 const CxImage *cropImg,
					 const int nThrshold,
					 const CSize minSize,
					 const CSize maxSize);

   double GetDensity(const CxImage *img,  CRect rect, const int nThreshold); 
   double GetHollowDensity( CxImage *cropImg, const int nThreshold, const CSize centerSize);

   //��ȡ��ǰdll�����ļ�·��
   CString GetMoudulePath(); //2016.06.14
   int GetCrossPointsCount(CRect rect1, CRect rect2);//�����ཻ�������
   bool GetVLinelen( CxImage srcImg, int nThreshold, int &nLen1);
   void GetThinImage(CxImage *cropImg, int nThreshold, int nTimes );

   void GetChainContour_Encolsed(CxImage srcImg,  int nThreshold, CSize dstSize, vector<CRect> &v_AllRects);
   void GetCharContour(CxImage srcImg,  int nThreshold, CRect &dstRect); // ��ȡ����������Ӿ���
   void GetChainContour(CxImage srcImg,  int nThreshold, CSize dstSize, vector<OMRRECT> &v_AllRects); //��ȡ���б߿���Ӿ��� 2016.06.21
   bool Cximage2Iplimage_1(CxImage *src, IplImage **dst);

   //��ȡ��Ϳ���������߶� pany 2016.06.22
   int GetMaxFillHeight(CxImage cropImg, int nThreshold, CSize dstSize);

   //��ȡ���ο�  2016.06.28
   bool GetIcrRect(CxImage srcImg, CSize dstSize, int nThreshold, CString &strRes);
   bool GetMinRect(CxImage srcImg, CSize minSize, int nThreshold, vector<CRect> &v_allRects);

   //��ȡ�׵�����λ�� 2016.07.28
   bool GetWhiteRect(CxImage srcImg, int nThreshold, CRect rect1, CRect &dstRect);

   bool IsAroundBlack(CxImage srcImg, int nThreshold, CPoint p1);
   bool GetValidExternalCharRect(CxImage srcImg, int nThreshold, CRect &dstRect); //��ȡ�ַ����ڵ���Ч��Ӿ��� 2016.08.05 pany
   bool GetExpandImg(CxImage srcImg, int nNewWidth, int nNewHeight, CxImage &dstImg);
private:
	CSize m_dstBlackSize;
	
	//��д��� 2016.06.14 
	//RelData m_rel;
	//bool  m_bInitIrc;
};
=======
#pragma once 
#pragma pack(1)

#include "stdafx.h"
#include "xml/Markup.h"
#include "include/zyj-dllexport.h"
#include <vector> 
#include "Image/CxImage/ximage.h"
using namespace std;
//#include "include/kadmos.h"

struct OMRRECT{
	CRect rect;
	int nCount;
	OMRRECT()
	{
		nCount = 0;
		rect.SetRect(0,0,0,0);
	}
};

//#include "../../../../code/bin/"
class CImageProcess
{
public:
	CImageProcess(void);

public: 
	~CImageProcess(void);
	CString GetCurrentFolderPath();            //��ȡ��ǰ���������ļ���·��
	BOOL IsPointInRect(CPoint p1, CRect rect); //�ж�ĳ���Ƿ�����Ӧ�ľ�������
	CPoint GetMidPoint(CPoint p1, CPoint p2);  //��ȡ����֮���е�
	double GetTrangleAreaPoints(CPoint p1, CPoint p2, CPoint p3); //��ȡ�����ε����
	double GetAnglePoints(CPoint pCross, CPoint p1, CPoint p2);
	static double GetLength(CPoint p1, CPoint p2);
	CRect NewRect2Rect(NEWRECT newRect);
	void GetBlackCount(const CxImage *img, CRect rectArea,int nThreshold,int &nCount); //��ȡͼ���кڵ�ĸ���   pany 2016.03.18
	void GetRatio(NEWPOINT pLocal[3], NEWPOINT pCenter, double &dHRatio, double &dVRatio); //��ȡĳ���ض�λ�����������ϵı���
	void GetNewPoint(NEWPOINT pCurLocal[3], double dHRatio, double dVRatio, NEWPOINT &pCenter);
	
	//��ȡ���������ͱ߿�
	bool GetValidRect(int nType, const CxImage *img, vector<CRect> &v_allRects, int nThreshold, CSize dstSiz); //��ȡ��Ч��������δ��Ϳ����
	bool GetAllPoint(CxImage *img, vector<CPoint> &v_allPoints, CPoint pStart, int nThreshold, int &nCount); //��ȡĳ����ΧnStep��С�������ٽ���
	bool GetRect(vector<CPoint> v_allPoints, CRect &dstRect); //���ݾۼ����ȡ����
	//bool loadSrcImg(CString strPath, DWORD DwType, int nThreshold);

	//��ȡ��վ������ͱ߿� 2015.12.22
	bool  GetEnclosedRects(int nType, CxImage *img, vector<CRect> &v_allRects, int nThreshold, CSize dstSize); //��ȡ��յľ��� 

	//��ȡ��д����α߿�  2016.07.28
	bool GetIcrRects(CxImage srcImg, CSize dstSize, int nThreshold, vector<CRect> &v_allRects);

	//��ȡ����ֱ��
	BOOL GetHLine(CPoint pExtream[2], CPoint pStart, CRect rectArea, CSize dstSize,const CxImage *img, int nThreshold, int nMaxGapLen);
	//��ȡ����ֱ��
	BOOL GetHLine_OMR(CPoint pExtream[2], CPoint pStart, CRect rectArea, CSize dstSize,const CxImage *img, int nThreshold, int nMaxGapLen);
	BOOL GetRectFromPoint(CRect &dstRect, CPoint pStart, CRect rectArea, CSize dstsize,const CxImage *img, int nThreshold);
 
   //ͬ��ͷ���ʶ��
   BOOL GetRectFromTwoRects(CRect &dstRect, CRect rect[2], CRect rectArea, CSize dstSize, CxImage *img, int nThreshold);
   void GetAllRectsFromRects(vector<CRect>&v_dstRects, CRect rect[2], CRect rectArea, CSize dstSize, CxImage *img, int nThreshold);

   //��ȡ�����ζ�λ��
   BOOL GetTriAngleLocalPoint(CxImage *img, const CSize dstSize, const int nThreshold, NEWTRIANGLE &dstTriangle);	
	
   //��ȡ
   BOOL GetPointsCenter(vector<CPoint> v_allPoints, CPoint &pCenter);

   //ʶ��������� 2016.01.22
   //��ȡʶ����
   //CString GetOcrResult(CxImage *img);
   
   //��ȡ������ھ����������
   bool GetTitleRect(CxImage *img, vector<TITLENO> v_modelTitleNo, int nThrshold, vector<TITLENO> &v_dstTitleNo);
	
   BOOL GetHLine1(CPoint pExtream[2],CPoint pStart, CRect rectArea, const CxImage *img,CSize minSize, CSize maxSize, const int nThreshold);
   BOOL GetRectFromPoint1(CRect &dstRect, CPoint pStart, CRect rectArea,const CxImage *img, CSize minSize, CSize maxSize, int nIndex, const int nThreshold,  const CxImage* pSrcImg);
   BOOL GetRectFromRect1(CRect &dstRect,
	   CRect rectArea,  
	   const CxImage *img,
	   CSize minSize,
	   CSize maxSize,
	   int nIndex,
	   const CxImage *pSrcImg,
	   const int nThreshold);

   //��ȡ���ζ�λ�����
   bool GetRectPoint(CRect &dstRect, 
					 const CxImage *srcImg,
					 const int nIndex, 
					 const CRect rectArea,
					 const CxImage *cropImg,
					 const int nThrshold,
					 const CSize minSize,
					 const CSize maxSize);

   double GetDensity(const CxImage *img,  CRect rect, const int nThreshold); 
   double GetHollowDensity( CxImage *cropImg, const int nThreshold, const CSize centerSize);

   //��ȡ��ǰdll�����ļ�·��
   CString GetMoudulePath(); //2016.06.14
   int GetCrossPointsCount(CRect rect1, CRect rect2);//�����ཻ�������
   bool GetVLinelen( CxImage srcImg, int nThreshold, int &nLen1);
   void GetThinImage(CxImage *cropImg, int nThreshold, int nTimes );

   void GetChainContour_Encolsed(CxImage srcImg,  int nThreshold, CSize dstSize, vector<CRect> &v_AllRects);
   void GetCharContour(CxImage srcImg,  int nThreshold, CRect &dstRect); // ��ȡ����������Ӿ���
   void GetChainContour(CxImage srcImg,  int nThreshold, CSize dstSize, vector<OMRRECT> &v_AllRects); //��ȡ���б߿���Ӿ��� 2016.06.21
   bool Cximage2Iplimage_1(CxImage *src, IplImage **dst);

   //��ȡ��Ϳ���������߶� pany 2016.06.22
   int GetMaxFillHeight(CxImage cropImg, int nThreshold, CSize dstSize);

   //��ȡ���ο�  2016.06.28
   bool GetIcrRect(CxImage srcImg, CSize dstSize, int nThreshold, CString &strRes);
   bool GetMinRect(CxImage srcImg, CSize minSize, int nThreshold, vector<CRect> &v_allRects);

   //��ȡ�׵�����λ�� 2016.07.28
   bool GetWhiteRect(CxImage srcImg, int nThreshold, CRect rect1, CRect &dstRect);

   bool IsAroundBlack(CxImage srcImg, int nThreshold, CPoint p1);
   bool GetValidExternalCharRect(CxImage srcImg, int nThreshold, CRect &dstRect); //��ȡ�ַ����ڵ���Ч��Ӿ��� 2016.08.05 pany
   bool GetExpandImg(CxImage srcImg, int nNewWidth, int nNewHeight, CxImage &dstImg);
private:
	CSize m_dstBlackSize;
	
	//��д��� 2016.06.14 
	//RelData m_rel;
	//bool  m_bInitIrc;
};
>>>>>>> c3ec4193a47e985f94758967b6bacfb8a4ab020b
