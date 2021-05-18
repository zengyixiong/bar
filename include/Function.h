
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
��������HouFangJiaoHui(int nCounterPic, int* pnIndex1, double *pdUnkn1, double **pData, double df, bool bBiaoDing, double dstop = 0.001)
���ܣ�  �󷽽�������ⷽλԪ��

����1��nCounterPic   ��Ƭ������
����2��pnIndex1      ÿ����Ƭ����������
����3��pdUnkn1  <in\out>     �ⷽλԪ�س�ֵ
Xs = pdUnkn1[6*i];
Ys = pdUnkn1[6*i+1];
Zs = pdUnkn1[6*i+2];

deg_a = pdUnkn1[6*i+3];
deg_w = pdUnkn1[6*i+4];
deg_k = pdUnkn1[6*i+5];

���������
x0 = pdUnkn1[6*nPic ];
y0 = pdUnkn1[6*nPic +1];
f = pdUnkn1[6*nPic +2];  //Ϊ����

k1 = pdUnkn1[6*nPic +3];
k2 = pdUnkn1[6*nPic +4];
k3 = pdUnkn1[6*nPic +5]; 

p1 = pdUnkn1[6*nPic +6];
p2 = pdUnkn1[6*nPic +7];

ap1 = pdUnkn1[6*nPic +8];
ap2 = pdUnkn1[6*nPic +9];
����4��pData         ��㡢�﷽������ 
����5��df			 ������ࣨ��ֵ��
����6��bBiaoDing     �Ƿ�궨���
����7��dstop		 ��������

����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/07/26

***************************************************/
Function_API double HouFangJiaoHui(int nCounterPic, int* pnIndex1, double *pdUnkn1, double **pData, double df, bool bBiaoDing, double dstop = 0.001);
 
/****************************************
FunctionDllInitial()
���ܣ� ��ʼ����̬��


����1��
����2��
����3��
����4��
����5��

����ֵ: ��

���ߣ���׿��
���ڣ�2017/01/03
****************************************/
Function_API void FunctionDllInitial();
/*******************************************************
��������HouFangJiaoHui(int nCounterPic, vector<CSamePoint> &dPoiArr, int* pnIndex1, double *pdUnkn1, double df, double dErBeiPixSize)
����˵�����󷽽������ⷽλԪ�س�ֵ

����1��nCounterPic                ��Ƭ������
����2��pnIndex1                   ÿ����Ƭ����������
����3��pdUnkn1       <out>        �ⷽλԪ�س�ֵ
����4��dPoiArr        <in>        ��Զ�(ǰ�����﷽���꣬�������������)
����5��df                         ����ֵ��������
����6��dErBeiPixSize              ������سߴ�Ķ���ֵ 

����ֵ��

�༭����׿��
���ڣ�2014/08/11
*******************************************************/
Function_API bool HouFangJiaoHui(int nCounterPic, vector<CSamePoint> &dPoiArr, int* pnIndex1, double *pdUnkn1, double df, double dErBeiPixSize);


/****************************************************
��������GetZuoBiaoZhuanHuanCanShu(vector<CSamePoint> GGPt, double dResult[])
���ܣ�  �������ϵת���Ĳ���������������ת����������X1�任��X2�Ĳ���

����1��GGPt ������������ϵ1�µ�����,��A�У�������������ϵ2�µ����꣬��B��
����2�� 
����3��dResult ����ֵ�����ݼ��洢˳������Ϊ��
��                                            ����ϵ��
Xs,Ys,Zs                                      ƽ������
�Ħئ�                                        ������ת�ǣ���תѭ��Ϊz��y��x��  
a1 a2 a3                                      ��ת����
b1 b2 b3
c1 c2 c3

�߸�������Ӧ�ľ���ֵ��5����,�ֱ�Ϊ��
����ϵ��      1��
������ת��    3��
��λȨ�����  1�����������ĺû����Ϳ�����������ˣ���ȷ�����ΪС��0.5�������Ҳ����ά��Ĳ��������йأ���ά�㾫��Խ�ߣ������ԽС����

����4��

����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/07/26

***************************************************/
Function_API bool GetZuoBiaoZhuanHuanCanShu(vector<CSamePoint> GGPt, double dResult[]);
/****************************************************
��������GetZuoBiaoZhuanHuanCanShu(CObjectPointsVect X1, CObjectPointsVect X11, double dResult[])
���ܣ�  �������ϵת���Ĳ���������������ת����������X1�任��X2�Ĳ���

����1��x1 ������������ϵ1�µ�����
����2��x2 ������������ϵ2�µ�����
����3��dResult ����ֵ�����ݼ��洢˳������Ϊ��
��                                            ����ϵ��
Xs,Ys,Zs                                      ƽ������
�Ħئ�                                        ������ת�ǣ���תѭ��Ϊz��y��x��  
a1 a2 a3                                      ��ת����
b1 b2 b3
c1 c2 c3
����4��

����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/07/26

***************************************************/
Function_API int GetZuoBiaoZhuanHuanCanShu(CObjectPointsVect &X1, CObjectPointsVect &X11, double dResult[]); 

/****************************************************
��������GetZuoBiaoZhuanHuanCanShu(double* X1, double* X11, int nc,  double dResult[])
���ܣ�  �������ϵת���Ĳ���������������ת����������X1�任��X2�Ĳ���

����1��x1 ������������ϵ1�µ�����
����2��x2 ������������ϵ2�µ�����
����3��nc ������Ķ������м��Թ����㣩
����4��px1[3] ������������ϵ1�����е���������꣨1/n��Xi, 1/n��Yi, 1/n��Zi��
����5��px2[3] ������������ϵ2�����е���������꣨1/n��Xi, 1/n��Yi, 1/n��Zi��
����6��dResult ����ֵ�����ݼ��洢˳������Ϊ��
��                                            ����ϵ��
Xs,Ys,Zs                                      ƽ������
�Ħئ�                                        ������ת�ǣ���תѭ��Ϊz��y��x��  
a1 a2 a3                                      ��ת����
b1 b2 b3
c1 c2 c3


����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/07/26

***************************************************/
Function_API int GetZuoBiaoZhuanHuanCanShu(double* X1, double* X11, int nc, double px1[3], double px2[3],double dResult[]);
 
