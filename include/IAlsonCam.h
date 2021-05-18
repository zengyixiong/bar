#ifndef ICHISHINECAM_H
#define ICHISHINECAM_H

#include <QObject>
#include <QVector>
#include "typeDefine.h"
// #include "MacroDefine.h"
// #include "Mat.h"
// #include "CScan.h"

struct camParam
{
	int serialPort;
	QString exposureTime;
	int realTimeEpt;
	int gain;
	QString roi;
	QString ptsDst;
	bool enhanceMode;
	int decodeThd;

	camParam()
	{
		serialPort = 7;
		exposureTime = 1000;
		gain = 1;
		roi = "600, 600, 200, 200";
		ptsDst = "0, -6000";
		enhanceMode = false;
		decodeThd = 4;
	}
};

class IAlsonCam : public QObject
{
public:
	//释放
	virtual void releaseRes() = 0;																	  //释放资源
 	virtual bool readCfg() = 0;																		  //读取配置文件
 	virtual bool writeCfg() = 0;																	  //保存配置文件
	
	virtual camParam getParam() = 0;																  //读取参数
	virtual void setParam(camParam param) = 0;														  //设置参数
	
	virtual int connectCam() = 0;
	virtual void setSerialPort(int port) = 0;
	virtual int setImageROI(QStringList roi) = 0;
	virtual void setPstDist(QStringList dist) = 0;
	virtual void setDecodeThd(int thd) = 0;
	virtual void setEnhanceMode(bool flag) = 0;
	virtual void setEpt(QStringList ept) = 0;
	virtual void setRealTimeEpt(int ept) = 0;
	virtual void getRealTimeEpt(int& ept) = 0;
	virtual void setGain(int gain) = 0;

	virtual QString getLog(int state) = 0;
	virtual int getCamInitStatus() = 0;
	virtual bool getCamStatus() = 0;
	virtual int getRealImg(HalconCpp::HObject& img) = 0;
	virtual int getImgH(HalconCpp::HObject& img) = 0;
	virtual int getPts(QVector<QVector<Point3D>>& pts, HalconCpp::HObject& imgH) = 0;
	virtual void genImageFromPts(QVector<QVector<Point3D>> pts, HObject srcImg, HObject& img) = 0;
	virtual int getPtsNum() = 0;

	virtual void savePts(QString path) = 0;
	virtual bool loadPts(QString path, QVector<QVector<Point3D>>& pts) = 0;
	virtual void saveImg(HalconCpp::HObject img, QString path) = 0;
	virtual void closeCam() = 0;


	virtual void showCamDlg() = 0;																	  //显示相机设置窗口
};

#endif