#pragma once

//基础类库
#ifndef         _XCLASSSET_H_
#define         _XCLASSSET_H_
/****************************************************
文件名：XClassSet.h
内容描述： 公共类集合

编写人：张卓辉
编写日期：2014/01/20

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

//二维平面上的椭圆类
class BASECLASS_SET CObEllipse
{
public:
	CObEllipse();
	CObEllipse(const CObEllipse& ellipse);
	~CObEllipse();
	CObEllipse& CObEllipse::operator=(const CObEllipse& ellipse);

	double m_dX;                          //椭圆的中心点坐标(x标示横坐标，y标示高度方向上的坐标)拟合的圆心坐标
	double m_dY;

	double m_dx;                          //灰度重心计算得到的圆心坐标
	double m_dy;

	byte m_byUseStates;                              //三角面的状态，0不使用，1使用，3其他
	bool m_bTheOtherOb;                         //是非椭圆类型图形，既不是元，也不是椭圆
	bool m_bIsCircle;                           //这是否是个圆；false = 椭圆, true = 圆
	double m_dEllipseRatio[5];                   //ax2+bxy+cy2+dx+ey+1 = 0;  一次为方程上的系数
	double m_dTouYingRMS;                       //参与拟合的点，在椭圆上的投影距的平局值，这个值越大说明越不是元

	double m_da2;                               //椭圆的长轴
	double m_db2;                               //椭圆的短轴

	double m_de;                               //椭圆的离心率
	double m_dth;                               //椭圆的旋转角

	double m_dRms;                              //元的定位精度
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

	byte m_byUseStates;                       //点的使用状态，1正常使用，2不能用的，3处理过的点

	double m_dDistance;           //点到直线的距离
};

//闭合区域的边缘点的集合
class BASECLASS_SET EdgePointSet
{
public:
	EdgePointSet();
	~EdgePointSet();
	EdgePointSet(const EdgePointSet& pointLink);
	EdgePointSet& EdgePointSet::operator=(const EdgePointSet& pointLink);
	//   void SetPointLinkList(const CXPoint & xp);
	//void ClearPointLinkList(void);
	//环形编码使用
	std::vector<CXPoint> *m_PointLinkList;             //一个闭合边缘的组成点点集
	CObEllipse m_ObEllipse;                     //点集所对应的椭圆

	char m_cCodeName[260];            //对应的编码名称
	int m_nCodeNum;                             //对应码值，就是几号

	//扫描测量使用
	bool m_bLaserLine;                          //是否为激光线条（当线条上的点数大于一定阈值时，就为真）
	bool m_bFaxLine;                            //是否为固定位置的激光线
	double m_dSlope;                            //固定激光线的斜率
	double m_dDistance;                         //原点到固定激光线的距离
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
	//定义位图信息头结构变量，读取位图信息头进内存，
	//存放在变量head中
	BITMAPINFOHEADER head;
	BITMAPFILEHEADER bmpFileHead;    //定义文件头对象
	int	m_nWidth;                    //宽
	int	m_nHeight;                   //高
	int	m_biBitCount;                //位深
	RGBQUAD  *m_pColorTable;         //调色板
	BITMAPINFO *m_lpbmi;            //
	bool m_bAdded;                   //添加过图像了

	int m_nBitsWidth;                // 图象中每行的字节数
	unsigned char* m_pucS;			// 指向原图象象素的指针
};
class BASECLASS_SET LaserLinePara
{
public:
	LaserLinePara();
	~LaserLinePara();
	LaserLinePara& LaserLinePara::operator=(const LaserLinePara& para);

	byte m_byMinHuiDuZhi;                              //激光光斑的最小灰度值(默认值10)，激光光斑的灰度一定大于这个数，这个数不一定是激光光斑的最小亮度值
	byte m_byMinNumPointLine;                          //一条激光线最少要包含多少个点(默认值15)，如果小于这个数，这个点链条就不是激光链条的一部分，当做干扰点过滤掉。
	byte m_byMaxLineRat;                               //线条半径宽度阈值（线条最大的宽度半径阈值，默认为一侧宽度30，总宽度60像素）
	byte m_byMaxRange;                                 //固定激光的最大的变动范围(默认值5个像素)，用来判定那张图像上的激光点是固定的。
	byte m_byCenterToLineRange;                        //图像中心到激光直线的最大距离用来判定那张图像上的激光点是固定的。(默认值10个像素)
	double m_dMaxRangePoiToPlane;                      //三维点过滤阈值（默认1.0mm），计算出的三维点，当到激光平面的距离大于这个值时，舍去。
	byte m_byNiHeDianShu;                              //在提取激光线条中心时，需要用附近的点进行直线拟合，以求得直线的法线方向.这个变量用来确定使用附近几个点拟合(默认值9个像素)
	float m_fXieLvJiaoDuYuZhi;                         //激光线条的斜率阈值，这个用来判断提取到的激光线条是否为固定激光。
	float m_fFaxLaserJiaoDu;                           //在定向后算出来的固定激光线条的斜率（注意哦不是角度），默认值为零。
	byte m_byBianJieRangeThreshold;                    //距离图像边界多少个像素的点，就不能使用了（默认15个）

protected:
private:
};

//code的解码参数类
class BASECLASS_SET XCodePara
{
public:
	XCodePara();
	XCodePara(const XCodePara& para);
	~XCodePara();
	XCodePara& XCodePara::operator=(const XCodePara& para);

public:
	int m_nRadius;                          //编码尺寸 单位毫米
	int m_nCodeAngle;                       //b编码度数（必须为正整数）
	int m_nCodeBite;                        //编码位数
	double m_dSearchRadiusRate;             //搜索半径倍率，搜索半径 = 几倍的圆点半径长（默认3.35倍）1：1.7：1.3半径、间距、环宽
	double m_dRaToOutCilcle;                //圆心到编码环内壁的距离（圆的半径加间隔圆环的宽度）1+1.7
	double m_dTotalLong;                    //圆心到外径的总长(半径 + 间距 + 环宽)
	double m_dProjectThreshold;             //投影误差的阈值，用以判定该拟合图形是圆还是椭圆（单位是像素，默认为一）
	int m_nMinPiex;                         //圆形的最小、最大像素数
	int m_nMaxPiex;
	int m_nEllipseCorreatThreshold;         //阈值，对编码区域的像素点是否进行椭圆纠正(是否进行椭圆纠正，默认阈值0.5个像素)
	int m_nAngleErrorThreshold;             //编码角度的误差阈值  (默认为0.2倍的m_nCodeAngle)
	double m_dEccentricityThreshold;        //离心率的阈值（默认0.9（单位像素））
	unsigned char m_RadiusExpand;                    //半径扩张长度（额外加大半径长度）

	//二值化专用的控制变量

public:
	//环境条件
	bool m_bIsBackgroundHighlight;           //背景色是否更突出（更亮）
	bool m_bIsOutDoorUse;                    //是否在室外应用
	bool m_bCorreatblur;                     // 是否纠正模糊

protected:
private:
};

/***********************************************
文件名：BaseCla.h

文件说明：Code点提取的参数类，用来设置提取参数值

编辑：张卓辉
日期：2014/04/14
************************************************/
class BASECLASS_SET CPara1
{
public:
	CPara1(void);
	CPara1(const CPara1& Para);
	~CPara1(void);
	CPara1& CPara1::operator=(const CPara1& Para);
	void ToDefault(void);
	// 像点扫描参数
	int			m_nMaxScanRadius_T_Scan;	// 标志点最大搜索半径
	int			m_nMaxScanRadius_R_Scan;	// Ring最大搜索半径
	int			m_nStep_Scan;				// 扫描步长
	int			m_nDelta_Scan;		 		// 边缘阈值
	double		m_dBias_Scan;				// 偏差
	double		m_dGain_Scan;				// 增益
	int			m_nMeanGrayMin_T_Scan;	    // 标志点检验阈值，灰度均值最小值
	int			m_nNumPixelMax_T_Scan;		// 最大像素数
	int			m_nNumPixelMin_T_Scan;		// 最小像素数
	int			m_nNumPixelxMax_T_Scan;		// x方向最大像素数
	int			m_nNumPixelxMin_T_Scan;		// x方向最小像素数
	int			m_nNumPixelyMax_T_Scan;		// y方向最大像素数
	int			m_nNumPixelyMin_T_Scan;		// y方向最小像素数
	double		m_dAspect_T_Scan;			// 两方向像素数比值最小值(y/x或x/y)
	int			m_nMeanGrayMin_R_Scan;	    // Ring检验阈值，灰度均值最小值
	int			m_nNumPixelMax_R_Scan;		// 最大像素数
	int			m_nNumPixelMin_R_Scan;		// 最小像素数
	int			m_nNumPixelxMax_R_Scan;		// x方向最大像素数
	int			m_nNumPixelxMin_R_Scan;		// x方向最小像素数
	int			m_nNumPixelyMax_R_Scan;		// x方向最大像素数
	int			m_nNumPixelyMin_R_Scan;		// x方向最小像素数
	double		m_dAspect_R_Scan;			// 两方向像素数比值最小值(y/x或x/y)