/****************************************************
��������GetXuanZhuanJvZhen(double abc[], double dM[])
���ܣ�  ����������ת�ǣ�������ת����

����1��abc[]     �Ħئ�            ������ת�ǣ���תѭ��Ϊz��y��x��
����2��dM ��ת����

a1 a2 a3                                      ��ת����
b1 b2 b3
c1 c2 c3


����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/07/31

***************************************************/
Function_API void GetXuanZhuanJvZhen(double abc[], double dM[]);


/********************************************
void OrientationCalculate(vector<CSamePoint> & dPoiArr, vector<CScaleBar> vecScaleBar, double dBack[])
���ܣ� ��ⶨ�����(���û�л�׼�ߣ�������Ի���Ϊ1000mm�Ķ���ģ��)

����1	sp				ͬ���㼯��
����2   vecScaleBar     ��׼��
����3   dBack          ���ص�����
Xs,Ys,Zs M �Ħئ�         ������ʼֵ 15���� 0 ~14
rms                    ���ն������������ 1��    15 
Xs,Ys,Zs �Ħئ� M ģ�͵���Ա�����ϵ 15��   16 ~ 30
Xs,Ys,Zs ģ�͵���ʵ������ϵ�� 3��     31 ~ 33
ms                      ���򾫶�      34 �����ڻ�û����Ӿ���������

����4  dErBeiPixSize    ���سߴ������ֵ(Ĭ��ֵΪ0.02)

����ֵ��

��д�ˣ���׿��
���ڣ�2012/09/04
********************************************/
Function_API bool OrientationCalculate(vector<CSamePoint> & dPoiArr, vector<CScaleBar> &vecScaleBar, double dBack[], double dErBeiPixSize = 0.02);


/********************************************
��������GetCorrespondingEpipolarLineImage(CCamera1 & lCam, CCamera1 & rCam, int w, int h, float ** pfRowImagPiexL, float ** pfRowImagPiexR, byte *pbyEpipolarLineImageL, byte *pbyEpipolarLineImageR)
���ܣ�  ���ɺ���Ӱ��Ӱ���ϵ�ͬ������ͬһ�л���

����1��lCam						<in>	��������ļ���lCam.m_dRotm/rCam.m_dRotm��ת���������Ҫ����ֵ��
����2��rCam						<in>
����3��w						<in>	ͼ����
����4��h						<in>
����5��pfRowImagPiexL           <out>   ���Һ���Ӱ���ϵ���㣬��Ӧ��ԭʼͼ���ϵ��������꣨����ϵԭ�������Ͻǣ�		��pfRowImagPiexL[i][0]��pfRowImagPiexL[i][1]�������Ӱ���ϣ���i�����ص�����Ӧ��ԭʼͼ�������ص��x��y���꣩
										��pfRowImagPiexL[i][0]��pfRowImagPiexL[i][1]�������Ӱ���ϣ���i�����ص�����Ӧ��ԭʼͼ�������ص��x��y���꣩
										��pfRowImagPiexL[i][2]��pfRowImagPiexL[i][3]�������Ӱ���ϣ���i�����ص�����Ӧ��ԭʼͼ���Ͼ���������x��y���꣩

����6��pfRowImagPiexR           <out>
����7��pbyrowL                  <out>    �������ԭʼӰ������ 
����8��pbyrowR					<out>
����9��pbyEpipolarLineImageL    <out>    ���ɵĺ���Ӱ������
����10��pbyEpipolarLineImageR    <out>    ���ɵĺ���Ӱ������

����ֵ��1=������X����2=������Y����0=���߼���ʧ�ܡ�

��д�ˣ���׿��
��д���ڣ� 2019/11/21
********************************************/
Function_API byte GetCorrespondingEpipolarLineImage(CCamera1 & lCam, CCamera1 & rCam, int w, int h, float ** pfRowImagPiexL, float ** pfRowImagPiexR, byte *pbyrowL = NULL, byte *pbyrowR = NULL, byte *pbyEpipolarLineImageL = NULL, byte *pbyEpipolarLineImageR = NULL);



/********************************************
��������SameNameEpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *lpabc,, double *lpabc)
���ܣ� ����õ����߷���ʽ��ϵ����������Ƭ��ѡһ���㣬�ֱ������Left��Ƭ��Right��Ƭ�ϵĺ��߷���)

����1��lCam          ��������ļ�
����2��
����3��pdx1y1z1      ���ϵS1�µ�һ������
����4��lpabc          ����Ƭ���߷��̵�ϵ���ͳ�����Ǹ�����ֵ ����Ϊa��b��c �ֱ�Ϊ���̵�ϵ�� ax+by+c =0;
����5��rpabc          ����Ƭ���߷��̵�ϵ���ͳ�����Ǹ�����ֵ ����Ϊa��b��c �ֱ�Ϊ���̵�ϵ�� ax+by+c =0;

����ֵ����
********************************************/
Function_API void SameNameEpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *lpabc, double *rpabc);



/*****************************************************************
void HorizontalParallax(CCamera1 lCam, CCamera1 rCam, float fDistanceRange[], float fParallax[])
���ܣ�  ���������Ӳʹ�÷���������Ƭ�ϵ����x���꣬��ȥ��С�Ӳ������Ӳ�͵õ��͵õ�����Ƭ��ͬ�����x���귶Χ����������x�������������y�᷽����ǰ�涼����y��


����1��lCam							��������ļ�
����2��rCam
����3��fDistanceRange               Ŀ������ȱ仯��Χ�� fDistanceRange[0]=����ľ��롢fDistanceRange[1]=��Զ�ľ��루��������ֵ����Ҫ�Ǹ�����,  ��λ�����ף�
����4��fParallax                    �ӲΧ����λ�����أ�fParallax[0]=����ľ���ķ�Χ��fParallax[1]=��Զ�ľ���ķ�Χ
����5��


����ֵ����

���ߣ���׿��
���ڣ�2019/11/26--11��39��25
*****************************************************************/
Function_API void HorizontalParallax(CCamera1 lCam, CCamera1 rCam, float fDistanceRange[], float fParallax[]);

