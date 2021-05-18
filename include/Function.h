
#define Function_API _declspec(dllexport)

#ifdef Function_API
#else
#define Function_API _declspec(dllexport)
#endif

#include "BaseCla.h"
//#include "SamePoint.h"
//#include "ScaleBar.h"
//#include "ObjectPoint.h"
//#include "Camera.h"
//#include "PhotoImage.h"
//#include "ImagePoint_N.h"

#define byte unsigned char
/****************************************************
函数名：HouFangJiaoHui(int nCounterPic, int* pnIndex1, double *pdUnkn1, double **pData, double df, bool bBiaoDing, double dstop = 0.001)
功能：  后方交会求解外方位元素

参数1：nCounterPic   相片的数量
参数2：pnIndex1      每张相片上像点的数量
参数3：pdUnkn1  <in\out>     外方位元素初值
Xs = pdUnkn1[6*i];
Ys = pdUnkn1[6*i+1];
Zs = pdUnkn1[6*i+2];

deg_a = pdUnkn1[6*i+3];
deg_w = pdUnkn1[6*i+4];
deg_k = pdUnkn1[6*i+5];

相机参数：
x0 = pdUnkn1[6*nPic ];
y0 = pdUnkn1[6*nPic +1];
f = pdUnkn1[6*nPic +2];  //为正数

k1 = pdUnkn1[6*nPic +3];
k2 = pdUnkn1[6*nPic +4];
k3 = pdUnkn1[6*nPic +5]; 

p1 = pdUnkn1[6*nPic +6];
p2 = pdUnkn1[6*nPic +7];

ap1 = pdUnkn1[6*nPic +8];
ap2 = pdUnkn1[6*nPic +9];
参数4：pData         像点、物方点坐标 
参数5：df			 相机焦距（初值）
参数6：bBiaoDing     是否标定相机
参数7：dstop		 收敛精度

返回值：

编写人：张卓辉
编写日期：2013/07/26

***************************************************/
Function_API double HouFangJiaoHui(int nCounterPic, int* pnIndex1, double *pdUnkn1, double **pData, double df, bool bBiaoDing, double dstop = 0.001);
 
/****************************************
FunctionDllInitial()
功能： 初始化动态库


参数1：
参数2：
参数3：
参数4：
参数5：

返回值: 无

作者：张卓辉
日期：2017/01/03
****************************************/
Function_API void FunctionDllInitial();
/*******************************************************
函数名：HouFangJiaoHui(int nCounterPic, vector<CSamePoint> &dPoiArr, int* pnIndex1, double *pdUnkn1, double df, double dErBeiPixSize)
功能说明：后方交会求外方位元素初值

参数1：nCounterPic                相片的数量
参数2：pnIndex1                   每张相片上像点的数量
参数3：pdUnkn1       <out>        外方位元素初值
参数4：dPoiArr        <in>        点对儿(前三个物方坐标，后三个像点坐标)
参数5：df                         焦距值（正数）
参数6：dErBeiPixSize              相机像素尺寸的二倍值 

返回值：

编辑：张卓辉
日期：2014/08/11
*******************************************************/
Function_API bool HouFangJiaoHui(int nCounterPic, vector<CSamePoint> &dPoiArr, int* pnIndex1, double *pdUnkn1, double df, double dErBeiPixSize);


/****************************************************
函数名：GetZuoBiaoZhuanHuanCanShu(vector<CSamePoint> GGPt, double dResult[])
功能：  求解坐标系转换的参数（公共点坐标转换）计算由X1变换到X2的参数

参数1：GGPt 公共点在坐标系1下的坐标,在A中；公共点在坐标系2下的坐标，在B中
参数2： 
参数3：dResult 返回值，内容及存储顺序依次为：
λ                                            比例系数
Xs,Ys,Zs                                      平移向量
δωκ                                        三个旋转角（旋转循序为z，y，x）  
a1 a2 a3                                      旋转矩阵
b1 b2 b3
c1 c2 c3

七个参数对应的精度值，5个数,分别为：
比例系数      1个
三个旋转角    3个
单位权中误差  1个（计算结果的好坏，就看这个数就行了，正确情况下为小于0.5（这个数也和三维点的测量精度有关，三维点精度越高，这个数越小））

参数4：

返回值：

编写人：张卓辉
编写日期：2013/07/26

***************************************************/
Function_API bool GetZuoBiaoZhuanHuanCanShu(vector<CSamePoint> GGPt, double dResult[]);
/****************************************************
函数名：GetZuoBiaoZhuanHuanCanShu(CObjectPointsVect X1, CObjectPointsVect X11, double dResult[])
功能：  求解坐标系转换的参数（公共点坐标转换）计算由X1变换到X2的参数

参数1：x1 公共点在坐标系1下的坐标
参数2：x2 公共点在坐标系2下的坐标
参数3：dResult 返回值，内容及存储顺序依次为：
λ                                            比例系数
Xs,Ys,Zs                                      平移向量
δωκ                                        三个旋转角（旋转循序为z，y，x）  
a1 a2 a3                                      旋转矩阵
b1 b2 b3
c1 c2 c3
参数4：

返回值：

编写人：张卓辉
编写日期：2013/07/26

***************************************************/
Function_API int GetZuoBiaoZhuanHuanCanShu(CObjectPointsVect &X1, CObjectPointsVect &X11, double dResult[]); 