	// AutoBar解码参数
	double m_dDisFactor_AutoBar;			// 距离因子
	double m_dDisFactor_Pt5_AutoBar;		// AutoBar5点距离因子
	double m_dDisFactor_Pt2_4_AutoBar;		// 点2、4到交点7的距离最大比值
	double m_dMaxCrossRatio_AutoBar;		// 交比阈值

	// 编码标志解码参数
	double m_dDisFactor_Code;			// 距离阈值系数      //当拍摄距离比较远，CODE比较小时，这个数相应的应该设置的比较大。
	double m_dMaxRms_Code;				// 最大Rms阈值
	double m_dCloseness_Code;			// 模板点仿射变换坐标与设计坐标最大距离
	double m_dMaxCrossRatio_Code;		// 交比最大差值
};

/********************************************
ObjectPoint.h
内容： 物方点类

编写人：张卓辉
日期：2012/08/30
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
	int		m_nPt;				// 序号
	char	m_sName[100];			// 点名

	double	m_dX;				// X坐标
	double	m_dY;				// Y坐标
	double	m_dZ;				// Z坐标

	double	m_dStdX;			// StdX	均方根
	double	m_dStdY;			// StdY
	double	m_dStdZ;			// StdZ
	double	m_dStdXYZ;			// StdXYZ 总精度

	int		m_nNumStaUsed;		// 对应可用像点数
	int		m_nNumSta;			// 对应总像点数，包括可用像点和粗差像点

	byte m_byPtCriteriaGrade;  //点等级分类 1 good、2 weak、3 bad 默认为1
	char	m_sType;            // 点类型:普通点(1)、控制点(2)、编码标志点(3)、定向棒点(4) .点的类型用括号内对应的数字标示
	int		m_nUsedStatus;		// 是否参与解算,-2表示平差前剔除,-1表示平差中粗差剔除,1表示正常使用

	int   m_shMaxShu;          //最大记录个数（也即是如果一个点的同名点的个数超出这个值，超出的部分不统计） 默认500
	int   m_shRealShu;		   //这个点被多少张图像拍到
	int   m_shPicIndex[1000];  //这个点成像的图像的索引值（从零开始）,以及像点在链表中的位置（从零开始）（一个图相对应两个数）
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
	char	m_sName[100];			// 点名
	std::vector<CObjectPoints> *m_vectObjectPoints; //同名点集合
	std::vector<XLine> *m_veLines; //同名点集合
	std::vector<FaxPlane> *m_vePlanes; //同名点集合
	std::vector<XCircle> *m_veCircle; //同名点集合
	std::vector<XParaboloid> *m_veParaboloid; //同名点集合
	std::vector<XSphere> *m_veSphere; //同名点集合

	double m_dRMS;                  //工程中误差
	double m_dXYZ;                  //物方点精度(由m_drmsX、m_drmsY、m_drmsZ三个分量合成)

	double m_drmsX;                  //X方向物方点中误差
	double m_drmsY;                  //Y方向物方点中误差
	double m_drmsZ;                  //Z方向物方点中误差

	double m_dmaxX;                  //X方向物方点最大中误差
	double m_dmaxY;                  //Y方向物方点最大中误差
	double m_dmaxZ;                  //Z方向物方点最大中误差
};

/****************************************************
文件名：SamePoint.h
内容描述：同名点的类，记录一组同名点

编写人：张卓辉
编写日期：2012/09/21

***************************************************/
class  BASECLASS_SET CSamePoint
{
public:
	CSamePoint(void);
	~CSamePoint(void);
	// 拷贝构造函数
	CSamePoint(const CSamePoint &other);
	// 重载=运算符
	CSamePoint&  operator =(const CSamePoint &other);
	//void SetViewCam(short vcam);
	//void ClearViewCam(void);