/********************************************
��������epipolarlineequation()
���ܣ� ����õ����߷����ǵ�ϵ��

����1��lCam          ��������ļ�
����2�� 
����3��pdx1y1z1      ���ϵS1�µ�һ������
����4��pabc          ���߷��̵�ϵ���ͳ�����Ǹ�����ֵ ����Ϊa��b��c �ֱ�Ϊ���̵�ϵ�� ax+by+c =0;
����ֵ����
********************************************/
Function_API void EpipolarLineEquation(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc);


/********************************************
��������EpipolarLineEquationEx(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc)
���ܣ� ����õ����߷����ǵ�ϵ��(�������Left��Ƭ�ϵĵ���Right��Ƭ�ϵĺ��߷���)

����1��lCam          ��������ļ�(lCam.m_dRotm����ת���������ֵ)
����2��rCam          ��������ļ�(rCam.m_dRotm����ת���������ֵ) 
����3��pdx1y1z1      ���ϵS1�µ�һ������
����4��pabc          ���߷��̵�ϵ���ͳ�����Ǹ�����ֵ ����Ϊa��b��c �ֱ�Ϊ���̵�ϵ�� ax+by+c =0;
����ֵ����
********************************************/
Function_API void EpipolarLineEquationEx(CCamera1 & lCam, CCamera1 & rCam, double *pdx1y1z1, double *pabc);


/****************************************************
��������XiangGuanXiShu(byte pbyValue1[], byte pbyValue2[], byte byTemplateSize, double & dBackValue)
���ܣ�  ����������������ϵ��

����1�� pbyValue1 ����1��ģ��1������
����2�� pbyValue2 ����2��ģ��2������
����3�� byTemplateSize ģ��ĳߴ�(ģ����,ģ������Ƿ��ε�)
����4�� dBackValue    ����ֵ

����ֵ�� ��ȷ���㷵��true or false

��д�ˣ���׿��
��д���ڣ�2013/08/28

***************************************************/
Function_API bool XiangGuanXiShu(byte pbyValue1[], byte pbyValue2[], byte byTemplateSize, double & dBackValue);

/********************************************
��������XuanZhuanJiaoToJvZheng(double pdrX, double pdX, byte byxyz)
���ܣ�����ת������ת����

����1��pdrX   ������ת�ǣ����ݴ洢˳��Ϊ (��λ�ǻ���)
�ף��أ���

����2��pdX  <out>  ��ת�������ݴ洢˳��Ϊ
a1,a2,a3;
b1,b2,b3;
c1,c2,c3;

˵�����Լ����

����3��byxyz   ������ת�ǵ�˳��1��xyz��ʵ����ת˳��Ϊ����x����y,�ٺ�z���� 2��xyz��ʵ����ת˳��Ϊ����z����y,�ٺ�x�� �� 3��zyz��ʵ����ת˳��Ϊ����z����y,�ٺ�z��    ��Ĭ��Ϊ1   ��

����ֵ����

��д�ˣ���׿��
��д���ڣ� 2011/04/21 
********************************************/


 void Function_API XuanZhuanJiaoToJvZheng(double pdrX[], double result[], byte byxyz = 1);

 /****************************************************
 ��������XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[])
 ���ܣ�  ����ת��ת������Ԫ��

 ����1��dxyz		<in>			��ת�ǣ����ȣ�
 ����2��dwxyz     <out>          ��Ԫ��
 ����3��byxyz   ������ת�ǵ�˳��1��xyz��ʵ����ת˳��Ϊ����x����y,�ٺ�z���� 2��zyx��ʵ����ת˳��Ϊ����z����y,�ٺ�x�� �� 3��zyz��ʵ����ת˳��Ϊ����z����y,�ٺ�z����Ĭ��1��


 ����ֵ��                    �ɹ�Ϊtrue

 ��д�ˣ���׿��
 ��д���ڣ�2014/01/08

 ***************************************************/
 bool Function_API XuanZhuanJiaotosiyuanshu(double dxyz[], double dwxyz[], byte byxyz = 1);


 /****************************************************
 ��������XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[])
 ���ܣ�  ����ת����ת������Ԫ��

 ����1��dxyz		<in>			��ת����()
 ����2��dwxyz     <out>          ��Ԫ��
 ����3��


 ����ֵ��                    �ɹ�Ϊtrue

 ��д�ˣ���׿��
 ��д���ڣ�2014/01/08

 ***************************************************/
 bool  Function_API XuanZhuanJvZhenTosiyuanshu(double dxyz[], double dwxyz[]);

 /****************************************************
 ��������CreatRotationMatrix(double rmat[], double angle, byte xyz)
 ���ܣ�

 ����1��rmat		<in\out>			��ת����()
 ����2��angle                ��ת�ĽǶ�(��λ������)
 ����3��xyz                  ���ĸ�����ת��0X�ᡢ1Y�ᡢ2Z�ᣩ


 ����ֵ��                    ��

 ��д�ˣ���׿��
 ��д���ڣ�2014/01/08

 ***************************************************/
 Function_API bool CreatRotationMatrix(double rmat[], double angle, byte xyz);

/********************************************
��������JiSuanSanGeXuanZhuanJiao(double **pdrX��double dResult[])
���ܣ� ����������ת�ǵ�ֵ������pdrX��ֵ���㣬���������������� pdrX ��

����1��pdrX  <in> �������õ����ⷽλԪ��ֵ�����ݴ洢˳��Ϊ 
a1,a2,a3;
b1,b2,b3;
c1,c2,c3; 

����2��dResult <out> �ף��أ���
����3��
����4��
����ֵ����

��д�ˣ���׿��
��д���ڣ� 2011/04/20 
********************************************/
Function_API void JvZhengToXuanZhuanJiao(double **pdrX, double dResult[]);