/****************************************************
函数名：GetZuoBiaoZhuanHuanCanShu(double* X1, double* X11, int nc,  double dResult[])
功能：  求解坐标系转换的参数（公共点坐标转换）计算由X1变换到X2的参数

参数1：x1 公共点在坐标系1下的坐标
参数2：x2 公共点在坐标系2下的坐标
参数3：nc 公共点的对数（有几对公共点）
参数4：px1[3] 公共点在坐标系1中所有点的中心坐标（1/n∑Xi, 1/n∑Yi, 1/n∑Zi）
参数5：px2[3] 公共点在坐标系2中所有点的中心坐标（1/n∑Xi, 1/n∑Yi, 1/n∑Zi）
参数6：dResult 返回值，内容及存储顺序依次为：
λ                                            比例系数
Xs,Ys,Zs                                      平移向量
δωκ                                        三个旋转角（旋转循序为z，y，x）  
a1 a2 a3                                      旋转矩阵
b1 b2 b3
c1 c2 c3


返回值：

编写人：张卓辉
编写日期：2013/07/26

***************************************************/
Function_API int GetZuoBiaoZhuanHuanCanShu(double* X1, double* X11, int nc, double px1[3], double px2[3],double dResult[]);
 
/****************************************************
函数名：GetXuanZhuanJvZhen(double abc[], double dM[])
功能：  输入三个旋转角，返回旋转矩阵

参数1：abc[]     δωκ            三个旋转角（旋转循序为z，y，x）
参数2：dM 旋转矩阵

a1 a2 a3                                      旋转矩阵
b1 b2 b3
c1 c2 c3


返回值：

编写人：张卓辉
编写日期：2013/07/31

***************************************************/
Function_API void GetXuanZhuanJvZhen(double abc[], double dM[]);


/********************************************
void OrientationCalculate(vector<CSamePoint> & dPoiArr, vector<CScaleBar> vecScaleBar, double dBack[])
功能： 求解定向参数(如果没有基准尺，则是相对基线为1000mm的定向模型)

参数1	sp				同名点集合
参数2   vecScaleBar     基准尺
参数3   dBack          返回的数据
Xs,Ys,Zs M δωκ         迭代初始值 15个数 0 ~14
rms                    最终定向结果的中误差 1个    15 
Xs,Ys,Zs δωκ M 模型的相对比例关系 15个   16 ~ 30
Xs,Ys,Zs 模型的真实比例关系。 3个     31 ~ 33
ms                      定向精度      34 （现在还没有添加精度评估）

参数4  dErBeiPixSize    像素尺寸二倍的值(默认值为0.02)

返回值：

编写人：张卓辉
日期：2012/09/04
********************************************/
Function_API bool OrientationCalculate(vector<CSamePoint> & dPoiArr, vector<CScaleBar> &vecScaleBar, double dBack[], double dErBeiPixSize = 0.02);


/********************************************
函数名：GetCorrespondingEpipolarLineImage(CCamera1 & lCam, CCamera1 & rCam, int w, int h, float ** pfRowImagPiexL, float ** pfRowImagPiexR, byte *pbyEpipolarLineImageL, byte *pbyEpipolarLineImageR)
功能：  生成核线影像，影像上的同名点在同一行或列

参数1：lCam						<in>	左右相机文件（lCam.m_dRotm/rCam.m_dRotm旋转矩阵参数需要被赋值）
参数2：rCam						<in>
参数3：w						<in>	图像宽高
参数4：h						<in>
参数5：pfRowImagPiexL           <out>   左、右核线影像上的像点，对应于原始图像上的像素坐标（坐标系原点在左上角）		（pfRowImagPiexL[i][0]、pfRowImagPiexL[i][1]代表核线影像上，第i个像素点所对应的原始图像上像素点的x、y坐标）
										（pfRowImagPiexL[i][0]、pfRowImagPiexL[i][1]代表核线影像上，第i个像素点所对应的原始图像上像素点的x、y坐标）
										（pfRowImagPiexL[i][2]、pfRowImagPiexL[i][3]代表核线影像上，第i个像素点所对应的原始图像上纠正后的像点x、y坐标）

参数6：pfRowImagPiexR           <out>
参数7：pbyrowL                  <out>    左、右相机原始影像数据 
参数8：pbyrowR					<out>
参数9：pbyEpipolarLineImageL    <out>    生成的核线影像数据
参数10：pbyEpipolarLineImageR    <out>    生成的核线影像数据

还回值：1=核线沿X方向、2=核线沿Y方向、0=核线计算失败。

编写人：张卓辉
编写日期： 2019/11/21
********************************************/
Function_API byte GetCorrespondingEpipolarLineImage(CCamera1 & lCam, CCamera1 & rCam, int w, int h, float ** pfRowImagPiexL, float ** pfRowImagPiexR, byte *pbyrowL = NULL, byte *pbyrowR = NULL, byte *pbyEpipolarLineImageL = NULL, byte *pbyEpipolarLineImageR = NULL);



/********************************************
函数名：SameNameEpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *lpabc,, double *lpabc)
功能： 计算得到核线方程式的系数（在左相片上选一个点，分别计算在Left相片和Right相片上的核线方程)

参数1：lCam          左右相机文件
参数2：
参数3：pdx1y1z1      像空系S1下的一个坐标
参数4：lpabc          左相片核线方程的系数和常数项，是个返回值 依次为a、b、c 分别为方程的系数 ax+by+c =0;
参数5：rpabc          右相片核线方程的系数和常数项，是个返回值 依次为a、b、c 分别为方程的系数 ax+by+c =0;

还回值：无
********************************************/
Function_API void SameNameEpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *lpabc, double *rpabc);