	char m_cPointName[100];		//像点的名字

	//相片A上的想点坐标
	double m_dAX;
	double m_dAY;
	double m_dAZ;

	//相片B上的像点坐标
	double m_dBX;
	double m_dBY;
	double m_dBZ;

	//左右视差
	double m_HorizontalParallax; //左右视差
};

class  BASECLASS_SET CSamePointVect
{
public:
	CSamePointVect(void);
	~CSamePointVect(void);
	// 拷贝构造函数
	CSamePointVect(const CSamePointVect &other);
	//CSamePointVect(const vector<CSamePoint> &other);
	// 重载=运算符
	CSamePointVect&  operator =(const CSamePointVect &other);

	char m_cPicName[100];		//图像的名字

	std::vector<CSamePoint>* m_vectSamePoint; //同名点集合m_vectSamePoint
};

/****************************************************
文件名：CCtrlDataSet.h
内容描述：k控制点集合

编写人：张卓辉
编写日期：2012/09/21

***************************************************/
class BASECLASS_SET CCtrlDataSet
{
public:
	CCtrlDataSet(void);
	~CCtrlDataSet(void);
	CCtrlDataSet(const CCtrlDataSet &other);

	// 重载=运算符
	CCtrlDataSet&  operator =(const CCtrlDataSet &other);

	CSamePoint   m_SPoint;  //这个点的名称也就是这个集合的名称

