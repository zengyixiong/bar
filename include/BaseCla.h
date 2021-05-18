#pragma once

//�������
#ifndef         _XCLASSSET_H_
#define         _XCLASSSET_H_
/****************************************************
�ļ�����XClassSet.h
���������� �����༯��

��д�ˣ���׿��
��д���ڣ�2014/01/20

***************************************************/
#ifdef BASECLASS_SET
#else
#define BASECLASS_SET _declspec(dllexport)
#endif
//#define _AFXDLL

//#include "PhoBasClass.h"

#include <vector>
using namespace std;

#include "HongDingYi.h"

#define byte unsigned char

class  Xxyz;
class  XVector;
class  XLine;
class  FaxPlane;
class  XCircle;
class  XSphere;
class  XParaboloid;
class  XPostion;

//#define _LINUX_BMP_HEADER_DEF_H_

#ifdef _LINUX_BMP_HEADER_DEF_H_

#define BI_RGB        0L

typedef struct tagBITMAPINFOHEADER {
	DWORD      biSize;
	LONG       biWidth;
	LONG       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	LONG       biXPelsPerMeter;
	LONG       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
} BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
	BYTE    rgbBlue;
	BYTE    rgbGreen;
	BYTE    rgbRed;
	BYTE    rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPFILEHEADER {
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
} BITMAPFILEHEADER, FAR *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFO {
	BITMAPINFOHEADER    bmiHeader;
	RGBQUAD             bmiColors[1];
} BITMAPINFO, FAR *LPBITMAPINFO, *PBITMAPINFO;

#endif

BASECLASS_SET void BaseClaDllInitial();
class BASECLASS_SET CXClassSet
{
public:
	CXClassSet(void);
	~CXClassSet(void);
};

//��άƽ���ϵ���Բ��
class BASECLASS_SET CObEllipse
{
public:
	CObEllipse();
	CObEllipse(const CObEllipse& ellipse);
	~CObEllipse();
	CObEllipse& CObEllipse::operator=(const CObEllipse& ellipse);

	double m_dX;                          //��Բ�����ĵ�����(x��ʾ�����꣬y��ʾ�߶ȷ����ϵ�����)��ϵ�Բ������
	double m_dY;

	double m_dx;                          //�Ҷ����ļ���õ���Բ������
	double m_dy;

	byte m_byUseStates;                              //�������״̬��0��ʹ�ã�1ʹ�ã�3����
	bool m_bTheOtherOb;                         //�Ƿ���Բ����ͼ�Σ��Ȳ���Ԫ��Ҳ������Բ
	bool m_bIsCircle;                           //���Ƿ��Ǹ�Բ��false = ��Բ, true = Բ
	double m_dEllipseRatio[5];                   //ax2+bxy+cy2+dx+ey+1 = 0;  һ��Ϊ�����ϵ�ϵ��
	double m_dTouYingRMS;                       //������ϵĵ㣬����Բ�ϵ�ͶӰ���ƽ��ֵ�����ֵԽ��˵��Խ����Ԫ

	double m_da2;                               //��Բ�ĳ���
	double m_db2;                               //��Բ�Ķ���

	double m_de;                               //��Բ��������
	double m_dth;                               //��Բ����ת��

	double m_dRms;                              //Ԫ�Ķ�λ����
};

class BASECLASS_SET CXPoint
{
public:
	CXPoint();
	CXPoint(const CXPoint& point);
	~CXPoint();
	CXPoint& CXPoint::operator=(const CXPoint& point);

	char m_cName[260];
	int x;
	int y;

	int m_nx;
	int m_ny;
	double m_dx;
	double m_dy;

	byte m_byUseStates;                       //���ʹ��״̬��1����ʹ�ã�2�����õģ�3������ĵ�

	double m_dDistance;           //�㵽ֱ�ߵľ���
};

//�պ�����ı�Ե��ļ���
class BASECLASS_SET EdgePointSet
{
public:
	EdgePointSet();
	~EdgePointSet();
	EdgePointSet(const EdgePointSet& pointLink);
	EdgePointSet& EdgePointSet::operator=(const EdgePointSet& pointLink);
	//   void SetPointLinkList(const CXPoint & xp);
	//void ClearPointLinkList(void);
	//���α���ʹ��
	std::vector<CXPoint> *m_PointLinkList;             //һ���պϱ�Ե����ɵ�㼯
	CObEllipse m_ObEllipse;                     //�㼯����Ӧ����Բ

	char m_cCodeName[260];            //��Ӧ�ı�������
	int m_nCodeNum;                             //��Ӧ��ֵ�����Ǽ���

	//ɨ�����ʹ��
	bool m_bLaserLine;                          //�Ƿ�Ϊ�����������������ϵĵ�������һ����ֵʱ����Ϊ�棩
	bool m_bFaxLine;                            //�Ƿ�Ϊ�̶�λ�õļ�����
	double m_dSlope;                            //�̶������ߵ�б��
	double m_dDistance;                         //ԭ�㵽�̶������ߵľ���
};

class BASECLASS_SET CBitmapPic
{
public:
	CBitmapPic();
	CBitmapPic(unsigned char *pBmpBuf, int w, int h, unsigned short biBitCount = 8);
	~CBitmapPic();

	void SavePicData(char filepath[], unsigned char *pBmpBuf, int w, int h, int nBitsWidth);
	void SavePicData(char filepath[], unsigned char *pBmpBuf, int w, int h);
	void SavePicData(char filepath[]);
	bool ReadPicture(char path[]);
	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬
	//����ڱ���head��
	BITMAPINFOHEADER head;
	BITMAPFILEHEADER bmpFileHead;    //�����ļ�ͷ����
	int	m_nWidth;                    //��
	int	m_nHeight;                   //��
	int	m_biBitCount;                //λ��
	RGBQUAD  *m_pColorTable;         //��ɫ��
	BITMAPINFO *m_lpbmi;            //
	bool m_bAdded;                   //��ӹ�ͼ����

	int m_nBitsWidth;                // ͼ����ÿ�е��ֽ���
	unsigned char* m_pucS;			// ָ��ԭͼ�����ص�ָ��
};
class BASECLASS_SET LaserLinePara
{
public:
	LaserLinePara();
	~LaserLinePara();
	LaserLinePara& LaserLinePara::operator=(const LaserLinePara& para);

	byte m_byMinHuiDuZhi;                              //�����ߵ���С�Ҷ�ֵ(Ĭ��ֵ10)�������ߵĻҶ�һ��������������������һ���Ǽ����ߵ���С����ֵ
	byte m_byMinNumPointLine;                          //һ������������Ҫ�������ٸ���(Ĭ��ֵ15)�����С�������������������Ͳ��Ǽ���������һ���֣��������ŵ���˵���
	byte m_byMaxLineRat;                               //�����뾶�����ֵ���������Ŀ�Ȱ뾶��ֵ��Ĭ��Ϊһ����30���ܿ��60���أ�
	byte m_byMaxRange;                                 //�̶���������ı䶯��Χ(Ĭ��ֵ5������)�������ж�����ͼ���ϵļ�����ǹ̶��ġ�
	byte m_byCenterToLineRange;                        //ͼ�����ĵ�����ֱ�ߵ������������ж�����ͼ���ϵļ�����ǹ̶��ġ�(Ĭ��ֵ10������)
	double m_dMaxRangePoiToPlane;                      //��ά�������ֵ��Ĭ��1.0mm�������������ά�㣬��������ƽ��ľ���������ֵʱ����ȥ��
	byte m_byNiHeDianShu;                              //����ȡ������������ʱ����Ҫ�ø����ĵ����ֱ����ϣ������ֱ�ߵķ��߷���.�����������ȷ��ʹ�ø������������(Ĭ��ֵ9������)
	float m_fXieLvJiaoDuYuZhi;                         //����������б����ֵ����������ж���ȡ���ļ��������Ƿ�Ϊ�̶����⡣
	float m_fFaxLaserJiaoDu;                           //�ڶ����������Ĺ̶�����������б�ʣ�ע��Ŷ���ǽǶȣ���Ĭ��ֵΪ�㡣
	byte m_byBianJieRangeThreshold;                    //����ͼ��߽���ٸ����صĵ㣬�Ͳ���ʹ���ˣ�Ĭ��15����

protected:
private:
};

//code�Ľ��������
class BASECLASS_SET XCodePara
{
public:
	XCodePara();
	XCodePara(const XCodePara& para);
	~XCodePara();
	XCodePara& XCodePara::operator=(const XCodePara& para);

public:
	int m_nRadius;                          //����ߴ� ��λ����
	int m_nCodeAngle;                       //b�������������Ϊ��������
	int m_nCodeBite;                        //����λ��
	double m_dSearchRadiusRate;             //�����뾶���ʣ������뾶 = ������Բ��뾶����Ĭ��3.35����1��1.7��1.3�뾶����ࡢ����
	double m_dRaToOutCilcle;                //Բ�ĵ����뻷�ڱڵľ��루Բ�İ뾶�Ӽ��Բ���Ŀ�ȣ�1+1.7
	double m_dTotalLong;                    //Բ�ĵ��⾶���ܳ�(�뾶 + ��� + ����)
	double m_dProjectThreshold;             //ͶӰ������ֵ�������ж������ͼ����Բ������Բ����λ�����أ�Ĭ��Ϊһ��
	int m_nMinPiex;                         //Բ�ε���С�����������
	int m_nMaxPiex;
	int m_nEllipseCorreatThreshold;         //��ֵ���Ա�����������ص��Ƿ������Բ����(�Ƿ������Բ������Ĭ����ֵ0.5������)
	int m_nAngleErrorThreshold;             //����Ƕȵ������ֵ  (Ĭ��Ϊ0.2����m_nCodeAngle)
	double m_dEccentricityThreshold;        //�����ʵ���ֵ��Ĭ��0.9����λ���أ���
	unsigned char m_RadiusExpand;                    //�뾶���ų��ȣ�����Ӵ�뾶���ȣ�

	//��ֵ��ר�õĿ��Ʊ���

public:
	//��������
	bool m_bIsBackgroundHighlight;           //����ɫ�Ƿ��ͻ����������
	bool m_bIsOutDoorUse;                    //�Ƿ�������Ӧ��
	bool m_bCorreatblur;                     // �Ƿ����ģ��

protected:
private:
};

/***********************************************
�ļ�����BaseCla.h

�ļ�˵����Code����ȡ�Ĳ����࣬����������ȡ����ֵ

�༭����׿��
���ڣ�2014/04/14
************************************************/
class BASECLASS_SET CPara1
{
public:
	CPara1(void);
	CPara1(const CPara1& Para);
	~CPara1(void);
	CPara1& CPara1::operator=(const CPara1& Para);
	void ToDefault(void);
	// ���ɨ�����
	int			m_nMaxScanRadius_T_Scan;	// ��־����������뾶
	int			m_nMaxScanRadius_R_Scan;	// Ring��������뾶
	int			m_nStep_Scan;				// ɨ�貽��
	int			m_nDelta_Scan;		 		// ��Ե��ֵ
	double		m_dBias_Scan;				// ƫ��
	double		m_dGain_Scan;				// ����
	int			m_nMeanGrayMin_T_Scan;	    // ��־�������ֵ���ҶȾ�ֵ��Сֵ
	int			m_nNumPixelMax_T_Scan;		// ���������
	int			m_nNumPixelMin_T_Scan;		// ��С������
	int			m_nNumPixelxMax_T_Scan;		// x�������������
	int			m_nNumPixelxMin_T_Scan;		// x������С������
	int			m_nNumPixelyMax_T_Scan;		// y�������������
	int			m_nNumPixelyMin_T_Scan;		// y������С������
	double		m_dAspect_T_Scan;			// ��������������ֵ��Сֵ(y/x��x/y)
	int			m_nMeanGrayMin_R_Scan;	    // Ring������ֵ���ҶȾ�ֵ��Сֵ
	int			m_nNumPixelMax_R_Scan;		// ���������
	int			m_nNumPixelMin_R_Scan;		// ��С������
	int			m_nNumPixelxMax_R_Scan;		// x�������������
	int			m_nNumPixelxMin_R_Scan;		// x������С������
	int			m_nNumPixelyMax_R_Scan;		// x�������������
	int			m_nNumPixelyMin_R_Scan;		// x������С������
	double		m_dAspect_R_Scan;			// ��������������ֵ��Сֵ(y/x��x/y)