/*****************************************************************
void HorizontalParallax(CCamera1 lCam, CCamera1 rCam, float fDistanceRange[], float fParallax[])
功能：  计算左右视差（使用方法：左相片上的像点x坐标，减去最小视差和最大视差，就得到就得到右相片上同名点的x坐标范围）（基线沿x方向，如果基线在y轴方向，则前面都换成y）


参数1：lCam							左右相机文件
参数2：rCam
参数3：fDistanceRange               目标物深度变化范围， fDistanceRange[0]=最近的距离、fDistanceRange[1]=最远的距离（两个距离值，都要是个正数,  单位：毫米）
参数4：fParallax                    视差范围（单位：像素）fParallax[0]=最近的距离的范围、fParallax[1]=最远的距离的范围
参数5：


返回值：无

作者：张卓辉
日期：2019/11/26--11：39：25
*****************************************************************/
Function_API void HorizontalParallax(CCamera1 lCam, CCamera1 rCam, float fDistanceRange[], float fParallax[]);

/********************************************
函数名：epipolarlineequation()
功能： 计算得到核线方程是的系数

参数1：lCam          左右相机文件
参数2： 
参数3：pdx1y1z1      像空系S1下的一个坐标
参数4：pabc          和线方程的系数和常数项，是个返回值 依次为a、b、c 分别为方程的系数 ax+by+c =0;
还回值：无
********************************************/
Function_API void EpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc);


/********************************************
函数名：EpipolarLineEquationEx(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc)
功能： 计算得到核线方程是的系数(计算的是Left相片上的点在Right相片上的核线方程)

参数1：lCam          左右相机文件(lCam.m_dRotm，旋转矩阵必须有值)
参数2：rCam          左右相机文件(rCam.m_dRotm，旋转矩阵必须有值) 
参数3：pdx1y1z1      像空系S1下的一个坐标
参数4：pabc          和线方程的系数和常数项，是个返回值 依次为a、b、c 分别为方程的系数 ax+by+c =0;
还回值：无
********************************************/
Function_API void EpipolarLineEquationEx(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc);


/****************************************************
函数名：XiangGuanXiShu(byte pbyValue1[], byte pbyValue2[], byte byTemplateSize, double & dBackValue)
功能：  计算两个数组的相关系数

参数1： pbyValue1 数组1，模板1的数据
参数2： pbyValue2 数组2，模板2的数据
参数3： byTemplateSize 模板的尺寸(模板宽度,模板必须是方形的)
参数4： dBackValue    返回值

返回值： 正确计算返回true or false

编写人：张卓辉
编写日期：2013/08/28

***************************************************/
Function_API bool XiangGuanXiShu(byte pbyValue1[], byte pbyValue2[], byte byTemplateSize, double & dBackValue);

/********************************************
函数名：XuanZhuanJiaoToJvZheng(double pdrX, double pdX, byte byxyz)
功能：由旋转角求旋转矩阵。

参数1：pdrX   三个旋转角，内容存储顺序为 (单位是弧度)
ψ，ω，Κ

参数2：pdX  <out>  旋转矩阵，内容存储顺序为
a1,a2,a3;
b1,b2,b3;
c1,c2,c3;

说明：以检验过

参数3：byxyz   输入旋转角的顺序，1：xyz（实际旋转顺序为：先x，后y,再后z）， 2：xyz（实际旋转顺序为：先z，后y,再后x） ， 3：zyz（实际旋转顺序为：先z，后y,再后z）    （默认为1   ）

还回值：无

编写人：张卓辉
编写日期： 2011/04/21 
********************************************/


 void Function_API XuanZhuanJiaoToJvZheng(double pdrX[], double result[], byte byxyz = 1);

 /****************************************************
 函数名：XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[])
 功能：  由旋转角转化成四元数

 参数1：dxyz		<in>			旋转角（弧度）
 参数2：dwxyz     <out>          四元数
 参数3：byxyz   输入旋转角的顺序，1：xyz（实际旋转顺序为：先x，后y,再后z）， 2：zyx（实际旋转顺序为：先z，后y,再后x） ， 3：zyz（实际旋转顺序为：先z，后y,再后z）（默认1）


 返回值：                    成功为true

 编写人：张卓辉
 编写日期：2014/01/08

 ***************************************************/
 bool Function_API XuanZhuanJiaotosiyuanshu(double dxyz[], double dwxyz[], byte byxyz = 1);


 /****************************************************
 函数名：XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[])
 功能：  由旋转矩阵转化成四元数

 参数1：dxyz		<in>			旋转矩阵()
 参数2：dwxyz     <out>          四元数
 参数3：


 返回值：                    成功为true

 编写人：张卓辉
 编写日期：2014/01/08

 ***************************************************/
 bool  Function_API XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[]);

 /****************************************************
 函数名：CreatRotationMatrix(double rmat[], double angle, byte xyz)
 功能：

 参数1：rmat		<in\out>			旋转矩阵()
 参数2：angle                旋转的角度(单位：弧度)
 参数3：xyz                  绕哪个轴旋转（0X轴、1Y轴、2Z轴）


 返回值：                    无

 编写人：张卓辉
 编写日期：2014/01/08

 ***************************************************/
 Function_API bool CreatRotationMatrix(double rmat[], double angle, byte xyz);

/********************************************
函数名：JiSuanSanGeXuanZhuanJiao(double **pdrX，double dResult[])
功能： 计算三个旋转角的值，根据pdrX的值计算，并将计算结果保存在 pdrX 中

参数1：pdrX  <in> 保存计算得到的外方位元素值，内容存储顺序为 
a1,a2,a3;
b1,b2,b3;
c1,c2,c3; 

参数2：dResult <out> ψ，ω，Κ
参数3：
参数4：
还回值：无

编写人：张卓辉
编写日期： 2011/04/20 
********************************************/
Function_API void JvZhengToXuanZhuanJiao(double **pdrX, double dResult[]);