	double       m_dXs;
	double       m_dYs;
	double       m_dZs;

	double       m_da; //三个旋转角
	double       m_dw;
	double       m_dk;

	double       m_dRoMatr[9];        //旋转矩阵常规排列
	// a1,a2,a3
	// b1,b2,b3
	// c1,c2,c3
};

/****************************************************
文件名：CScaleBar.h
内容描述：基准尺子类

编写人：张卓辉
编写日期：2012/09/21

***************************************************/
class BASECLASS_SET  CScaleBar
{
public:
	CScaleBar(void);
	CScaleBar(const CScaleBar& bar);
	~CScaleBar(void);
	CScaleBar& operator =(const CScaleBar& bar);

	char m_cName[100];					//基准尺名称

	CObjectPoints m_BarPoints1;			//组成基准尺两个端点的点,名基准尺两端的端点坐标值
	CObjectPoints m_BarPoints2;

	double m_dBarLength;				//基准尺的长度
};

/****************************************************
文件名：CCamera1.h
内容描述：相机文件类

编写人：张卓辉
编写日期：2012/09/21

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
	char m_sName[100];					// 相机名称--关键字段
	char	m_sFileName[100];				// 标定文件名及路径

	int		m_nResolutionx;				// 水平分辨率--单位：pixel
	int		m_nResolutiony;				// 垂直分辨率
	double	m_dPixelSizex;				// 象素宽度--单位：mm
	double	m_dPixelSizey;				// 象素高度

	double	m_dF;						// 主距
	double	m_dx0;						// 主点横坐标
	double	m_dy0;						// 主点纵坐标
	double	m_dK1;						// 径向畸变
	double	m_dK2;						//
	double	m_dK3;						//
	double	m_dP1;						// 切向畸变
	double	m_dP2;						//
	double	m_db1;						// 像平面内仿射畸变
	double	m_db2;						//

	double	m_dX;						//相机投影中心坐标
	double	m_dY;						//
	double	m_dZ;						//

	double	m_dRa;						// δωκ旋转角
	double	m_dRw;						//
	double	m_dRk;						//

	bool m_bDingXiang;                  //是否定过向
	double m_dRotm[9];                  //旋转矩阵

	double	m_dDF;                      //相对平差前的改正数
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
文件名：CImagePoint_N.h
内容描述：像点类

编写人：张卓辉
编写日期：2012/09/21

***************************************************/
class  BASECLASS_SET CImagePoint_N
{
public:
	CImagePoint_N();
	CImagePoint_N(const CImagePoint_N& Imagepoints);
	CImagePoint_N& operator =(const CImagePoint_N &Imagepoints);
	virtual ~CImagePoint_N();
public:
	char	m_sName[100];                // 点名
	int		m_nSta;                 // 所在像片序号
	int		m_nPt;                  // 对应物方点序号(从1开始的，不是从0)
	int	    m_sType;                //点类型:普通点1、控制点2、编码标志点3、定向棒点4，Nugget点5
	int		m_nUsedStatus;          //该像点是否参与平差计算,-2表示平差前停用,-1表示平差中粗差剔除,0表示未成像,1表示正常使用

	double	m_dx;                   // 像点坐标x，单位：mm
	double  m_dy;
	double	m_dxCali;				// 加入畸变改正后像点坐标x，单位：mm
	double	m_dyCali;
	double	m_dxRes;				// x的残差
	double	m_dyRes;

	double	m_dPixelx;                   // 原始像素坐标x，单位：个
	double  m_dPixely;

	bool    m_bIsMatched;				//这个点是否已经完成了匹配，是(true)，否(false)
	int		m_nNumPix;					// 像素个数
};

/****************************************************
文件名：CPhotoImage.h
内容描述：图片类

编写人：张卓辉
编写日期：2012/09/21

***************************************************/

class  BASECLASS_SET CPhotoImage
{
public:
	CPhotoImage(void);
	~CPhotoImage(void);
	// 拷贝构造函数
	CPhotoImage(const CPhotoImage &other);
	// 重载=运算符
	CPhotoImage&  operator =(const CPhotoImage &other);
	void RenamePoints();//提取到的点重命名，将图片名称添加到点命中
	bool WaiFangWeiFuZhi(double *pdkn);
	void ClearScanAndOrentionData();
	void ClearData();   //清除数据
	void WriteObject(char *pImageFilePath, char *pSavePath, int nPic); //输出图像类对象
	void WriteObject_b(char *pImageFilePath, char *pSavePath, int nPic);//二进制格式
	bool ReadObject(char *pImageFilePath); //读入图像类对象
	bool ReadObject_b(char *pImageFilePath);//读入二进制格式