	// AutoBar�������
	double m_dDisFactor_AutoBar;			// ��������
	double m_dDisFactor_Pt5_AutoBar;		// AutoBar5���������
	double m_dDisFactor_Pt2_4_AutoBar;		// ��2��4������7�ľ�������ֵ
	double m_dMaxCrossRatio_AutoBar;		// ������ֵ

	// �����־�������
	double m_dDisFactor_Code;			// ������ֵϵ��      //���������Ƚ�Զ��CODE�Ƚ�Сʱ���������Ӧ��Ӧ�����õıȽϴ�
	double m_dMaxRms_Code;				// ���Rms��ֵ
	double m_dCloseness_Code;			// ģ������任�������������������
	double m_dMaxCrossRatio_Code;		// ��������ֵ
};

/********************************************
ObjectPoint.h
���ݣ� �﷽����

��д�ˣ���׿��
���ڣ�2012/08/30
********************************************/

class BASECLASS_SET CObjectPoints
{
public:
	CObjectPoints(void);
	CObjectPoints(const CObjectPoints& point);
	CObjectPoints(const double dx, const double dy, const double dz);
	CObjectPoints(const double dxyz[3]);
	~CObjectPoints(void);
	CObjectPoints& CObjectPoints::operator =(const CObjectPoints& point);
	CObjectPoints& CObjectPoints::operator =(const Xxyz& point);
	bool Write3DData(vector<CObjectPoints> veOPt, char cpath[]);
public:
	int		m_nPt;				// ���
	char	m_sName[100];			// ����

	double	m_dX;				// X����
	double	m_dY;				// Y����
	double	m_dZ;				// Z����

	double	m_dStdX;			// StdX	������
	double	m_dStdY;			// StdY
	double	m_dStdZ;			// StdZ
	double	m_dStdXYZ;			// StdXYZ �ܾ���

	int		m_nNumStaUsed;		// ��Ӧ���������
	int		m_nNumSta;			// ��Ӧ��������������������ʹֲ����

	byte m_byPtCriteriaGrade;  //��ȼ����� 1 good��2 weak��3 bad Ĭ��Ϊ1
	char	m_sType;            // ������:��ͨ��(1)�����Ƶ�(2)�������־��(3)���������(4) .��������������ڶ�Ӧ�����ֱ�ʾ
	int		m_nUsedStatus;		// �Ƿ�������,-2��ʾƽ��ǰ�޳�,-1��ʾƽ���дֲ��޳�,1��ʾ����ʹ��

	int   m_shMaxShu;          //����¼������Ҳ�������һ�����ͬ����ĸ����������ֵ�������Ĳ��ֲ�ͳ�ƣ� Ĭ��500
	int   m_shRealShu;		   //����㱻������ͼ���ĵ�
	int   m_shPicIndex[1000];  //���������ͼ�������ֵ�����㿪ʼ��,�Լ�����������е�λ�ã����㿪ʼ����һ��ͼ���Ӧ��������
};

class BASECLASS_SET CObjectPointsVect
{
public:
	CObjectPointsVect(void);
	CObjectPointsVect(const CObjectPointsVect& point);
	~CObjectPointsVect(void);
	CObjectPointsVect&  operator =(const CObjectPointsVect& points);
	bool ReadDataFile(char* filepath);

public:
	char	m_sName[100];			// ����
	std::vector<CObjectPoints> *m_vectObjectPoints; //ͬ���㼯��
	std::vector<XLine> *m_veLines; //ͬ���㼯��
	std::vector<FaxPlane> *m_vePlanes; //ͬ���㼯��
	std::vector<XCircle> *m_veCircle; //ͬ���㼯��
	std::vector<XParaboloid> *m_veParaboloid; //ͬ���㼯��
	std::vector<XSphere> *m_veSphere; //ͬ���㼯��

	double m_dRMS;                  //���������
	double m_dXYZ;                  //�﷽�㾫��(��m_drmsX��m_drmsY��m_drmsZ���������ϳ�)

	double m_drmsX;                  //X�����﷽�������
	double m_drmsY;                  //Y�����﷽�������
	double m_drmsZ;                  //Z�����﷽�������

	double m_dmaxX;                  //X�����﷽����������
	double m_dmaxY;                  //Y�����﷽����������
	double m_dmaxZ;                  //Z�����﷽����������
};