/****************************************************
函数名：JvZhengToXuanZhuanJiao(double pdrX[], byte xyz)
功能：  从矩阵数据求旋转角

参数1：pdrX <in、out>   前9个是M 后3个是旋转角
参数2：xyz              输出的角度是按1：xyz:、还是2：zyx的旋转顺序、还是3：zyz的旋转顺序，默认1
参数3：
参数4：

返回值：

编写人：张卓辉
编写日期：2013/10/28

***************************************************/
Function_API bool JvZhengToXuanZhuanJiao(double pdrX[12], byte xyz = 1);

/****************************************************
函数名：ChangeAix(double dData[])
功能：  吧相机对中的一个相机，通过基准相机参数，转换到总坐标系下

参数1：dData <in/out> 
输入数据顺序：
Xs,Ys,Zs δωκ		基准相机的外参数 3个
Xs,Ys,Zs δωκ M   另一相机的模型的相对比例关系 15个

输出数据顺序：
Xs,Ys,Zs δωκ M   另一相机的转换后的外方位 15个

参数2：bUseMatrix 是否使用 另一相机的M 参数，如果否，
则根据δωκ算 M 的值
参数3：
参数4：

返回值：

编写人：张卓辉
编写日期：2013/10/28

***************************************************/
Function_API bool ChangeAix(double dData[], bool bUseMatrix = false);

/********************************************
函数名：QianFangJiaoHuiEx(double M[3][3], double S[3], CArray <double, double> &dPoiArr, double *XYZ)
功能： 前方交会公式，增强版（一次仅能计算一个像点对应的物方点）

参数1：dWaiFangWei      图像的外放为元素，每一行代表一个相机的外方位，Xs,Ys,Zs,ψ，ω，Κ
参数2：nCountCameras	相机数量
参数3：dPointCoor		同名点坐标 每一行代表一个点的同名数据，一行上的数据数，由nCountCameras决定，= 3*nCountCameras 存储顺序为像点的x、y、z；x、y、z。。。。
参数4：XYZ  物方点的坐标
参数5： 

说明：dWaiFangWei、dPointCoor两者之间图片的外方位和相应的像点的存储顺序是一致的
还回值：计算成功返回 TRUE

编写人：张卓辉
编写日期： 2011/04/18 
********************************************/
Function_API bool QianFangJiaoHuiEx(double **dWaiFangWei, int nCountCameras, double *dPointCoor, double XYZ[]);
/****************************************************
函数名：QianFangJiaoHuiEx(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool bKaiGuan[3], bool nindex[])
功能：   前方交会计算（支持多个点同时计算）(这个比QianFangJiaoHuiEx速度要快一点，它里面不进行求解旋转矩阵运算，而是在输入的时候，在doutArr
           里面已经将旋转矩阵的值付给了同名点，后面就直接使用旋转矩阵了)
//准备前方交会的数据 
//前方交会计算更多物方点数据 

参数1：doutArr                     同名点几何（它里面包含了每一个点所对应的外方位信息，每一个点都是纠正过的坐标,使用的是旋转矩阵，而不再是由旋转角算出矩阵之后再用旋转矩阵）
参数2：nPtindex                    doutArr中，每一个同名点的个数，数组
参数3：nPt                         一共有多少组同名点（多少个物方点）
参数4：pXYZ          <out>         保存计算出来的三维坐标
参数5：
参数6：


返回值：

编写人：张卓辉
编写日期：2014/01/09

***************************************************/
Function_API bool QianFangJiaoHuiEx2(vector<CCtrlDataSet> doutArr, int *nPtindex, int nPt, vector<CObjectPoints> &pXYZ);