	//属性
public:
	char m_sImageName[260];						//图片名
	char m_sPtFileName[260];						//点文件名称（处理过图片之后生成的文件，保存了点坐标，相机外参数）
	std::vector<CImagePoint_N>* m_veImagePoints;	    //当前图像的像点链表
	std::vector<EdgePointSet>* m_veLineSet;           //扫描测量时，存放激光的线条坐标
	bool m_bIsRename;							//是否已经重命名,初始值false
	bool m_bIsOrientationed;                    //是否已定向
	unsigned int m_unCountPt;
	int m_nPtIndex[3];                          //链表m_veImagePoints中点的索引，前面m_nPtIndex[0]个保存的为CODE，中间m_nPtIndex[1]个保存的为NUGET点，最后保存的m_nPtIndex[2]个为单点
	bool m_bScaned;                             //是否已经扫描过了
	byte m_byCountScarbar;                      //基准次的数量
	byte m_byPicCriteriaGrade;                  //图片等级分类 1 good、2 weak、3 bad 默认为1
	int m_nMatchedPt;                           //匹配上的点的数量
	int m_nUsedPt;                              //最终参与计算三维点的（像点）点的数量
	//拍这张相片时，相机的外方位参数
public:
	double m_dXs;						//投影中心坐标
	double m_dYs;
	double m_dZs;

	double m_Rotax;					//三个旋转角	ψ，ω，Κ
	double m_Rotay;
	double m_Rotaz;

	double m_RotateArr[9];			//旋转矩阵

	//定向精度
	double m_dSigmaX;						//投影中心坐标
	double m_dSigmaY;
	double m_dSigmaZ;

	double m_RSigmax;					//三个旋转角	ψ，ω，Κ
	double m_RSigmay;
	double m_RSigmaz;

	double m_dAcc;                    // 图片总精度
	/*
	a1,a2,a3;
	b1,b2,b3;
	c1,c2,c3;

	*/
};

/***********************************************
文件名：FaxPlane.h

文件说明：结构光平面参数类

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XPlane
{
public:
	XPlane();
	XPlane(double da, double db, double dc, Xxyz on_pt); //通过平面上一点和平面的法线确定一个平面
	XPlane(const XPlane& xPl);
	~XPlane();
	XPlane& operator =(const XPlane& xPl);
	XPlane& operator =(const FaxPlane& xPl);
	XPlane& operator =(const XCircle& xPl);
	bool initialXPlane(char filepath[]); //只是加载了平面方程参数
public:
	char m_Name[260];                      //结构光平面名称

	//平面参数 方程式：A*X + B*Y+ C*Z + D = 0;的系数
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;

	CObjectPoints m_PassPt;                          //平面上一点的坐标
	byte m_byUseStates;                              //三角面的状态，0不使用，1使用，3其他
	double m_dRms;                                   //平面中误差
};

/***********************************************
文件名：FaxPlane.h

文件说明：结构光平面参数类

编辑：张卓辉
日期：2014/04/14
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
	char m_Name[260];                      //结构光平面名称
	char m_CrossCam[260];                  //所通过的投影中心的相机（也即是和那个相机相交）

	//平面参数 方程式：A*X + B*Y+ C*Z + D = 0;的系数
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;

	byte m_byUseStates;                              //三角面的状态，0不使用，1使用，3其他
	vector<CObjectPoints> m_vertexPt;                //多边形平面的顶点
	vector<CObjectPoints> m_veFitPt;                 //参与拟合的点
	vector<CObjectPoints> m_veProgectPt;             //拟合点所对应的投影点 m_veFitPt.at(0) 和 m_veProgectPt.at(0)是一对对应点
	double m_dRms;                                   //平面中误差
	double m_dAngle;                                 //激光光斑在相交相机上的成像斜率，也即是这条线在向平面坐标系下的斜率
	double m_dDistance;                              //原点到激光光斑的距离（以像素为单位）
};

/***********************************************
文件名：FaxPlane.h

文件说明：结构光平面参数类

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XLine
{
public:
	XLine();
	XLine(const CObjectPoints pt_front, const CObjectPoints pt_back);
	XLine(const Xxyz pt_front, const Xxyz pt_back);
	XLine(const XLine& FaxPl);
	XLine(const XVector v1, const CObjectPoints pt_origin, const double dlength);
	bool CreatLine(const CObjectPoints pt_front, const CObjectPoints pt_back);  //生成直线
	~XLine();
	XLine& operator =(const XLine& FaxPl);
	CObjectPoints GetEndPoint(void);
public:
	char m_Name[260];                      //线条名称

	//直线的方向向量
	double m_dA;
	double m_dB;
	double m_dC;

	double m_dSlope;                                //直线斜率（一般针对与二维直线的）
	double m_dConstantc;                            //常数项c,
	//直线通过的空间一点的坐标
	CObjectPoints   m_PassPoint;

	double m_dLength;                               //直线的长度
	byte m_byWeiDu;                                 //几位空间的线条，2代表二维空间，3代表3维空间，等等依次类推
	byte m_byUseStates;                             //线条的状态，0不使用，1使用，3其他

	vector<CObjectPoints> m_veFitPt;                 //参与拟合的点
	vector<CObjectPoints> m_veProgectPt;             //拟合点所对应的投影点 m_veFitPt.at(0) 和 m_veProgectPt.at(0)是一对对应点
	double m_dRms;                                  //中误差
};

/***********************************************
文件名：BundlePra

文件说明：平差计算的输入参数

编辑：张卓辉
日期：2014/12/23
************************************************/
class  BASECLASS_SET BundlePra
{
public:
	BundlePra();
	BundlePra(const BundlePra& FaxPl);
	~BundlePra();
	BundlePra& operator =(const BundlePra& FaxPl);
public:
	//char m_Name[260];                      //线条名称