/****************************************************
��������JvZhengToXuanZhuanJiao(double pdrX[], byte xyz)
���ܣ�  �Ӿ�����������ת��

����1��pdrX <in��out>   ǰ9����M ��3������ת��
����2��xyz              ����ĽǶ��ǰ�1��xyz:������2��zyx����ת˳�򡢻���3��zyz����ת˳��Ĭ��1
����3��
����4��

����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/10/28

***************************************************/
Function_API bool JvZhengToXuanZhuanJiao(double pdrX[12], byte xyz = 1);

/****************************************************
��������ChangeAix(double dData[])
���ܣ�  ��������е�һ�������ͨ����׼���������ת����������ϵ��

����1��dData <in/out> 
��������˳��
Xs,Ys,Zs �Ħئ�		��׼���������� 3��
Xs,Ys,Zs �Ħئ� M   ��һ�����ģ�͵���Ա�����ϵ 15��

�������˳��
Xs,Ys,Zs �Ħئ� M   ��һ�����ת������ⷽλ 15��

����2��bUseMatrix �Ƿ�ʹ�� ��һ�����M �����������
����ݦĦئ��� M ��ֵ
����3��
����4��

����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/10/28

***************************************************/
Function_API bool ChangeAix(double dData[], bool bUseMatrix = false);

/********************************************
��������QianFangJiaoHuiEx(double M[3][3], double S[3], CArray <double, double> &dPoiArr, double *XYZ)
���ܣ� ǰ�����ṫʽ����ǿ�棨һ�ν��ܼ���һ������Ӧ���﷽�㣩

����1��dWaiFangWei      ͼ������ΪԪ�أ�ÿһ�д���һ��������ⷽλ��Xs,Ys,Zs,�ף��أ���
����2��nCountCameras	�������
����3��dPointCoor		ͬ�������� ÿһ�д���һ�����ͬ�����ݣ�һ���ϵ�����������nCountCameras������= 3*nCountCameras �洢˳��Ϊ����x��y��z��x��y��z��������
����4��XYZ  �﷽�������
����5�� 

˵����dWaiFangWei��dPointCoor����֮��ͼƬ���ⷽλ����Ӧ�����Ĵ洢˳����һ�µ�
����ֵ������ɹ����� TRUE

��д�ˣ���׿��
��д���ڣ� 2011/04/18 
********************************************/
Function_API bool QianFangJiaoHuiEx(double **dWaiFangWei, int nCountCameras, double *dPointCoor, double XYZ[]);
/****************************************************
��������QianFangJiaoHuiEx(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool bKaiGuan[3], bool nindex[])
���ܣ�   ǰ��������㣨֧�ֶ����ͬʱ���㣩(�����QianFangJiaoHuiEx�ٶ�Ҫ��һ�㣬�����治���������ת�������㣬�����������ʱ����doutArr
           �����Ѿ�����ת�����ֵ������ͬ���㣬�����ֱ��ʹ����ת������)
//׼��ǰ����������� 
//ǰ�������������﷽������ 

����1��doutArr                     ͬ���㼸�Σ������������ÿһ��������Ӧ���ⷽλ��Ϣ��ÿһ���㶼�Ǿ�����������,ʹ�õ�����ת���󣬶�����������ת���������֮��������ת����
����2��nPtindex                    doutArr�У�ÿһ��ͬ����ĸ���������
����3��nPt                         һ���ж�����ͬ���㣨���ٸ��﷽�㣩
����4��pXYZ          <out>         ��������������ά����
����5��
����6��


����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/09

***************************************************/
Function_API bool QianFangJiaoHuiEx2(vector<CCtrlDataSet> doutArr, int *nPtindex, int nPt, vector<CObjectPoints> &pXYZ);

/********************************************
��������QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu)
���ܣ� ǰ�����ṫʽ������﷽�����ꣻ����ʽ���������Թ��淽ʽ�����Ľ��㣬��Ϊ�÷�ʽĬ����һ��ͶӰ����Ϊ
ԭ�㣬����ת����Ϊ��λ��

����1��M               ��Ƭ����ת����
����2��S               ��Ƭ��ͶӰ��������
����3��dPoiArr         ͬ�������� �洢˳��Ϊ������x��y��z;������x��y��z
����4��pXYZ      <out>      �﷽�������,
����5��nshu           ���ڼ���ĵ�ĸ���

����ֵ������ɹ����� TRUE

��д�ˣ���׿��
��д���ڣ� 2011/04/18 
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], vector<CSamePoint> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu);


/********************************************
��������QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, double *XYZ, int nshu)
���ܣ� ǰ�����ṫʽ������﷽�����ꣻ����ʽ���������Թ��淽ʽ�����Ľ��㣬��Ϊ�÷�ʽĬ����һ��ͶӰ����Ϊ
ԭ�㣬����ת����Ϊ��λ��

����1��M ��Ƭ����ת����
����2��S ��Ƭ��ͶӰ��������
����3��dPoiArr ͬ�������� �洢˳��Ϊ������x��y��z;������x��y��z
����4��**XYZ  �﷽�������,����nshuά��3�еľ���
����5�� nshu ���ڼ���ĵ�ĸ���

����ֵ������ɹ����� TRUE

��д�ˣ���׿��
��д���ڣ� 2011/04/18
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], vector<CSamePoint> &dPoiArr, double **XYZ, int nshu);

/********************************************
��������QianFangJiaoHui(double M[3][3], double S[3], CArray <double, double> &dPoiArr, vector<CObjectPoints> &pXYZ, int nshu)
���ܣ� ǰ�����ṫʽ������﷽�����ꣻ����ʽ���������Թ��淽ʽ�����Ľ��㣬��Ϊ�÷�ʽĬ����һ��ͶӰ����Ϊ
ԭ�㣬����ת����Ϊ��λ��

����1��M               ��Ƭ����ת����
����2��S               ��Ƭ��ͶӰ��������
����3��dxyz_t          ͬ�������� �洢˳��Ϊ������x��y��z;������x��y��z
����4��Pt_xyz          �﷽�������
����5��

����ֵ������ɹ����� TRUE

��д�ˣ���׿��
��д���ڣ� 2011/04/18
********************************************/
Function_API bool QianFangJiaoHui(double M[3][3], double S[3], double dxyz_t[6], Xxyz &Pt_xyz);