/********************************************
函数名：QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu)
功能： 前方交会公式，求解物方点坐标；本公式仅适用于以共面方式定向后的解算，因为该方式默认以一个投影中心为
原点，其旋转矩阵为单位阵。

参数1：M               右片的旋转矩阵
参数2：S               右片的投影中心坐标
参数3：dPoiArr         同名点坐标 存储顺序为左像点的x、y、z;右像点的x、y、z
参数4：pXYZ      <out>      物方点的坐标,
参数5：nshu           参于计算的点的个数

还回值：计算成功返回 TRUE

编写人：张卓辉
编写日期： 2011/04/18 
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], vector<CSamePoint> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu);


/********************************************
函数名：QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, double *XYZ, int nshu)
功能： 前方交会公式，求解物方点坐标；本公式仅适用于以共面方式定向后的解算，因为该方式默认以一个投影中心为
原点，其旋转矩阵为单位阵。

参数1：M 右片的旋转矩阵
参数2：S 右片的投影中心坐标
参数3：dPoiArr 同名点坐标 存储顺序为左像点的x、y、z;右像点的x、y、z
参数4：**XYZ  物方点的坐标,它是nshu维，3列的矩阵
参数5： nshu 参于计算的点的个数

还回值：计算成功返回 TRUE

编写人：张卓辉
编写日期： 2011/04/18
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], vector<CSamePoint> &dPoiArr, double **XYZ, int nshu);

/********************************************
函数名：QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu)
功能： 前方交会公式，求解物方点坐标；本公式仅适用于以共面方式定向后的解算，因为该方式默认以一个投影中心为
原点，其旋转矩阵为单位阵。

参数1：M               右片的旋转矩阵
参数2：S               右片的投影中心坐标
参数3：dxyz_t          同名点坐标 存储顺序为左像点的x、y、z;右像点的x、y、z
参数4：Pt_xyz          物方点的坐标
参数5：

还回值：计算成功返回 TRUE

编写人：张卓辉
编写日期： 2011/04/18
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], double dxyz_t[6], Xxyz &Pt_xyz);

/*******************************************************
函数名：PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
功能说明：点面交会求物方点

参数1：Images                      像点文件几何、外参数 
参数2：fPlane                      平面方程                         
参数3：vectPoint        <out>      物方点存储数组
参数4：df                          焦距 
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint, double df);


/*******************************************************
函数名：PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<Xxyz>& vectPoint)
功能说明：点面交会求物方点

参数1：Images                      像点文件集合
参数2：Cam                         相机文件（外方位要赋值）
参数3：fPlane                      平面方程组
参数4：vectPoint        <out>      物方点存储数
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, XPlane fPlane, vector<Xxyz>& vectPoint);
/*******************************************************
函数名：PointPlaneJiaoHui(CImagePoint_N pt, double dxyzabc[], FaxPlane fPlane, CObjectPoints &opt, double df)
功能说明：

参数1：xpt           <in>            像点
参数2：dxyzabc       <in>            外方位 
共12个数，存储顺序为：
前三个，投影中心坐标（Xs,Ys,Zs）
后九个为旋转矩阵，a1 a2 a3
b1 b2 b3
c1 c2 c3

参数3：fPlane        <in>            平面方程
参数4：opt           <out>           计算出的物方点坐标
参数5：df            <in>            焦距(正数)
参数6：

返回值：

编辑：张卓辉
日期：2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(CImagePoint_N pt, double dxyzabc[], FaxPlane fPlane, CObjectPoints &opt, double df);


/*******************************************************
函数名：PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
功能说明：点面交会求物方点

参数1：Images                      像点文件集合 
参数2：Cam                         相机文件（外方位要赋值） 
参数3：fPlane                      平面方程组  
参数4：vectPoint        <out>      物方点存储数
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, FaxPlane fPlane, vector<CObjectPoints>& vectPoint);

/*******************************************************
函数名：PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
功能说明：点面交会求物方点

参数1：Images                      像点文件集合
参数2：Cam                         相机文件（外方位要赋值）
参数3：fPlane                      平面方程组
参数4：vectPoint        <out>      物方点存储数
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, XPlane fPlane, vector<CObjectPoints>& vectPoint);
/****************************************************
函数名：FeatureExtractAccuracy(int nPic, vector<CPhotoImage> veImages, vector<CObjectPoints> CtrlPoints, double &dAccuracy)
功能：  定向之后，求每个像点的提取精度（用控制点反算像点法），（本方法一次只能处理一个相机的图片，因为每次只能输入一个相机焦距dF）

参数1：nCounterPic   相片的数量
参数2：veImages      每张相片上像点的数据
参数3：CtrlPoints    物方点坐标（控制点坐标） 
参数4：dF            相机 
参数5：dAccuracy	 所有像点的平均精度


返回值：

编写人：张卓辉
编写日期：2013/12/3

***************************************************/
Function_API bool FeatureExtractAccuracy(int nPic, vector<CPhotoImage>& veImages, vector<CObjectPoints> CtrlPoints, double dF, double &dAccuracy);


/****************************************************
函数名：bool SingleCameraMultPicOrientationCalculate(int nPic, vector<CPhotoImage> &veImages, vector<CObjectPoints> &CtrlPoints, vector<CScaleBar> &vecScaleBar, CCamera1 Cam,double &dAccuracy, bool bChangeCam)
功能：  单相机测量定向（单相机多张图像测量,支持有控制数据的定向，同时也支持有基准尺的相对定向）
（如果 CtrlPoints 中有四个以上的值，则根据控制点定向）
参数1：nPic                  图像数量
参数2：veImages              像点文件集
参数3：CtrlPoints            控制点数据
参数4：vecScaleBar           基准尺文件
参数5 CCamera1 Cam           相机文件
参数6：dAccuracy             定向精度
参数7：pXYZ       <out>      计算得到的三维物方点坐标
参数8：BPra                  平差定向参数
参数9：bChangeCam            是否迭代相机文件里的内容（是否改变内参数）(有默认值，默认是改变的)
 
返回值：

编写人：张卓辉
编写日期：2014/01/08

***************************************************/
Function_API bool SingleCameraMultPicOrientationCalculate(int nPic, vector<CPhotoImage> &veImages, vector<CObjectPoints> &CtrlPoints, vector<CScaleBar> &vecScaleBar
														  , CCamera1& Cam,/*double &dAccuracy, */vector<CObjectPoints> &pXYZ, BundlePra &BPra, bool bChangeCam);