/****************************************************
�ļ�����SamePoint.h
����������ͬ������࣬��¼һ��ͬ����

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/
class  BASECLASS_SET CSamePoint
{
public:
	CSamePoint(void);
	~CSamePoint(void);
	// �������캯��
	CSamePoint(const CSamePoint &other);
	// ����=�����
	CSamePoint&  operator =(const CSamePoint &other);
	//void SetViewCam(short vcam);
	//void ClearViewCam(void);

	char m_cPointName[100];		//��������

	//��ƬA�ϵ��������
	double m_dAX;
	double m_dAY;
	double m_dAZ;

	//��ƬB�ϵ��������
	double m_dBX;
	double m_dBY;
	double m_dBZ;

	//�����Ӳ�
	double m_HorizontalParallax; //�����Ӳ�
};

class  BASECLASS_SET CSamePointVect
{
public:
	CSamePointVect(void);
	~CSamePointVect(void);
	// �������캯��
	CSamePointVect(const CSamePointVect &other);
	//CSamePointVect(const vector<CSamePoint> &other);
	// ����=�����
	CSamePointVect&  operator =(const CSamePointVect &other);

	char m_cPicName[100];		//ͼ�������

	std::vector<CSamePoint>* m_vectSamePoint; //ͬ���㼯��m_vectSamePoint
};

/****************************************************
�ļ�����CCtrlDataSet.h
����������k���Ƶ㼯��

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/
class BASECLASS_SET CCtrlDataSet
{
public:
	CCtrlDataSet(void);
	~CCtrlDataSet(void);
	CCtrlDataSet(const CCtrlDataSet &other);

	// ����=�����
	CCtrlDataSet&  operator =(const CCtrlDataSet &other);

	CSamePoint   m_SPoint;  //����������Ҳ����������ϵ�����

	double       m_dXs;
	double       m_dYs;
	double       m_dZs;

	double       m_da; //������ת��
	double       m_dw;
	double       m_dk;

	double       m_dRoMatr[9];        //��ת���󳣹�����
	// a1,a2,a3
	// b1,b2,b3
	// c1,c2,c3
};

/****************************************************
�ļ�����CScaleBar.h
������������׼������

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/
class BASECLASS_SET  CScaleBar
{
public:
	CScaleBar(void);
	CScaleBar(const CScaleBar& bar);
	~CScaleBar(void);
	CScaleBar& operator =(const CScaleBar& bar);

	char m_cName[100];					//��׼������

	CObjectPoints m_BarPoints1;			//��ɻ�׼�������˵�ĵ�,����׼�����˵Ķ˵�����ֵ
	CObjectPoints m_BarPoints2;

	double m_dBarLength;				//��׼�ߵĳ���
};

/****************************************************
�ļ�����CCamera1.h
��������������ļ���

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/
class  BASECLASS_SET CCamera1
{
public:
	CCamera1();
	CCamera1(const CCamera1& Cam);
	virtual ~CCamera1();
	CCamera1& operator =(const CCamera1& Cam);
	bool initialCameral(char cpath[]);
public:
	char m_sName[100];					// �������--�ؼ��ֶ�
	char	m_sFileName[100];				// �궨�ļ�����·��

	int		m_nResolutionx;				// ˮƽ�ֱ���--��λ��pixel
	int		m_nResolutiony;				// ��ֱ�ֱ���
	double	m_dPixelSizex;				// ���ؿ��--��λ��mm
	double	m_dPixelSizey;				// ���ظ߶�

	double	m_dF;						// ����
	double	m_dx0;						// ���������
	double	m_dy0;						// ����������
	double	m_dK1;						// �������
	double	m_dK2;						//
	double	m_dK3;						//
	double	m_dP1;						// �������
	double	m_dP2;						//
	double	m_db1;						// ��ƽ���ڷ������
	double	m_db2;						//

	double	m_dX;						//���ͶӰ��������
	double	m_dY;						//
	double	m_dZ;						//

	double	m_dRa;						// �Ħئ���ת��
	double	m_dRw;						//
	double	m_dRk;						//

	bool m_bDingXiang;                  //�Ƿ񶨹���
	double m_dRotm[9];                  //��ת����

	double	m_dDF;                      //���ƽ��ǰ�ĸ�����
	double	m_dDx0;
	double	m_dDy0;
	double	m_dDK1;
	double	m_dDK2;
	double	m_dDK3;
	double	m_dDP1;
	double	m_dDP2;
	double	m_dDb1;
	double	m_dDb2;
};

/****************************************************
�ļ�����CImagePoint_N.h
���������������

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/
class  BASECLASS_SET CImagePoint_N
{
public:
	CImagePoint_N();
	CImagePoint_N(const CImagePoint_N& Imagepoints);
	CImagePoint_N& operator =(const CImagePoint_N &Imagepoints);
	virtual ~CImagePoint_N();
public:
	char	m_sName[100];                // ����
	int		m_nSta;                 // ������Ƭ���
	int		m_nPt;                  // ��Ӧ�﷽�����(��1��ʼ�ģ����Ǵ�0)
	int	    m_sType;                //������:��ͨ��1�����Ƶ�2�������־��3���������4��Nugget��5
	int		m_nUsedStatus;          //������Ƿ����ƽ�����,-2��ʾƽ��ǰͣ��,-1��ʾƽ���дֲ��޳�,0��ʾδ����,1��ʾ����ʹ��

	double	m_dx;                   // �������x����λ��mm
	double  m_dy;
	double	m_dxCali;				// �������������������x����λ��mm
	double	m_dyCali;
	double	m_dxRes;				// x�Ĳв�
	double	m_dyRes;

	double	m_dPixelx;                   // ԭʼ��������x����λ����
	double  m_dPixely;

	bool    m_bIsMatched;				//������Ƿ��Ѿ������ƥ�䣬��(true)����(false)
	int		m_nNumPix;					// ���ظ���
};

/****************************************************
�ļ�����CPhotoImage.h
����������ͼƬ��

��д�ˣ���׿��
��д���ڣ�2012/09/21

***************************************************/

class  BASECLASS_SET CPhotoImage
{
public:
	CPhotoImage(void);
	~CPhotoImage(void);
	// �������캯��
	CPhotoImage(const CPhotoImage &other);
	// ����=�����
	CPhotoImage&  operator =(const CPhotoImage &other);
	void RenamePoints();//��ȡ���ĵ�����������ͼƬ������ӵ�������
	bool WaiFangWeiFuZhi(double *pdkn);
	void ClearScanAndOrentionData();
	void ClearData();   //�������
	void WriteObject(char *pImageFilePath, char *pSavePath, int nPic); //���ͼ�������
	void WriteObject_b(char *pImageFilePath, char *pSavePath, int nPic);//�����Ƹ�ʽ
	bool ReadObject(char *pImageFilePath); //����ͼ�������
	bool ReadObject_b(char *pImageFilePath);//��������Ƹ�ʽ