/*******************************************************
��������PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
����˵�������潻�����﷽��

����1��Images                      ����ļ����Ρ������ 
����2��fPlane                      ƽ�淽��                         
����3��vectPoint        <out>      �﷽��洢����
����4��df                          ���� 
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint, double df);


/*******************************************************
��������PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<Xxyz>& vectPoint)
����˵�������潻�����﷽��

����1��Images                      ����ļ�����
����2��Cam                         ����ļ����ⷽλҪ��ֵ��
����3��fPlane                      ƽ�淽����
����4��vectPoint        <out>      �﷽��洢��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, XPlane fPlane, vector<Xxyz>& vectPoint);
/*******************************************************
��������PointPlaneJiaoHui(CImagePoint_N pt, double dxyzabc[], FaxPlane fPlane, CObjectPoints &opt, double df)
����˵����

����1��xpt           <in>            ���
����2��dxyzabc       <in>            �ⷽλ 
��12�������洢˳��Ϊ��
ǰ������ͶӰ�������꣨Xs,Ys,Zs��
��Ÿ�Ϊ��ת����a1 a2 a3
b1 b2 b3
c1 c2 c3

����3��fPlane        <in>            ƽ�淽��
����4��opt           <out>           ��������﷽������
����5��df            <in>            ����(����)
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(CImagePoint_N pt, double dxyzabc[], FaxPlane fPlane, CObjectPoints &opt, double df);


/*******************************************************
��������PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
����˵�������潻�����﷽��

����1��Images                      ����ļ����� 
����2��Cam                         ����ļ����ⷽλҪ��ֵ�� 
����3��fPlane                      ƽ�淽����  
����4��vectPoint        <out>      �﷽��洢��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, FaxPlane fPlane, vector<CObjectPoints>& vectPoint);

/*******************************************************
��������PointPlaneJiaoHui(CPhotoImage Images, FaxPlane fPlane, vector<CObjectPoints>& vectPoint)
����˵�������潻�����﷽��

����1��Images                      ����ļ�����
����2��Cam                         ����ļ����ⷽλҪ��ֵ��
����3��fPlane                      ƽ�淽����
����4��vectPoint        <out>      �﷽��洢��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/26
*******************************************************/
Function_API bool PointPlaneJiaoHui(vector<CImagePoint_N> Images, CCamera1 Cam, XPlane fPlane, vector<CObjectPoints>& vectPoint);
/****************************************************
��������FeatureExtractAccuracy(int nPic, vector<CPhotoImage> veImages, vector<CObjectPoints> CtrlPoints, double &dAccuracy)
���ܣ�  ����֮����ÿ��������ȡ���ȣ��ÿ��Ƶ㷴����㷨������������һ��ֻ�ܴ���һ�������ͼƬ����Ϊÿ��ֻ������һ���������dF��

����1��nCounterPic   ��Ƭ������
����2��veImages      ÿ����Ƭ����������
����3��CtrlPoints    �﷽�����꣨���Ƶ����꣩ 
����4��dF            ��� 
����5��dAccuracy	 ��������ƽ������


����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/12/3

***************************************************/
Function_API bool FeatureExtractAccuracy(int nPic, vector<CPhotoImage>& veImages, vector<CObjectPoints> CtrlPoints, double dF, double &dAccuracy);


/****************************************************
��������bool SingleCameraMultPicOrientationCalculate(int nPic, vector<CPhotoImage> &veImages, vector<CObjectPoints> &CtrlPoints, vector<CScaleBar> &vecScaleBar, CCamera1 Cam,double &dAccuracy, bool bChangeCam)
���ܣ�  ������������򣨵��������ͼ�����,֧���п������ݵĶ���ͬʱҲ֧���л�׼�ߵ���Զ���
����� CtrlPoints �����ĸ����ϵ�ֵ������ݿ��Ƶ㶨��
����1��nPic                  ͼ������
����2��veImages              ����ļ���
����3��CtrlPoints            ���Ƶ�����
����4��vecScaleBar           ��׼���ļ�
����5 CCamera1 Cam           ����ļ�
����6��dAccuracy             ���򾫶�
����7��pXYZ       <out>      ����õ�����ά�﷽������
����8��BPra                  ƽ������
����9��bChangeCam            �Ƿ��������ļ�������ݣ��Ƿ�ı��ڲ�����(��Ĭ��ֵ��Ĭ���Ǹı��)
 
����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/08

***************************************************/
Function_API bool SingleCameraMultPicOrientationCalculate(int nPic, vector<CPhotoImage> &veImages, vector<CObjectPoints> &CtrlPoints, vector<CScaleBar> &vecScaleBar
														  , CCamera1& Cam,/*double &dAccuracy, */vector<CObjectPoints> &pXYZ, BundlePra &BPra, bool bChangeCam);