/*******************************************************
函数名：AutoMatchEx(vector<CPhotoImage> &veImages, CCamera1& Cam)
功能说明： 自动匹配（这时的图像都定过向了//、、、像点都定过向了）

参数1：veImages                              像点数据（每个点的匹配状态要标记为false）
参数2：Cam                                   
参数3：distancestreshold                     点到直线的距离阈值（匹配时，同名点到直线的距离阈值，一个像素的大小）
参数4：pWuXYZ                                匹配中生成的物方点
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/09/25
*******************************************************/
Function_API int AutoMatchEx(vector<CPhotoImage> &veImages, CCamera1& Cam, double distancestreshold, vector<CObjectPoints> & pWuXYZ);
/*******************************************************
函数名：AutoMatch2Ex(vector<CPhotoImage> &veImages, CCamera1& Cam)
功能说明： 自动匹配（这时的图像都定过向了//、、、像点都定过向了）

参数1：veImages                              像点数据（每个点的匹配状态要标记为false）
参数2：Cam                                   
参数3：distancestreshold                     点到直线的距离阈值（匹配时，同名点到直线的距离阈值，一个像素的大小）
参数4：pWuXYZ                                匹配中生成的物方点
参数5：nHadMatch                             已经匹配过的图像有多少张（主要是为了显示匹配进度） 
参数6：

返回值：

编辑：张卓辉
日期：2014/09/25
*******************************************************/
Function_API int AutoMatch(vector<CPhotoImage> &veImages, CCamera1& Cam, double distancestreshold, vector<CObjectPoints> & pWuXYZ, int &nHadMatch);
/****************************************************
函数名：BundleAjustment(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, double dF, bool bKaiGuan[3], double &dJingDu)
功能：  光束法平差（完成有控制点的定向计算，同时可以控制标定、定向、整体平差）(计算的结果定向的都保存在了veImages中，内参数的保存到了
Cam中，到时候在指定的变量中提取就行了)

参数1：veImages                    每张图像的想点数据（可以使所有的图片，参与运算或不参与的）
参数2：pXYZ                        控制点三维坐标
参数3：dF                          焦距
参数4：bKaiGuan                    设置计算的内容bKaiGuan[0] == true则定向计算，bKaiGuan[2] == true则修正控制数据，bKaiGuan[1] == true则标定内参数
参数5：nindex                      参与平差计算的图像的标记(数组大小等于图像的数量)（可以不是所有的图像都参与的）
参数6：dstop                       停止条件（默认0.00002）
参数7：bFullBundle                 是否完全平差（所有点参与（ture）、只有CODE中心点参与（false）,如果这一项为true，则nindex可以为空数组，后面不用）
参数8：pWpWuFangIndexuFang         物方点中CODE、CDOE编码、单点的数量信息  
参数9：BBack                       返回值结构体


返回值：

编写人：张卓辉
编写日期：2014/01/09

***************************************************/
Function_API bool BundleAjustment4(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam/*, bool *bKaiGuan, bool *nindex*/, double dstop, BundlePra &BPra, bool bFullBundle = false, int *pWuFangIndex = NULL, BundleBack *BBack = NULL);
Function_API bool BundleAjustment4_BD(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam/*, bool *bKaiGuan, bool *nindex*/, double dstop, BundlePra &BPra, bool bFullBundle = false, int *pWuFangIndex = NULL, BundleBack *BBack = NULL);
/*******************************************************
函数名：CodeNarget(vector<CPhotoImage> &veImages, CCamera1& Cam, vector<CObjectPoints> & pWuXYZ)
功能说明： 计算CODE周围的编码点

参数1：veImages                              像点数据（每个点的匹配状态要标记为false）
参数2：dF                                    相机焦距（正数）
参数3：pWuXYZ                                匹配中生成的物方点
参数4：
参数5：
参数6：

返回值：     匹配到的点的数量

编辑：张卓辉
日期：2014/09/25
*******************************************************/
Function_API int CodeNarget(vector<CPhotoImage> &veImages, double dF, vector<CObjectPoints> & pWuXYZ);
 


//////////////////////////////////////////////////////////////////////////
/********************************************
函数名：CorrectImagPointCoordinate(CPicture pic)
功能：  依据相片的纠正参数，纠正像点的坐标

参数1：Cam            相片的纠正参数
参数2：veImage        相片对象
参数3：
参数4：
还回值：无

编写人：张卓辉
编写日期： 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 & Cam, vector<CPhotoImage>& veImage);


/********************************************
函数名：CorrectImagPointCoordinate(CPicture pic)
功能：  依据相片的纠正参数，纠正像点的坐标

参数1：Cam            相片的纠正参数
参数2：veImage        想点数据集合
参数3：
参数4：
还回值：无

编写人：张卓辉
编写日期： 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 & Cam, vector<CImagePoint_N>& veImage);

/********************************************
函数名：CorrectImagPointCoordinate(CCamera1 &Cam, CImagePoint_N& pt)
功能：  依据相片的纠正参数，纠正像点的坐标

参数1：Cam            相片的纠正参数
参数2：pt            想点数据
参数3：
参数4：
还回值：无

编写人：张卓辉
编写日期： 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 &Cam, CImagePoint_N& pt);
 
/****************************************************
函数名：QianFangJiaoHui(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool bKaiGuan[3], bool nindex[])
功能：   前方交会计算（他要在内部完成数据整理，数据准备，将多个相片上的点计算出来，是多张相片上的点）
//准备前方交会的数据 
//前方交会计算更多物方点数据 

参数1：veImages                    每张图像的想点数据（可以使所有的图片，参与运算或不参与的）
参数2：pXYZ          <out>         保存计算出来的三维坐标
参数3：Cam                         相机文件
参数4：nindex                      参与计算的图像的标记(数组大小等于图像的数量,它和 veImages 对应)（可以不是所有的图像都参与的）
参数5：bCodeOnly                   是否只计算编码点（就是不计算一般的单点）
参数6：bOrentainUse                在定向过程中使用，（这个过程中，不使用纠正过的像点坐标），如果为false则是一般的应用，他在内部使用纠正过的像点坐标


返回值：

编写人：张卓辉
编写日期：2014/01/09

***************************************************/
Function_API bool QianFangJiaoHui(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool nindex[], bool bCodeOnly, bool bOrentainUse = true);