	//前期定向用的参数
	double m_dZuiXiaoJiXianChang;                     //定向时最小的基线长（默认500mm）
	byte m_byMinCode;                                 //定向时两张图像的最小同名点数量（仅针对CODE点定向的情况，默认为5个）
	bool m_bNullCam;                                  //相机文件是否为空的（也就是输入的相机文件，畸变参数是否已经付过值了，是否需要标定）
	//，如果是则为true，否则为false。默认值为true
	byte m_byCodeType;                                //使用的是哪类编码、8为CODE、1为环形编码（默认为8）

	//平差用的
	byte m_byDieDaiCiShu;                                 //平差迭代次数阈值（默认20）
	double m_dShouLianYuZhi;                         //收敛阈值（精度控制）
	bool   m_bFullBundle;                            //完全平差
	byte   m_byMinPic;                               //最小图片数量6张
	byte   m_byMinMatchRay;                          //匹配时最小的同名点数量（自动匹配阶段用）（3个）
	byte   m_byMinRay;                               //前方交会时，最少同名点个数（2个）

	//标准测试
	//【bad criteria】
	byte m_byBadPicNumOfPt;                          //图片上点的数量  6
	double m_dBadPicPercentage;                       //图片上点的解算率百分比 	 50%

	byte m_byBadPtNumOfRays;                         //点的同名点数量   2
	double m_dBadPtPercentage;                        //同名点使用率的百分比	 50%
	double m_dBadPtSigmaX;                            //点的闭合差  0.02
	double m_dBadPtSigmaY;
	double m_dBadPtSigmaZ;

	byte m_byBadBarNumOfRays;                         //点的同名点数量   2
	double m_dBadBarPercentage;                        //同名点使用率的百分比	 50%
	double m_dBadBarSigmaX;                            //点的闭合差  0.02
	double m_dBadBarSigmaY;
	double m_dBadBarSigmaZ;

	//【weak criteria】
	byte m_byWeakPicNumOfPt;                            //图片上点的数量  12
	double m_dWeakPicPercentage;                        //图片上点的解算率百分比 	 80%

	byte m_byWeakPtNumOfRays;                           //点的同名点数量   4
	double m_dWeakPtPercentage;                         //同名点使用率的百分比	 75%
	double m_dWeakPtSigmaX;                             //点的闭合差  0.002
	double m_dWeakPtSigmaY;
	double m_dWeakPtSigmaZ;

	byte m_byWeakBarNumOfRays;                           //点的同名点数量   4
	double m_dWeakBarPercentage;                         //同名点使用率的百分比	 75%
	double m_dWeakBarSigmaX;                             //点的闭合差  0.002
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

	double m_drmsX;                                  //中误差在三个方向上的平均值
	double m_drmsY;
	double m_drmsZ;

	double m_drmsmaxX;                                  //中误差在三个方向上的最大值
	double m_drmsmaxY;
	double m_drmsmaxZ;

	int m_nOverLimitPt;                                  //超限点的数量
	double m_dZhiLiangYinZi;                             //质量因子  //质量因子是个大于等于1的数，该值越接近于1越好；大于1.5说明重叠度不好，大于2说明网型结构不好。
	double m_dRMS;                                       //测量中误差

	int m_nTotalPic;                                      //总图片数
	int m_nWeakPic;                                       //弱图片数
	int m_nBadPic;                                        //差图片数

	int m_nTotalPt;                                      //总点数
	int m_nWeakPt;                                       //弱点数
	int m_nBadPt;                                        //差点数

	int m_nTotalBar;                                      //总基准尺数
	int m_nWeakBar;                                       //弱基准尺数
	int m_nBadBar;                                        //差基准尺数

	byte m_byDieDaiCiShu;                                 //平差迭代次数阈值（默认50）
	byte m_byteRealDieDaiCiShu;                           //真实迭代次数
	double *m_dpCanCha;                                   //每次迭代的残差

	double m_dPtLimitYuZhi;                               //像点超限阈值
	double m_dBundleProgess;                              //平差迭代一次的进度
};