/*******************************************************
��������AutoMatchEx(vector<CPhotoImage> &veImages, CCamera1& Cam)
����˵���� �Զ�ƥ�䣨��ʱ��ͼ�񶼶�������//��������㶼�������ˣ�

����1��veImages                              ������ݣ�ÿ�����ƥ��״̬Ҫ���Ϊfalse��
����2��Cam                                   
����3��distancestreshold                     �㵽ֱ�ߵľ�����ֵ��ƥ��ʱ��ͬ���㵽ֱ�ߵľ�����ֵ��һ�����صĴ�С��
����4��pWuXYZ                                ƥ�������ɵ��﷽��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/09/25
*******************************************************/
Function_API int AutoMatchEx(vector<CPhotoImage> &veImages, CCamera1& Cam, double distancestreshold, vector<CObjectPoints> & pWuXYZ);
/*******************************************************
��������AutoMatch2Ex(vector<CPhotoImage> &veImages, CCamera1& Cam)
����˵���� �Զ�ƥ�䣨��ʱ��ͼ�񶼶�������//��������㶼�������ˣ�

����1��veImages                              ������ݣ�ÿ�����ƥ��״̬Ҫ���Ϊfalse��
����2��Cam                                   
����3��distancestreshold                     �㵽ֱ�ߵľ�����ֵ��ƥ��ʱ��ͬ���㵽ֱ�ߵľ�����ֵ��һ�����صĴ�С��
����4��pWuXYZ                                ƥ�������ɵ��﷽��
����5��nHadMatch                             �Ѿ�ƥ�����ͼ���ж����ţ���Ҫ��Ϊ����ʾƥ����ȣ� 
����6��

����ֵ��

�༭����׿��
���ڣ�2014/09/25
*******************************************************/
Function_API int AutoMatch(vector<CPhotoImage> &veImages, CCamera1& Cam, double distancestreshold, vector<CObjectPoints> & pWuXYZ, int &nHadMatch);
/****************************************************
��������BundleAjustment(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, double dF, bool bKaiGuan[3], double &dJingDu)
���ܣ�  ������ƽ�����п��Ƶ�Ķ�����㣬ͬʱ���Կ��Ʊ궨����������ƽ�(����Ľ������Ķ���������veImages�У��ڲ����ı��浽��
Cam�У���ʱ����ָ���ı�������ȡ������)

����1��veImages                    ÿ��ͼ���������ݣ�����ʹ���е�ͼƬ����������򲻲���ģ�
����2��pXYZ                        ���Ƶ���ά����
����3��dF                          ����
����4��bKaiGuan                    ���ü��������bKaiGuan[0] == true������㣬bKaiGuan[2] == true�������������ݣ�bKaiGuan[1] == true��궨�ڲ���
����5��nindex                      ����ƽ������ͼ��ı��(�����С����ͼ�������)�����Բ������е�ͼ�񶼲���ģ�
����6��dstop                       ֹͣ������Ĭ��0.00002��
����7��bFullBundle                 �Ƿ���ȫƽ����е���루ture����ֻ��CODE���ĵ���루false��,�����һ��Ϊtrue����nindex����Ϊ�����飬���治�ã�
����8��pWpWuFangIndexuFang         �﷽����CODE��CDOE���롢�����������Ϣ  
����9��BBack                       ����ֵ�ṹ��


����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/09

***************************************************/
Function_API bool BundleAjustment4(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam/*, bool *bKaiGuan, bool *nindex*/, double dstop, BundlePra &BPra, bool bFullBundle = false, int *pWuFangIndex = NULL, BundleBack *BBack = NULL);
Function_API bool BundleAjustment4_BD(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam/*, bool *bKaiGuan, bool *nindex*/, double dstop, BundlePra &BPra, bool bFullBundle = false, int *pWuFangIndex = NULL, BundleBack *BBack = NULL);
/*******************************************************
��������CodeNarget(vector<CPhotoImage> &veImages, CCamera1& Cam, vector<CObjectPoints> & pWuXYZ)
����˵���� ����CODE��Χ�ı����

����1��veImages                              ������ݣ�ÿ�����ƥ��״̬Ҫ���Ϊfalse��
����2��dF                                    ������ࣨ������
����3��pWuXYZ                                ƥ�������ɵ��﷽��
����4��
����5��
����6��

����ֵ��     ƥ�䵽�ĵ������

�༭����׿��
���ڣ�2014/09/25
*******************************************************/
Function_API int CodeNarget(vector<CPhotoImage> &veImages, double dF, vector<CObjectPoints> & pWuXYZ);
 


//////////////////////////////////////////////////////////////////////////
/********************************************
��������CorrectImagPointCoordinate(CPicture pic)
���ܣ�  ������Ƭ�ľ���������������������

����1��Cam            ��Ƭ�ľ�������
����2��veImage        ��Ƭ����
����3��
����4��
����ֵ����

��д�ˣ���׿��
��д���ڣ� 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 & Cam, vector<CPhotoImage>& veImage);


/********************************************
��������CorrectImagPointCoordinate(CPicture pic)
���ܣ�  ������Ƭ�ľ���������������������

����1��Cam            ��Ƭ�ľ�������
����2��veImage        ������ݼ���
����3��
����4��
����ֵ����

��д�ˣ���׿��
��д���ڣ� 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 & Cam, vector<CImagePoint_N>& veImage);

/********************************************
��������CorrectImagPointCoordinate(CCamera1 &Cam, CImagePoint_N& pt)
���ܣ�  ������Ƭ�ľ���������������������

����1��Cam            ��Ƭ�ľ�������
����2��pt            �������
����3��
����4��
����ֵ����

��д�ˣ���׿��
��д���ڣ� 2011/05/23 
********************************************/
Function_API void CorrectImagPointCoordinate(CCamera1 &Cam, CImagePoint_N& pt);
 
/****************************************************
��������QianFangJiaoHui(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool bKaiGuan[3], bool nindex[])
���ܣ�   ǰ��������㣨��Ҫ���ڲ����������������׼�����������Ƭ�ϵĵ����������Ƕ�����Ƭ�ϵĵ㣩
//׼��ǰ����������� 
//ǰ�������������﷽������ 

����1��veImages                    ÿ��ͼ���������ݣ�����ʹ���е�ͼƬ����������򲻲���ģ�
����2��pXYZ          <out>         ��������������ά����
����3��Cam                         ����ļ�
����4��nindex                      ��������ͼ��ı��(�����С����ͼ�������,���� veImages ��Ӧ)�����Բ������е�ͼ�񶼲���ģ�
����5��bCodeOnly                   �Ƿ�ֻ�������㣨���ǲ�����һ��ĵ��㣩
����6��bOrentainUse                �ڶ��������ʹ�ã�����������У���ʹ�þ�������������꣩�����Ϊfalse����һ���Ӧ�ã������ڲ�ʹ�þ��������������


����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/09

***************************************************/
Function_API bool QianFangJiaoHui(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, bool nindex[], bool bCodeOnly, bool bOrentainUse = true);