/****************************************************
函数名：SignImaOrientation(vector<CSamePoint> &dPoiArr, double dPixelSizex, double dBack[])
功能：  单张图像的后方交会

参数1：dPoiArr    数据,其中每一个同名点对象，赋值对应方式如下

spt.m_dAX = pobj->m_dX;  //物方点
spt.m_dAY = pobj->m_dY;
spt.m_dAZ = pobj->m_dZ;

spt.m_dBX = por->m_dx; //像点（纠正后的像点坐标）
spt.m_dBY = por->m_dy;
spt.m_dBZ = -dF;

参数2：dPixelSizex        像素尺寸
参数3：dBack       in/out     内外方位元素，大小为16个数
作为输入参数，顺序为
前六个数赋值为0
dBack[0] ~dBack[5]      0

后面十个数
dBack[6] =Cam.m_dx0;
dBack[7] =Cam.m_dy0; 
dBack[8] =Cam.m_dF;

dBack[9] = Cam.m_dK1;
dBack[10] =Cam.m_dK2;
dBack[11] =Cam.m_dK3;
dBack[12] =Cam.m_dP1;
dBack[13] =Cam.m_dP2;
dBack[14] =Cam.m_db1;
dBack[15] =Cam.m_db2;



作为输出参数，顺序为
前六个数
dBack[0] ~dBack[5]     
Xs,Ys,Zs
a,w,b

dBack[6] = 定向精度

后面全为零


参数4：
参数5：

返回值：

编写人：张卓辉
编写日期：2014/01/09

***************************************************/
Function_API bool SignImaOrientation(vector<CSamePoint> &dPoiArr, double dPixelSizex, double dBack[]);

/*******************************************************
函数名：GetImageResidual(CCtrlDataSet& doutArr, CObjectPoints oPt, double drxy[])
功能说明：计算单个物方点所对应的像点残差

参数1：
参数2：
参数3：drxy                  返回x、y两个方向上的平均残差
参数4：
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/09/28
*******************************************************/
Function_API bool GetImageResidual(CCtrlDataSet& doutArr, CObjectPoints oPt, double drxy[]);
/****************************************************
函数名：FromObjectToImagPoint(double dXsYsZs[3], double dRot[9], double df, double dXYZ[3], double &dx, double &dy)
功能：  由物方反算的像点坐标

参数1：dXsYsZs            相片的外方位-投影中心坐标
参数2：dRot               相片的外方位-旋转矩阵
9个数，依次为：
a1,a2,a3;
b1,b2,b3;
c1,c2,c3; 

参数3：df                 相机焦距 (正数值，不要取负号)
参数4：dXYZ               物方点坐标
参数5：dx                 物方点对应的像点x坐标值
参数6：dy                 物方点对应的像点y坐标值
返回值：

编写人：张卓辉
编写日期：2013/12/03

***************************************************/
Function_API void FromObjectToImagPoint(double dXsYsZs[3], double dRot[9], double df, double dXYZ[3], double &dx, double &dy);

/*******************************************************
函数名：FromObjectToImagPoint(CCamera1 cam, CObjectPoints opt, CImagePoint_N pt)
功能说明： 由物方点反求像点（纠正后的像点）

参数1：cam                     外方位
参数2：opt                     物方点  
参数3：pt       <out>          像点
参数4：
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/06/27
*******************************************************/
Function_API void FromObjectToImagPoint(CCamera1 cam, CObjectPoints opt, CImagePoint_N &pt);

/*******************************************************
函数名：BackCodePoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ)
功能说明：以物方点为基础反算所对应的像点，仅针对CODE点（这时候输入的物方点，最好只有CODE点，这样速度会快一点）

参数1：veImages                像点坐标数据 
参数2：Cam                     相片的宽高，像元尺寸   
参数3：pWuXYZ				   物方点的三维坐标，（最好只有CODE点的）
参数4：dxyYuZhi                反算的像点坐标与原坐标之间的坐标差值，在两个方向上的距离阈值（按三个像素距离即可）    
参数5：
参数6：

返回值：                       反算新得到的点的数量

编辑：张卓辉
日期：2014/11/05
*******************************************************/
Function_API int BackCodePoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ, double dxyYuZhi);


//////////////////////////////////////////////////////////////////////////
//完全整体迭代

/****************************************************
函数名：BundleAjustment5(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, double dF, bool bKaiGuan[3], double &dJingDu)
功能：  光束法平差（完成有控制点的定向计算，同时可以控制标定、定向、整体平差）(计算的结果定向的都保存在了veImages中，内参数的保存到了
Cam中，到时候在指定的变量中提取就行了)

参数1：veImages                    每张图像的想点数据（可以使所有的图片，参与运算或不参与的）
参数2：pXYZ                        控制点三维坐标
参数3：Cam                         
参数4：dstop                      停止条件（默认0.00002）
参数5：BPra                       参与平差运行参数
参数6：bFullBundle                是否完全平差（所有点参与（ture）、只有CODE中心点参与（false）,如果这一项为true，则nindex可以为空数组，后面不用）
参数7：BBack                      平差结果返回值
参数8：               


返回值：

编写人：张卓辉
编写日期：2014/01/09

***************************************************/
Function_API bool BundleAjustment5(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, double dstop, BundlePra &BPra, bool bFullBundle, BundleBack *BBack);


