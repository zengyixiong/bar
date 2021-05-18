#ifndef IVISION_H
#define IVISION_H

#include <QObject>
#include "halconCpp.h"
#include <QVector>
#include "typeDefine.h"
#include <QImage>

using namespace HalconCpp;

struct DetectParam
{
	HTuple roi;
	HTuple waterThd;
	int shieldNum;
	HTuple shieldROI;

	DetectParam()
	{
		roi[0] = 0;
		roi[1] = 0;
		roi[2] = 0;
		roi[3] = 100;
		roi[4] = 100;
		waterThd = 25;
		shieldNum = 0;
	}
};

struct weldsData
{
	HObject srcImg1;
	HObject srcImg2;
	HTuple weldRow;
	HTuple weldColumn;
};

struct resultData
{
	int barsNums;
	HObject barsRegion;
	HTuple barsRow;
	HTuple barsColumn;
	HTuple weldRow;
	HTuple weldColumn;
	HTuple ptsX;
	HTuple ptsY;
	HTuple ptsZ;
	HTuple robotX;
	HTuple robotZ;
	HTuple robotY;

	resultData()
	{
		barsNums = 0;
		barsRow = 0;
		barsColumn = 0;
		weldRow = 0;
		weldColumn = 0;
		ptsX = 0;
		ptsY = 0;
		ptsZ = 0;
		robotX = 0;
		robotZ = 0;
		robotY = 0;
	};

	void reStore()
	{
		barsNums = 0;
		barsRow = 0;
		barsColumn = 0;
		weldRow = 0;
		weldColumn = 0;
		ptsX = 0;
		ptsY = 0;
		ptsZ = 0;
		robotX = 0;
		robotZ = 0;
		robotY = 0;
	}
};

class IVision : public QObject
{
public:
	//释放资源
	virtual void releaseRes() = 0;

	virtual void setParam(DetectParam _param) = 0;
	virtual DetectParam getParam() = 0;

	virtual bool readCfg() = 0;
	virtual bool writeCfg() = 0;

	//复核及定位棒材位置
	virtual bool detectBars(HObject srcImg, int barsSpec, resultData& _outData) = 0;
	//筛选出合适的焊点
	virtual void selectOutPoint(HTuple row, HTuple column, int weldNum, HTuple& weldRow, HTuple& weldColumn) = 0;
	virtual void selectOutPoint(HTuple row, HTuple column, HObject barsRegion, int weldNum, QVector<QVector<Point3D>> pts, HTuple& weldRow, HTuple& weldColumn) = 0;
	//检测焊接是否成功
	virtual void detectWeldPoint(HObject img1, HObject img2, HTuple weldRow, HTuple weldColumn, QVector<bool>& ret) = 0;
	virtual void detectWeldPoint(QVector<QVector<Point3D>> barsPts, QVector<QVector<Point3D>> weldsPts, QVector<QStringList> roiList, QVector<bool>& ret) = 0;
	//图像格式转换
	virtual void qImgToHobject(QImage img, HObject& hImg) = 0;
	virtual void hobjectToQImg(HObject hImg, QImage& img) = 0;
	//标定
	virtual bool calibration(HTuple imgX, HTuple imgY, HTuple imgZ, HTuple robotX, HTuple robotY, HTuple robotZ) = 0;
	//图像坐标转机器人坐标
	virtual void affinePoint(HTuple imgX, HTuple imgY, HTuple imgZ, HTuple& robotX, HTuple& robotY, HTuple& robotZ) = 0;
};

#endif