/****************************************************
��������SignImaOrientation(vector<CSamePoint> &dPoiArr, double dPixelSizex, double dBack[])
���ܣ�  ����ͼ��ĺ󷽽���

����1��dPoiArr    ����,����ÿһ��ͬ������󣬸�ֵ��Ӧ��ʽ����

spt.m_dAX = pobj->m_dX;  //�﷽��
spt.m_dAY = pobj->m_dY;
spt.m_dAZ = pobj->m_dZ;

spt.m_dBX = por->m_dx; //��㣨�������������꣩
spt.m_dBY = por->m_dy;
spt.m_dBZ = -dF;

����2��dPixelSizex        ���سߴ�
����3��dBack       in/out     ���ⷽλԪ�أ���СΪ16����
��Ϊ���������˳��Ϊ
ǰ��������ֵΪ0
dBack[0] ~dBack[5]      0

����ʮ����
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



��Ϊ���������˳��Ϊ
ǰ������
dBack[0] ~dBack[5]     
Xs,Ys,Zs
a,w,b

dBack[6] = ���򾫶�

����ȫΪ��


����4��
����5��

����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/09

***************************************************/
Function_API bool SignImaOrientation(vector<CSamePoint> &dPoiArr, double dPixelSizex, double dBack[]);

/*******************************************************
��������GetImageResidual(CCtrlDataSet& doutArr, CObjectPoints oPt, double drxy[])
����˵�������㵥���﷽������Ӧ�����в�

����1��
����2��
����3��drxy                  ����x��y���������ϵ�ƽ���в�
����4��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/09/28
*******************************************************/
Function_API bool GetImageResidual(CCtrlDataSet& doutArr, CObjectPoints oPt, double drxy[]);
/****************************************************
��������FromObjectToImagPoint(double dXsYsZs[3], double dRot[9], double df, double dXYZ[3], double &dx, double &dy)
���ܣ�  ���﷽������������

����1��dXsYsZs            ��Ƭ���ⷽλ-ͶӰ��������
����2��dRot               ��Ƭ���ⷽλ-��ת����
9����������Ϊ��
a1,a2,a3;
b1,b2,b3;
c1,c2,c3; 

����3��df                 ������� (����ֵ����Ҫȡ����)
����4��dXYZ               �﷽������
����5��dx                 �﷽���Ӧ�����x����ֵ
����6��dy                 �﷽���Ӧ�����y����ֵ
����ֵ��

��д�ˣ���׿��
��д���ڣ�2013/12/03

***************************************************/
Function_API void FromObjectToImagPoint(double dXsYsZs[3], double dRot[9], double df, double dXYZ[3], double &dx, double &dy);

/*******************************************************
��������FromObjectToImagPoint(CCamera1 cam, CObjectPoints opt, CImagePoint_N pt)
����˵���� ���﷽�㷴����㣨���������㣩

����1��cam                     �ⷽλ
����2��opt                     �﷽��  
����3��pt       <out>          ���
����4��
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/06/27
*******************************************************/
Function_API void FromObjectToImagPoint(CCamera1 cam, CObjectPoints opt, CImagePoint_N &pt);

/*******************************************************
��������BackCodePoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ)
����˵�������﷽��Ϊ������������Ӧ����㣬�����CODE�㣨��ʱ��������﷽�㣬���ֻ��CODE�㣬�����ٶȻ��һ�㣩

����1��veImages                ����������� 
����2��Cam                     ��Ƭ�Ŀ�ߣ���Ԫ�ߴ�   
����3��pWuXYZ				   �﷽�����ά���꣬�����ֻ��CODE��ģ�
����4��dxyYuZhi                ��������������ԭ����֮��������ֵ�������������ϵľ�����ֵ�����������ؾ��뼴�ɣ�    
����5��
����6��

����ֵ��                       �����µõ��ĵ������

�༭����׿��
���ڣ�2014/11/05
*******************************************************/
Function_API int BackCodePoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ, double dxyYuZhi);


//////////////////////////////////////////////////////////////////////////
//��ȫ�������

/****************************************************
��������BundleAjustment5(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, double dF, bool bKaiGuan[3], double &dJingDu)
���ܣ�  ������ƽ�����п��Ƶ�Ķ�����㣬ͬʱ���Կ��Ʊ궨����������ƽ�(����Ľ������Ķ���������veImages�У��ڲ����ı��浽��
Cam�У���ʱ����ָ���ı�������ȡ������)

����1��veImages                    ÿ��ͼ���������ݣ�����ʹ���е�ͼƬ����������򲻲���ģ�
����2��pXYZ                        ���Ƶ���ά����
����3��Cam                         
����4��dstop                      ֹͣ������Ĭ��0.00002��
����5��BPra                       ����ƽ�����в���
����6��bFullBundle                �Ƿ���ȫƽ����е���루ture����ֻ��CODE���ĵ���루false��,�����һ��Ϊtrue����nindex����Ϊ�����飬���治�ã�
����7��BBack                      ƽ��������ֵ
����8��               


����ֵ��

��д�ˣ���׿��
��д���ڣ�2014/01/09

***************************************************/
Function_API bool BundleAjustment5(vector<CPhotoImage> &veImages, vector<CObjectPoints> &pXYZ, CCamera1 &Cam, double dstop, BundlePra &BPra, bool bFullBundle, BundleBack *BBack);