	//����
public:
	char m_sImageName[260];						//ͼƬ��
	char m_sPtFileName[260];						//���ļ����ƣ������ͼƬ֮�����ɵ��ļ��������˵����꣬����������
	std::vector<CImagePoint_N>* m_veImagePoints;	    //��ǰͼ����������
	std::vector<EdgePointSet>* m_veLineSet;           //ɨ�����ʱ����ż������������
	bool m_bIsRename;							//�Ƿ��Ѿ�������,��ʼֵfalse
	bool m_bIsOrientationed;                    //�Ƿ��Ѷ���
	unsigned int m_unCountPt;
	int m_nPtIndex[3];                          //����m_veImagePoints�е��������ǰ��m_nPtIndex[0]�������ΪCODE���м�m_nPtIndex[1]�������ΪNUGET�㣬��󱣴��m_nPtIndex[2]��Ϊ����
	bool m_bScaned;                             //�Ƿ��Ѿ�ɨ�����
	byte m_byCountScarbar;                      //��׼�ε�����
	byte m_byPicCriteriaGrade;                  //ͼƬ�ȼ����� 1 good��2 weak��3 bad Ĭ��Ϊ1
	int m_nMatchedPt;                           //ƥ���ϵĵ������
	int m_nUsedPt;                              //���ղ��������ά��ģ���㣩�������
	//��������Ƭʱ��������ⷽλ����
public:
	double m_dXs;						//ͶӰ��������
	double m_dYs;
	double m_dZs;

	double m_Rotax;					//������ת��	�ף��أ���
	double m_Rotay;
	double m_Rotaz;

	double m_RotateArr[9];			//��ת����

	//���򾫶�
	double m_dSigmaX;						//ͶӰ��������
	double m_dSigmaY;
	double m_dSigmaZ;

	double m_RSigmax;					//������ת��	�ף��أ���
	double m_RSigmay;
	double m_RSigmaz;

	double m_dAcc;                    // ͼƬ�ܾ���
	/*
	a1,a2,a3;
	b1,b2,b3;
	c1,c2,c3;

	*/
};

/***********************************************
�ļ�����FaxPlane.h

�ļ�˵�����ṹ��ƽ�������

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XPlane
{
public:
	XPlane();
	XPlane(double da, double db, double dc, Xxyz on_pt); //ͨ��ƽ����һ���ƽ��ķ���ȷ��һ��ƽ��
	XPlane(const XPlane& xPl);
	~XPlane();
	XPlane& operator =(const XPlane& xPl);
	XPlane& operator =(const FaxPlane& xPl);
	XPlane& operator =(const XCircle& xPl);
	bool initialXPlane(char filepath[]); //ֻ�Ǽ�����ƽ�淽�̲���
public:
	char m_Name[260];                      //�ṹ��ƽ������

	//ƽ����� ����ʽ��A*X + B*Y+ C*Z + D = 0;��ϵ��
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;

	CObjectPoints m_PassPt;                          //ƽ����һ�������
	byte m_byUseStates;                              //�������״̬��0��ʹ�ã�1ʹ�ã�3����
	double m_dRms;                                   //ƽ�������
};

/***********************************************
�ļ�����FaxPlane.h

�ļ�˵�����ṹ��ƽ�������

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET FaxPlane
{
public:
	FaxPlane();
	FaxPlane(const FaxPlane& FaxPl);
	FaxPlane(const XPlane& FaxPl);
	~FaxPlane();
	FaxPlane& operator =(const FaxPlane& FaxPl);
	FaxPlane& operator =(const XCircle& FaxPl);
public:
	char m_Name[260];                      //�ṹ��ƽ������
	char m_CrossCam[260];                  //��ͨ����ͶӰ���ĵ������Ҳ���Ǻ��Ǹ�����ཻ��

	//ƽ����� ����ʽ��A*X + B*Y+ C*Z + D = 0;��ϵ��
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;

	byte m_byUseStates;                              //�������״̬��0��ʹ�ã�1ʹ�ã�3����
	vector<CObjectPoints> m_vertexPt;                //�����ƽ��Ķ���
	vector<CObjectPoints> m_veFitPt;                 //������ϵĵ�
	vector<CObjectPoints> m_veProgectPt;             //��ϵ�����Ӧ��ͶӰ�� m_veFitPt.at(0) �� m_veProgectPt.at(0)��һ�Զ�Ӧ��
	double m_dRms;                                   //ƽ�������
	double m_dAngle;                                 //���������ཻ����ϵĳ���б�ʣ�Ҳ��������������ƽ������ϵ�µ�б��
	double m_dDistance;                              //ԭ�㵽�����ߵľ��루������Ϊ��λ��
};

/***********************************************
�ļ�����FaxPlane.h

�ļ�˵�����ṹ��ƽ�������

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XLine
{
public:
	XLine();
	XLine(const CObjectPoints pt_front, const CObjectPoints pt_back);
	XLine(const Xxyz pt_front, const Xxyz pt_back);
	XLine(const XLine& FaxPl);
	XLine(const XVector v1, const CObjectPoints pt_origin, const double dlength);
	bool CreatLine(const CObjectPoints pt_front, const CObjectPoints pt_back);  //����ֱ��
	~XLine();
	XLine& operator =(const XLine& FaxPl);
	CObjectPoints GetEndPoint(void);
public:
	char m_Name[260];                      //��������

	//ֱ�ߵķ�������
	double m_dA;
	double m_dB;
	double m_dC;

	double m_dSlope;                                //ֱ��б�ʣ�һ��������άֱ�ߵģ�
	double m_dConstantc;                            //������c,
	//ֱ��ͨ���Ŀռ�һ�������
	CObjectPoints   m_PassPoint;

	double m_dLength;                               //ֱ�ߵĳ���
	byte m_byWeiDu;                                 //��λ�ռ��������2�����ά�ռ䣬3����3ά�ռ䣬�ȵ���������
	byte m_byUseStates;                             //������״̬��0��ʹ�ã�1ʹ�ã�3����

	vector<CObjectPoints> m_veFitPt;                 //������ϵĵ�
	vector<CObjectPoints> m_veProgectPt;             //��ϵ�����Ӧ��ͶӰ�� m_veFitPt.at(0) �� m_veProgectPt.at(0)��һ�Զ�Ӧ��
	double m_dRms;                                  //�����
};

/***********************************************
�ļ�����BundlePra

�ļ�˵����ƽ�������������

�༭����׿��
���ڣ�2014/12/23
************************************************/
class  BASECLASS_SET BundlePra
{
public:
	BundlePra();
	BundlePra(const BundlePra& FaxPl);
	~BundlePra();
	BundlePra& operator =(const BundlePra& FaxPl);
public:
	//char m_Name[260];                      //��������

	//ǰ�ڶ����õĲ���
	double m_dZuiXiaoJiXianChang;                     //����ʱ��С�Ļ��߳���Ĭ��500mm��
	byte m_byMinCode;                                 //����ʱ����ͼ�����Сͬ���������������CODE�㶨��������Ĭ��Ϊ5����
	bool m_bNullCam;                                  //����ļ��Ƿ�Ϊ�յģ�Ҳ�������������ļ�����������Ƿ��Ѿ�����ֵ�ˣ��Ƿ���Ҫ�궨��
	//���������Ϊtrue������Ϊfalse��Ĭ��ֵΪtrue
	byte m_byCodeType;                                //ʹ�õ���������롢8ΪCODE��1Ϊ���α��루Ĭ��Ϊ8��

	//ƽ���õ�
	byte m_byDieDaiCiShu;                                 //ƽ�����������ֵ��Ĭ��20��
	double m_dShouLianYuZhi;                         //������ֵ�����ȿ��ƣ�
	bool   m_bFullBundle;                            //��ȫƽ��
	byte   m_byMinPic;                               //��СͼƬ����6��
	byte   m_byMinMatchRay;                          //ƥ��ʱ��С��ͬ�����������Զ�ƥ��׶��ã���3����
	byte   m_byMinRay;                               //ǰ������ʱ������ͬ���������2����

	//��׼����
	//��bad criteria��
	byte m_byBadPicNumOfPt;                          //ͼƬ�ϵ������  6
	double m_dBadPicPercentage;                       //ͼƬ�ϵ�Ľ����ʰٷֱ� 	 50%

	byte m_byBadPtNumOfRays;                         //���ͬ��������   2
	double m_dBadPtPercentage;                        //ͬ����ʹ���ʵİٷֱ�	 50%
	double m_dBadPtSigmaX;                            //��ıպϲ�  0.02
	double m_dBadPtSigmaY;
	double m_dBadPtSigmaZ;

	byte m_byBadBarNumOfRays;                         //���ͬ��������   2
	double m_dBadBarPercentage;                        //ͬ����ʹ���ʵİٷֱ�	 50%
	double m_dBadBarSigmaX;                            //��ıպϲ�  0.02
	double m_dBadBarSigmaY;
	double m_dBadBarSigmaZ;

	//��weak criteria��
	byte m_byWeakPicNumOfPt;                            //ͼƬ�ϵ������  12
	double m_dWeakPicPercentage;                        //ͼƬ�ϵ�Ľ����ʰٷֱ� 	 80%

	byte m_byWeakPtNumOfRays;                           //���ͬ��������   4
	double m_dWeakPtPercentage;                         //ͬ����ʹ���ʵİٷֱ�	 75%
	double m_dWeakPtSigmaX;                             //��ıպϲ�  0.002
	double m_dWeakPtSigmaY;
	double m_dWeakPtSigmaZ;

	byte m_byWeakBarNumOfRays;                           //���ͬ��������   4
	double m_dWeakBarPercentage;                         //ͬ����ʹ���ʵİٷֱ�	 75%
	double m_dWeakBarSigmaX;                             //��ıպϲ�  0.002
	double m_dWeakBarSigmaY;
	double m_dWeakBarSigmaZ;
};

class  BASECLASS_SET BundleBack
{
public:
	BundleBack();
	BundleBack(const BundleBack& FaxPl);
	void Reset();
	void Clear();
	~BundleBack();
	BundleBack& operator =(const BundleBack& FaxPl);
public:

	double m_drmsX;                                  //����������������ϵ�ƽ��ֵ
	double m_drmsY;
	double m_drmsZ;

	double m_drmsmaxX;                                  //����������������ϵ����ֵ
	double m_drmsmaxY;
	double m_drmsmaxZ;

	int m_nOverLimitPt;                                  //���޵������
	double m_dZhiLiangYinZi;                             //��������  //���������Ǹ����ڵ���1��������ֵԽ�ӽ���1Խ�ã�����1.5˵���ص��Ȳ��ã�����2˵�����ͽṹ���á�
	double m_dRMS;                                       //���������

	int m_nTotalPic;                                      //��ͼƬ��
	int m_nWeakPic;                                       //��ͼƬ��
	int m_nBadPic;                                        //��ͼƬ��

	int m_nTotalPt;                                      //�ܵ���
	int m_nWeakPt;                                       //������
	int m_nBadPt;                                        //�����

	int m_nTotalBar;                                      //�ܻ�׼����
	int m_nWeakBar;                                       //����׼����
	int m_nBadBar;                                        //���׼����

	byte m_byDieDaiCiShu;                                 //ƽ�����������ֵ��Ĭ��50��
	byte m_byteRealDieDaiCiShu;                           //��ʵ��������
	double *m_dpCanCha;                                   //ÿ�ε����Ĳв�

	double m_dPtLimitYuZhi;                               //��㳬����ֵ
	double m_dBundleProgess;                              //ƽ�����һ�εĽ���
};

