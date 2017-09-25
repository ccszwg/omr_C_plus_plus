#pragma once
#include  "include/zyj-dllexport.h"
#include <vector>
using namespace std;

struct LOCALPOINT_DATA
{
	char cCurImgPath[256];
	NEWRECT pLocalRects[3];

	LOCALPOINT_DATA()
	{
		memset(cCurImgPath, '\0', 256);
	}
};

class CurImage
{
public:
	CurImage(void);
	~CurImage(void);
	
	int m_nThreshold; //��ֵ 
	vector<NEWRECT> m_rectLocal; //��λ��
	//int m_nLocalType; //��λ������ 1��������  2������

	vector<RECTARRAY> v_modelRectArrays; //ģ���п͹�������
	vector<NEWRECT>   v_rectModelLocal;    //ģ����������λ�����ھ���λ��
	vector<int>  v_OMRZuIDs; // ģ������ID��Ϣ
	vector<RECTARRAY> v_modelKhRectArray; //ģ���п������ھ���λ��
	vector<RECTARRAY> v_modelScoreRectArray; //ģ���з������ο�����λ��
	vector<RECTARRAY> v_modelTitleQRRectArray; //ģ���б����ά��
	vector<RECTARRAY> v_modelKhQRRectArray;   //ģ���п����������ھ���
	vector<RECTARRAY> v_modelPageRectArray;   //ģ����ҳ�����ھ���
	RECTARRAY  modelAbsentRectArray;          //ģ����ȱ�����ھ���

	int m_nAverGrayValue; 
	double m_dAverDensity;

	//�������ƥ���ȡ�͹�����λ�õ� 2016.12.15
	void GetCurImgRectArray(const CxImage srcImg, const vector<RECTARRAY> v_ModelRA, int nThreshold, vector<RECTARRAY> &v_dstRA);
	bool IsValidRect(CxImage srcImg, int nThreshold, CSize dstSize, NEWRECT rect1); //��ȡ��ǰ��Ч���� 2016.12.15

};