/*******************************************************
��������BackCodeNagetPoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ)
����˵�������﷽��Ϊ������������Ӧ����㣬�����CODE�㣨��ʱ��������﷽�㣬���ֻ��CODE�㣬�����ٶȻ��һ�㣩

����1��veImages                ����������� 
����2��Cam                     ��Ƭ�Ŀ�ߣ���Ԫ�ߴ�   
����3��pWuXYZ				   �﷽�����ά���꣬��CODE�����ά����Ҫ������ǰ�棬�������Ǳ���㣩
����4��dxyYuZhi                ��������������ԭ����֮��������ֵ�������������ϵľ�����ֵ�����������ؾ��뼴�ɣ�    
����5��nCode                   �﷽����CODE�������
����6��

����ֵ��                       �����µõ��ĵ������

�༭����׿��
���ڣ�2014/11/05
*******************************************************/
Function_API int BackCodeNagetPoints(vector<CPhotoImage> &veImages, CCamera1 Cam, vector<CObjectPoints> & pWuXYZ, double dxyYuZhi, int nCode);









/****************************************************
��������CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve)
���ܣ�  ���������������ϵ������������ϵ��ת������

����1��robat_Tr_Rmat		<in>		 �����˵��������ת�ǣ�ÿһ��12������ǰ����Ϊxyz���꣬��Ÿ�����ת����
����2��cam_Tr_Rmat          <in>         ����Ĳ�����ÿһ��12������ǰ����Ϊxyz���꣬��Ÿ�����ת����
����3��cam_To_robat         <out>        ����������˹�������ϵ��ת������
����4��reserve                           ����λ

����ֵ��                    ��

��д�ˣ���׿��
��д���ڣ�2014/01/08

***************************************************/
Function_API bool CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve = 0);

/****************************************************
��������CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], double cam_To_robat[], byte reserve)
���ܣ�  ���������������ϵ������������ϵ��ת������

����1��robat_Tr_Rmat		<in>		 �����˵��������ת�ǣ�ÿһ��12������ǰ����Ϊxyz���꣬��Ÿ�����ת����
����2��cam_Tr_Rmat          <in>         ����Ĳ�����ÿһ��12������ǰ����Ϊxyz���꣬��Ÿ�����ת����
����3��byT                  <in>         ƽ������
����4��byR                               ��ת����
����5��cam_To_robat         <out>        �����
����6��reserve                           ����λ

����ֵ��                    ��

��д�ˣ���׿��
��д���ڣ�2014/01/08

***************************************************/
Function_API bool CalculateCamToRobate(double robat_Tr_Rmat[], double cam_Tr_Rmat[], byte byT, byte byR, double cam_To_robat[], byte reserve);
 

/*****************************************************************
bool RotationMatrixToRotatingVector(double RotM[], double RotV[])
���ܣ�//�����޵����˹�任����ת����ת��Ϊ��ת��������ת����ģ��


����1��RotM           <in>              ��ת����a1,a2,a3,b1,b2,b3 ,c1,c2,c3
����2��RotV           <out>             ��ת������x��y��z������λ������������ģ�����ĸ���
����3��
����4��
����5��


����ֵ���ɹ�����true

���ߣ���׿��
���ڣ�2019/08/28--22��53��46
*****************************************************************/

Function_API bool RotationMatrixToRotatingVector(double RotM[], double RotV[]);

/****************************************************
bool SiyuanshutoXuanZhuanJvZhen(double dsiyuanshu[], double dR_[])
���ܣ�  ����Ԫ��ת������ת����

����1��dsiyuanshu		<in>			��Ԫ��(w + a*i + b*j + c*k),dsiyuanshu������Ϊw,a,b,c
����2��dR_     <out>          ��ת����
����3��


����ֵ��                    �ɹ�Ϊtrue

��д�ˣ���׿��
��д���ڣ�2014/01/08

***************************************************/
Function_API bool SiyuanshutoXuanZhuanJvZhen(double dsiyuanshu[], double dR_[]);


/****************************************************
bool SiyuanshutoXuanZhuanJvZhen(XVector v1, XVector v2, double dsiyuanshu[])
���ܣ�  ����������v2��ת������v1����Ӧ����Ԫ������ת����

����1��v1		<in>			Ŀ������(��λ����)
����2��v2       <in>            ת������(��λ����)
����3��dsiyuanshu      <out>	��Ԫ��(w + a*i + b*j + c*k),dsiyuanshu������Ϊw,a,b,c


����ֵ�� ��

��д�ˣ���׿��
��д���ڣ�2014/01/08

***************************************************/
Function_API void VectorRotateToVector(XVector v1, XVector v2, double dsiyuanshu[]);


/*******************************************************
��������ImagePtToObjectPt(CImagePoint_N imag_pt, CCamera1 cam, double dZ, CObjectPoints &ob_out)
����˵��������������������Ӧ����ά�����꣬������һ��ǰ�ᣬ������֪Z���������ֻ��Ҫ����X,Y��ֵ

����1��imag_pt             �����������꣬�Ѿ��������������������
����2��cam                 ����ļ�����������Ҫ�����������Ϣ��
����3��dZ					�����Ϣ
����4��ob_out              �﷽������꣨�Ѿ�ȥ����վ�����ˣ�
����5��
����6��

����ֵ��

�༭����׿��
���ڣ�2014/1/6
*******************************************************/
Function_API bool ImagePtToObjectPt(CImagePoint_N imag_pt, CCamera1 cam, double dZ, CObjectPoints &ob_out);


/****************************************************
��������CameraToRobatMode_C_L(XCameraPos CmaRtoCamL, XCameraPos CmaRtoBord, XCameraPos bordtoRobat, XCameraPos &CmatoRobat)
���ܣ�  �ϳ�����������˵�ת������

����1��CmaRtoCamL		<in>		     ������������
����2��CmaRtoBord       <in>             ����ڱ궨������ϵ�µ������
����3��bordtoRobat      <in>             �궨�嵽�����ת������
����3��CmatoRobat      <in>             �궨�嵽�����ת������

����ֵ��                    ��

��д�ˣ���׿��
��д���ڣ�2016/06/08

***************************************************/
Function_API bool CameraToRobatMode_C_L(XCameraPos CmaRtoCamL, XCameraPos CmaRtoBord, XCameraPos bordtoRobat, XCameraPos &CmatoRobat);