/***********************************************
�ļ�����XTriangle.h

�ļ�˵���������ζ���

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XTriangle
{
public:
	XTriangle();
	XTriangle(const XTriangle& FaxPl);
	~XTriangle();
	XTriangle& operator =(const XTriangle& FaxPl);
public:
	char m_Name[260];                      //����

	//������ķ�������
	double m_dA;
	double m_dB;
	double m_dC;

	//������������
	CObjectPoints   m_TrPtA;
	CObjectPoints   m_TrPtB;
	CObjectPoints   m_TrPtC;

	//���Բ�����������
	CObjectPoints   m_CircleCenter;
	double m_dRadius;                               //���Բ�뾶

	//int m_nAdjacentIndex[3];                             //���������ڵ�����������
	int m_nAdjacentCount;                                //���������ڵ�����������
	double m_dArea;                                 //����������
	byte m_byWeiDu;                                 //��λ�ռ��������2�����ά�ռ䣬3����3ά�ռ䣬�ȵ���������
	byte m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XCircle.h

�ļ�˵����Բ����

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XCircle
{
public:
	XCircle();
	XCircle(const XCircle& FaxPl);
	~XCircle();
	XCircle& operator =(const XCircle& FaxPl);
public:
	char m_Name[260];                      //����

	//��ķ�������
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;                                   //Ԫƽ�淽�̵ĳ�����

	//Բ���������������
	CObjectPoints   m_CircleCentPt;
	double m_dRadius;                               //Բ�뾶
	double m_dinRms;                                //Բƽ���ڵ���ϵ㣬���߽�����
	double m_doutRms;								//Բƽ�������ϵ㣬��Բƽ���ͶӰ���
	byte m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����

	vector<CObjectPoints> m_veFitPt;                 //������ϵĵ�
	vector<CObjectPoints> m_veProgectPt;             //��ϵ�����Ӧ��ͶӰ�� m_veFitPt.at(0) �� m_veProgectPt.at(0)��һ�Զ�Ӧ��
};

/***********************************************
�ļ�����XSphere.h

�ļ�˵����Բ����

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XSphere
{
public:
	XSphere();
	XSphere(const XSphere& FaxPl);
	~XSphere();
	XSphere& operator =(const XSphere& FaxPl);
public:
	char m_Name[260];                      //����

	CObjectPoints  m_Center;                         //��������

	double m_dRadius;                               //��뾶
	double m_dRms;                                 //Բƽ���ڵ���ϵ㣬���߽�����
	double m_dDu;								   //Բ��
	byte m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����

	vector<CObjectPoints> m_veFitPt;                 //������ϵĵ�
	vector<CObjectPoints> m_veProgectPt;             //��ϵ�����Ӧ��ͶӰ�� m_veFitPt.at(0) �� m_veProgectPt.at(0)��һ�Զ�Ӧ��
};

/***********************************************
�ļ�����XParaboloid.h

�ļ�˵�������������

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XParaboloid
{
public:
	XParaboloid();
	XParaboloid(const XParaboloid& FaxPl);
	~XParaboloid();
	XParaboloid& operator =(const XParaboloid& FaxPl);
public:
	char m_Name[260];                      //����

	CObjectPoints  m_Vertex;                         //�����涥������
	//������Ŀ��ڷ�����������Ϊ��λ������
	double m_dA;
	double m_dB;
	double m_dC;

	//x2/a + y2/b = 4fz
	double m_da;                                    //x,y��ϵ����Ĭ����1��Ҳ������ת�����棩
	double m_db;
	//����
	double m_df;

	double m_dLong;                                 //������Ӷ��㵽���ڴ��ĳ���
	double m_dRms;                                  //���
	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����

	vector<CObjectPoints> m_veFitPt;                 //������ϵĵ�
	vector<CObjectPoints> m_veProgectPt;             //��ϵ�����Ӧ��ͶӰ�� m_veFitPt.at(0) �� m_veProgectPt.at(0)��һ�Զ�Ӧ��
};

/***********************************************
�ļ�����XVector

�ļ�˵��������

�༭����׿��
���ڣ�2014/04/14
************************************************/
class  BASECLASS_SET XVector
{
public:
	XVector();
	XVector(double i, double j, double k);
	XVector(double dijk[3]);  //i��j��k˳����������飬��Ҫ��������
	XVector(const XVector& FaxPl);
	XVector(const CObjectPoints pt_front, const CObjectPoints pt_back);
	XVector(const Xxyz pt_front, const Xxyz pt_back);
	~XVector();
	XVector& operator =(const XVector& FaxPl);
	XVector& operator =(const XLine& FaxPl);
	XVector& operator =(const FaxPlane& FaxPl);
	XVector& operator =(const XPlane& FaxPl);
	XVector& operator =(const XCircle& FaxPl);
	XVector& operator =(const XParaboloid& FaxPl);
	void Reverse(); //����ȡ����������ǰ�Ӹ���
public:
	char m_Name[260];                      //����

