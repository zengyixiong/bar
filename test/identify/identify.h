#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_identify.h"
#include "function.h"
#include "Halcon.h"
#include "cpp\HalconCpp.h"
#include "halconcpp\HalconCpp.h"
#include "socket.h"
#include "settingdialog.h"
#include "debug.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QtGui/qpixmap.h>
#include <QFileDialog>
#include <QFileInfo>
#include <stdio.h>
#include <qmessagebox.h>
#include <QDateTime>
#include <QSettings>
#include <QTextCodec>

extern int Threshold1_min;
extern int Threshold1_max;
extern double circularity_min;
extern double circularity_max;
extern int Threshold2_min;
extern int Threshold2_max;
extern int first_select;
extern int second_select;


using namespace HalconCpp;
class identify : public QMainWindow
{
	Q_OBJECT

public:
	identify(QWidget *parent = Q_NULLPTR);
	//ui部分
	QPixmap m_greenLed;
	QPixmap m_redLed;
	QPixmap m_yellowLed;



	//halcon参数部分
	HTuple m_hLabelID;			//QLabel控件句柄
	HTuple m_hHalconID;			//Halcon显示窗口句柄
	HTuple hv_name;
	QImage to, to_new;
	HTuple hv_pointer;
	HTuple htype;
	HTuple   o_width, o_height;
	double area1,data2;
	unsigned char *ptr;
	unsigned char *ptr_new;
	HObject  ho_Image, ho_ROI_0, ho_ImageReduced;
	HObject  ho_Region, ho_RegionOpening, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_SelectedRegions2, ho_RegionTrans;
	HObject  ho_shape, ho_RegionDilation, ho_RegionUnion, ho_ImageReduced_3;
	HObject  ho_ImageMean, ho_DarkPixels, ho_ConnectedRegions_2;
	HObject  ho_SelectedRegions_3, ho_RegionDilation_2, ho_RegionFillUp;
	HTuple  hv_Area, hv_Row, hv_Column, hv_all_area, hv_num, hv_num2, hv_Max, hv_Area2;

	//不同窗口
	MainWindow newwindow;
	settingdialog settingdialog;
	debug debugdialog;
	//函数部分
	void hobjectToQImg(HObject hImg, QImage& img) ;
	void init();
	void readparam();
private:
	Ui::identifyClass ui;
private slots:
	void image();
	void socket_show();
	void setting();
	void debug();
	void slot_change();
	void myslots();
public	slots:
	void getit();

};