/***********************************************
文件名：XTriangle.h

文件说明：三角形对象

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XTriangle
{
public:
	XTriangle();
	XTriangle(const XTriangle& FaxPl);
	~XTriangle();
	XTriangle& operator =(const XTriangle& FaxPl);
public:
	char m_Name[260];                      //名称

	//三角面的方向向量
	double m_dA;
	double m_dB;
	double m_dC;

	//三个顶点坐标
	CObjectPoints   m_TrPtA;
	CObjectPoints   m_TrPtB;
	CObjectPoints   m_TrPtC;

	//外接圆或外接球坐标
	CObjectPoints   m_CircleCenter;
	double m_dRadius;                               //外接圆半径

	//int m_nAdjacentIndex[3];                             //和自身相邻的三角形索引
	int m_nAdjacentCount;                                //和自身相邻的三角形数量
	double m_dArea;                                 //三角面的面积
	byte m_byWeiDu;                                 //几位空间的线条，2代表二维空间，3代表3维空间，等等依次类推
	byte m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XCircle.h

文件说明：圆对象

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XCircle
{
public:
	XCircle();
	XCircle(const XCircle& FaxPl);
	~XCircle();
	XCircle& operator =(const XCircle& FaxPl);
public:
	char m_Name[260];                      //名称

	//面的方向向量
	double m_dA;
	double m_dB;
	double m_dC;
	double m_dD;                                   //元平面方程的常数项

	//圆心坐标或球心坐标
	CObjectPoints   m_CircleCentPt;
	double m_dRadius;                               //圆半径
	double m_dinRms;                                //圆平面内的拟合点，到边界的误差
	double m_doutRms;								//圆平面外的拟合点，到圆平面的投影误差
	byte m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他

	vector<CObjectPoints> m_veFitPt;                 //参与拟合的点
	vector<CObjectPoints> m_veProgectPt;             //拟合点所对应的投影点 m_veFitPt.at(0) 和 m_veProgectPt.at(0)是一对对应点
};

/***********************************************
文件名：XSphere.h

文件说明：圆对象

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XSphere
{
public:
	XSphere();
	XSphere(const XSphere& FaxPl);
	~XSphere();
	XSphere& operator =(const XSphere& FaxPl);
public:
	char m_Name[260];                      //名称

	CObjectPoints  m_Center;                         //球心坐标

	double m_dRadius;                               //球半径
	double m_dRms;                                 //圆平面内的拟合点，到边界的误差
	double m_dDu;								   //圆度
	byte m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他

	vector<CObjectPoints> m_veFitPt;                 //参与拟合的点
	vector<CObjectPoints> m_veProgectPt;             //拟合点所对应的投影点 m_veFitPt.at(0) 和 m_veProgectPt.at(0)是一对对应点
};

/***********************************************
文件名：XParaboloid.h

文件说明：抛物面对象

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XParaboloid
{
public:
	XParaboloid();
	XParaboloid(const XParaboloid& FaxPl);
	~XParaboloid();
	XParaboloid& operator =(const XParaboloid& FaxPl);
public:
	char m_Name[260];                      //名称

	CObjectPoints  m_Vertex;                         //抛物面顶点坐标
	//抛物面的开口方向向量（化为单位向量）
	double m_dA;
	double m_dB;
	double m_dC;

	//x2/a + y2/b = 4fz
	double m_da;                                    //x,y的系数（默认是1，也就是旋转抛物面）
	double m_db;
	//焦距
	double m_df;

	double m_dLong;                                 //抛物面从顶点到开口处的长度
	double m_dRms;                                  //误差
	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他

	vector<CObjectPoints> m_veFitPt;                 //参与拟合的点
	vector<CObjectPoints> m_veProgectPt;             //拟合点所对应的投影点 m_veFitPt.at(0) 和 m_veProgectPt.at(0)是一对对应点
};

/***********************************************
文件名：XVector

文件说明：向量

编辑：张卓辉
日期：2014/04/14
************************************************/
class  BASECLASS_SET XVector
{
public:
	XVector();
	XVector(double i, double j, double k);
	XVector(double dijk[3]);  //i、j、k顺序输入的数组，需要三个数。
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
	void Reverse(); //向量取反，各分量前加负号
public:
	char m_Name[260];                      //名称