	//��������Ϊ��λ������
	double m_di;
	double m_dj;
	double m_dk;

	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XCuboid

�ļ�˵�������������

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET XCuboid
{
public:
	XCuboid();
	XCuboid(XCuboid& Cub);
	XCuboid(vector<CObjectPoints> CuboidVertex);					//�˸���������,����˳�����ȶ����ĸ���������ĸ�����˳ʱ�뷽�򣻶���͵���ĵ����¶�Ӧ��
	XCuboid(vector<CObjectPoints> CuboidVertex, double dLength);    //�������ϱ��棬��˳ʱ�뷽��˳������������������꣬��ӳ������ڸñ���Ĵ�ֱ�����ϵĸ߶�
	~XCuboid();
	XCuboid& operator =(XCuboid& Cub);
	bool CreatCuboid(vector<CObjectPoints> CuboidVertex);  //����ֱ��
	void VectorCross(XVector v1, XVector v2, XVector &v3);
	void VectorCross(double dv1[], double dv2[], double dv3[]);
	bool CalcuRectanglesFourthVertex(double Material_box[], double FourthVertex[]);
	void GenerateNormal(vector<CObjectPoints> CuboidVertex, XVector &v3);
public:
	char m_Name[260];                      //����

	//��������Ϊ��λ������
	XVector m_TopSurfaceNormals;           //���淨��
	vector<CObjectPoints> m_veCuboidVertex;//�˸���������,����˳�����ȶ����ĸ���������ĸ�����˳ʱ�뷽�򣻶���͵���ĵ����¶�Ӧ��
	CObjectPoints m_CuboidCentPt;          //���ĵ�����
	double m_dCuboidVolume;                //���������

	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XCuboid

�ļ�˵�������������

�༭����׿��
���ڣ�2014/04/14
************************************************/

template<class T>
class BASECLASS_SET XMatrix
{
public:
	XMatrix();
	XMatrix(XMatrix& Cub);
	XMatrix(int nRow, int nColumn);					//�˸���������,����˳�����ȶ����ĸ���������ĸ�����˳ʱ�뷽�򣻶���͵���ĵ����¶�Ӧ��
	XMatrix& operator =(XMatrix& Cub);

	~XMatrix();

public:
	char m_Name[260];                      //����

	int m_nRow;
	int m_nColumn;

	T ** m_pMatrix;

	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XCuboid

�ļ�˵�������������

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET XCoordinateTransPar
{
public:
	XCoordinateTransPar();
	XCoordinateTransPar(XCoordinateTransPar& Par);
	XCoordinateTransPar(double dpar[]);

	~XCoordinateTransPar();
	XCoordinateTransPar& operator =(XCoordinateTransPar& Par);

public:
	//char m_Name[260];                      //����

	double m_dlaim;                       //ϵ��
	CObjectPoints m_Trans;                //ƽ������
	double m_dRotationAngle[3];           //��ת��
	double m_dRotationMatrix[9];          //��ת����

	bool   m_bMatrixassigned;             //��ת�����Ƿ�ֵ�ˣ�Ĭ��Ϊfalse��
	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����Xxyz

�ļ�˵��������������

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET Xxyz
{
public:
	Xxyz();
	Xxyz(const Xxyz& Par);
	Xxyz(const double dpar[]);
	Xxyz(const double dx, const double dy, const double dz, const byte byUseStates = 1);
	Xxyz(const CObjectPoints& Par);
	Xxyz& operator =(const CObjectPoints& Par);
	Xxyz& operator =(const Xxyz& Par);
	Xxyz& operator +(const Xxyz& Par);
	Xxyz& operator -(const Xxyz& Par);

	~Xxyz();
	double Distance(Xxyz Par);
	bool Write3DData_(vector<Xxyz> &opv, char cpath[], byte baoliu);//baoliu == 0 ,fprintf(pFile, "%d %lf %lf %lf\n", por->m_byUseStates, por->m_dX, por->m_dY, por->m_dZ);   baoliu == 1,fprintf(pFile, "%d %lf %lf %lf\n", i, por->m_dX, por->m_dY, por->m_dZ); i++;

	void r_3DData(vector<Xxyz> &opv, char cpath[]);
public:

	double m_dX;
	double m_dY;
	double m_dZ;

	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XRectangle

�ļ�˵�������ζ���

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET XRectangle
{
public:
	XRectangle();
	XRectangle(const XRectangle& re);
	XRectangle(Xxyz pt1, Xxyz pt2, Xxyz pt3, Xxyz pt4);
	XRectangle(Xxyz pt1, Xxyz pt2, Xxyz pt3);
	XRectangle& operator =(const XRectangle& re);
	XRectangle& operator =(const XCuboid& re);
	~XRectangle();

public:

	Xxyz m_pt1;              //�����ĸ�����
	Xxyz m_pt2;
	Xxyz m_pt3;
	Xxyz m_pt4;

	Xxyz m_center_pt;       //�������ĵ�

	double m_dW;            //���ο��
	double m_dH;

	byte   m_byUseStates;                             //�������״̬��0��ʹ�ã�1ʹ�ã�3����
};

/***********************************************
�ļ�����XPostion

�ļ�˵��������ⷽΪ��������

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET XPostion
{
public:
	XPostion();
	XPostion(const XPostion& re);
	XPostion(Xxyz T, double drx, double dry, double drz);
	XPostion& operator =(const XPostion& re);
	~XPostion();

public:

	Xxyz m_T;              //ƽ������
	double m_drotxyz[3];            //��ת��
	double m_dRot[9];          //��ת����
};

/***********************************************
�ļ�����XCameraPos

�ļ�˵��������ⷽΪ��������

�༭����׿��
���ڣ�2014/04/14
************************************************/

class  BASECLASS_SET XCameraPos : public XPostion
{
public:
	XCameraPos();
	XCameraPos(const XCameraPos& re);
	XCameraPos(Xxyz T, double drx, double dry, double drz);
	XCameraPos& operator =(const XCameraPos& re);
	~XCameraPos();

	//public:
	//
	//	Xxyz m_T;              //ƽ������
	//	double m_drotxyz[3];            //��ת��
	//	double m_dRot[9];          //��ת����
};

/*******************************************************
��������  read3DData_Xxyz(vector<Xxyz> &opv, char cpath[])
����˵���� ���ļ����������

����1��opv          <out>             �����������(�ļ���ʽΪ����һ��Ϊ����������ӵڶ��п�ʼ��ÿ�е����ݸ�ʽ���������ո�X���ꡢ�ո�Y���ꡢ�ո�Z����)
����2��cpath                         ����·��
����3��
����4��
����5��
����6��
����7��
����8��
����9��
����10��
����ֵ����

�༭����׿��
���ڣ�2016/04/20
*******************************************************/
BASECLASS_SET void read3DData_Xxyz(vector<Xxyz> &opv, char cpath[]);

/*******************************************************
��������  read3DData_CObjectPoints(vector<CObjectPoints> &opv, char cpath[])
����˵���� ���ļ����������

����1��opv          <out>             �����������(�ļ���ʽΪ����һ��Ϊ����������ӵڶ��п�ʼ��ÿ�е����ݸ�ʽ��������char*�����ո�X���ꡢ�ո�Y���ꡢ�ո�Z����)
����2��cpath                         ����·��
����3��
����4��
����5��
����6��
����7��
����8��
����9��
����10��
����ֵ����

�༭����׿��
���ڣ�2016/04/20
*******************************************************/
BASECLASS_SET void read3DData_CObjectPoints(vector<CObjectPoints> &opv, char cpath[]);

#endif