/*******************************************************
函数名：BackCodeNagetPoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ)
功能说明：以物方点为基础反算所对应的像点，仅针对CODE点（这时候输入的物方点，最好只有CODE点，这样速度会快一点）

参数1：veImages                像点坐标数据 
参数2：Cam                     相片的宽高，像元尺寸   
参数3：pWuXYZ				   物方点的三维坐标，（CODE点的三维坐标要排在最前面，其后面才是编码点）
参数4：dxyYuZhi                反算的像点坐标与原坐标之间的坐标差值，在两个方向上的距离阈值（按三个像素距离即可）    
参数5：nCode                   物方点中CODE点的数量
参数6：

返回值：                       反算新得到的点的数量

编辑：张卓辉
日期：2014/11/05
*******************************************************/
Function_API int BackCodeNagetPoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ, double dxyYuZhi, int nCode);









/****************************************************
函数名：CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve)
功能：  计算相机测量坐标系到机器人坐标系的转换参数

参数1：robat_Tr_Rmat		<in>		 机器人的坐标和旋转角（每一组12个数，前三个为xyz坐标，后九个是旋转矩阵）
参数2：cam_Tr_Rmat          <in>         相机的参数（每一组12个数，前三个为xyz坐标，后九个是旋转矩阵）
参数3：cam_To_robat         <out>        相机到机器人工具坐标系的转换参数
参数4：reserve                           保留位

返回值：                    无

编写人：张卓辉
编写日期：2014/01/08

***************************************************/
Function_API bool CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve = 0);

/****************************************************
函数名：CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve)
功能：  计算相机测量坐标系到机器人坐标系的转换参数

参数1：robat_Tr_Rmat		<in>		 机器人的坐标和旋转角（每一组12个数，前三个为xyz坐标，后九个是旋转矩阵）
参数2：cam_Tr_Rmat          <in>         相机的参数（每一组12个数，前三个为xyz坐标，后九个是旋转矩阵）
参数3：byT                  <in>         平移数量
参数4：byR                               旋转数量
参数5：cam_To_robat         <out>        外参数
参数6：reserve                           保留位

返回值：                    无

编写人：张卓辉
编写日期：2014/01/08

***************************************************/
Function_API bool CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], byte byT, byte byR, double cam_To_robat[], byte reserve);
 

/*****************************************************************
bool RotationMatrixToRotatingVector(double RotM[], double RotV[])
功能：//利用罗德里格斯变换将旋转矩阵转换为旋转向量和旋转向量模长


参数1：RotM           <in>              旋转矩阵a1,a2,a3,b1,b2,b3 ,c1,c2,c3
参数2：RotV           <out>             旋转向量（x、y、z）（单位化的向量）和模长，四个数
参数3：
参数4：
参数5：


返回值：成功返回true

作者：张卓辉
日期：2019/08/28--22：53：46
*****************************************************************/

Function_API bool RotationMatrixToRotatingVector(double RotM[], double RotV[]);

/****************************************************
bool SiyuanshutoXuanZhuanJvZhen(double dsiyuanshu[], double dR_[])
功能：  由四元数转化成旋转矩阵

参数1：dsiyuanshu		<in>			四元数(w + a*i + b*j + c*k),dsiyuanshu中依次为w,a,b,c
参数2：dR_     <out>          旋转矩阵
参数3：


返回值：                    成功为true

编写人：张卓辉
编写日期：2014/01/08

***************************************************/
Function_API bool SiyuanshutoXuanZhuanJvZhen(double dsiyuanshu[], double dR_[]);


/****************************************************
bool SiyuanshutoXuanZhuanJvZhen(XVector v1, XVector v2, double dsiyuanshu[])
功能：  计算由向量v2，转到向量v1所对应的四元数（旋转矩阵）

参数1：v1		<in>			目标向量(单位向量)
参数2：v2       <in>            转动向量(单位向量)
参数3：dsiyuanshu      <out>	四元数(w + a*i + b*j + c*k),dsiyuanshu中依次为w,a,b,c


返回值： 无

编写人：张卓辉
编写日期：2014/01/08

***************************************************/
Function_API void VectorRotateToVector(XVector v1, XVector v2, double dsiyuanshu[]);


/*******************************************************
函数名：ImagePtToObjectPt(CImagePoint_N imag_pt, CCamera1 cam, double dZ, CObjectPoints &ob_out)
功能说明：由像点坐标计算所对应的三维点坐标，这里有一个前提，就是已知Z坐标分量；只需要计算X,Y的值

参数1：imag_pt             输入的像点坐标，已经完成想点坐标纠正后的像点
参数2：cam                 相机文件对象（它里面要包含外参数信息）
参数3：dZ					像点信息
参数4：ob_out              物方点的坐标（已经去掉设站坐标了）
参数5：
参数6：

返回值：

编辑：张卓辉
日期：2014/1/6
*******************************************************/
Function_API bool ImagePtToObjectPt(CImagePoint_N imag_pt, CCamera1 cam, double dZ, CObjectPoints &ob_out);


/****************************************************
函数名：CameraToRobatMode_C_L(XCameraPos CmaRtoCamL, XCameraPos CmaRtoBord, XCameraPos bordtoRobat, XCameraPos &CmatoRobat)
功能：  合成相机到机器人的转换参数

参数1：CmaRtoCamL		<in>		     右相机的外参数
参数2：CmaRtoBord       <in>             相机在标定板坐标系下的外参数
参数3：bordtoRobat      <in>             标定板到相机的转换参数
参数3：CmatoRobat      <in>             标定板到相机的转换参数

返回值：                    无

编写人：张卓辉
编写日期：2016/06/08

***************************************************/
Function_API bool CameraToRobatMode_C_L(XCameraPos CmaRtoCamL, XCameraPos CmaRtoBord, XCameraPos bordtoRobat, XCameraPos &CmatoRobat);