	//向量（化为单位向量）
	double m_di;
	double m_dj;
	double m_dk;

	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XCuboid

文件说明：长方体对象

编辑：张卓辉
日期：2014/04/14
************************************************/

class  BASECLASS_SET XCuboid
{
public:
	XCuboid();
	XCuboid(XCuboid& Cub);
	XCuboid(vector<CObjectPoints> CuboidVertex);					//八个顶点坐标,排列顺序是先顶面四个，后底面四个，按顺时针方向；顶面和底面的点上下对应。
	XCuboid(vector<CObjectPoints> CuboidVertex, double dLength);    //长方体上表面，按顺时针方向顺序输入的三个顶点坐标，外加长方体在该表面的垂直方向上的高度
	~XCuboid();
	XCuboid& operator =(XCuboid& Cub);
	bool CreatCuboid(vector<CObjectPoints> CuboidVertex);  //生成直线
	void VectorCross(XVector v1, XVector v2, XVector &v3);
	void VectorCross(double dv1[], double dv2[], double dv3[]);
	bool CalcuRectanglesFourthVertex(double Material_box[], double FourthVertex[]);
	void GenerateNormal(vector<CObjectPoints> CuboidVertex, XVector &v3);
public:
	char m_Name[260];                      //名称

	//向量（化为单位向量）
	XVector m_TopSurfaceNormals;           //顶面法线
	vector<CObjectPoints> m_veCuboidVertex;//八个顶点坐标,排列顺序是先顶面四个，后底面四个，按顺时针方向；顶面和底面的点上下对应。
	CObjectPoints m_CuboidCentPt;          //中心点坐标
	double m_dCuboidVolume;                //长方体体积

	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XCuboid

文件说明：长方体对象

编辑：张卓辉
日期：2014/04/14
************************************************/

template<class T>
class BASECLASS_SET XMatrix
{
public:
	XMatrix();
	XMatrix(XMatrix& Cub);
	XMatrix(int nRow, int nColumn);					//八个顶点坐标,排列顺序是先顶面四个，后底面四个，按顺时针方向；顶面和底面的点上下对应。
	XMatrix& operator =(XMatrix& Cub);

	~XMatrix();

public:
	char m_Name[260];                      //名称

	int m_nRow;
	int m_nColumn;

	T ** m_pMatrix;

	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XCuboid

文件说明：长方体对象

编辑：张卓辉
日期：2014/04/14
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
	//char m_Name[260];                      //名称

	double m_dlaim;                       //系数
	CObjectPoints m_Trans;                //平移向量
	double m_dRotationAngle[3];           //旋转角
	double m_dRotationMatrix[9];          //旋转矩阵

	bool   m_bMatrixassigned;             //旋转矩阵是否赋值了（默认为false）
	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：Xxyz

文件说明：简洁坐标对象

编辑：张卓辉
日期：2014/04/14
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

	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XRectangle

文件说明：矩形对象

编辑：张卓辉
日期：2014/04/14
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

	Xxyz m_pt1;              //矩形四个顶点
	Xxyz m_pt2;
	Xxyz m_pt3;
	Xxyz m_pt4;

	Xxyz m_center_pt;       //矩形中心点

	double m_dW;            //矩形宽高
	double m_dH;

	byte   m_byUseStates;                             //三角面的状态，0不使用，1使用，3其他
};

/***********************************************
文件名：XPostion

文件说明：相机外方为参数对象

编辑：张卓辉
日期：2014/04/14
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

	Xxyz m_T;              //平移向量
	double m_drotxyz[3];            //旋转角
	double m_dRot[9];          //旋转矩阵
};

/***********************************************
文件名：XCameraPos

文件说明：相机外方为参数对象

编辑：张卓辉
日期：2014/04/14
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
	//	Xxyz m_T;              //平移向量
	//	double m_drotxyz[3];            //旋转角
	//	double m_dRot[9];          //旋转矩阵
};

/*******************************************************
函数名：  read3DData_Xxyz(vector<Xxyz> &opv, char cpath[])
功能说明： 从文件里读入坐标

参数1：opv          <out>             待输出的坐标(文件格式为，第一行为点的数量；从第二行开始，每行的数据格式：点名、空格、X坐标、空格、Y坐标、空格、Z坐标)
参数2：cpath                         保存路径
参数3：
参数4：
参数5：
参数6：
参数7：
参数8：
参数9：
参数10：
返回值：无

编辑：张卓辉
日期：2016/04/20
*******************************************************/
BASECLASS_SET void read3DData_Xxyz(vector<Xxyz> &opv, char cpath[]);

/*******************************************************
函数名：  read3DData_CObjectPoints(vector<CObjectPoints> &opv, char cpath[])
功能说明： 从文件里读入坐标

参数1：opv          <out>             待输出的坐标(文件格式为，第一行为点的数量；从第二行开始，每行的数据格式：点名（char*）、空格、X坐标、空格、Y坐标、空格、Z坐标)
参数2：cpath                         保存路径
参数3：
参数4：
参数5：
参数6：
参数7：
参数8：
参数9：
参数10：
返回值：无

编辑：张卓辉
日期：2016/04/20
*******************************************************/
BASECLASS_SET void read3DData_CObjectPoints(vector<CObjectPoints> &opv, char cpath[]);

#endif
