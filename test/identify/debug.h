#pragma once


#include "ui_debug.h"
#include "Halcon.h"
#include "cpp\HalconCpp.h"
#include "halconcpp\HalconCpp.h"
#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QtGui/qpixmap.h>
#include <QFileDialog>
#include <QFileInfo>
#include <stdio.h>
#include <qmessagebox.h>
#include <QDateTime>
#include <QtWidgets/QMainWindow>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QTextCodec>
#include "MyLabel.h"
#include "ScaleLabelDemo.h"


using namespace HalconCpp;

extern QString qtFilePath;
//extern int Threshold1_min;
//extern int Threshold1_max;
//extern double circularity_min = 0.3;
//extern double circularity_max = 1;
//extern int Threshold2_min = 20;
//extern int Threshold2_max = 80;
//extern int first_select = 30000;
//extern int second_select = 1000;
class debug : public QMainWindow
{
	Q_OBJECT

public:
	debug(QWidget *parent = Q_NULLPTR);

	HTuple m_hLabelID;			//QLabel¿Ø¼þ¾ä±ú
	HTuple m_hHalconID;			//HalconÏÔÊ¾´°¿Ú¾ä±ú
	HTuple hv_name;
	QImage to, to_new;
	HTuple hv_pointer;
	HTuple htype;
	HTuple   o_width, o_height;
	double area1, data2;
	unsigned char *ptr;
	unsigned char *ptr_new;
	HObject  ho_Image, ho_ROI_0, ho_ImageReduced;
	HObject  ho_Region, ho_RegionOpening, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_SelectedRegions2, ho_RegionTrans;
	HObject  ho_shape, ho_RegionDilation, ho_RegionUnion, ho_ImageReduced_3;
	HObject  ho_ImageMean, ho_DarkPixels, ho_ConnectedRegions_2;
	HObject  ho_SelectedRegions_3, ho_RegionDilation_2, ho_RegionFillUp;
	HTuple  hv_Area, hv_Row, hv_Column, hv_all_area, hv_num, hv_num2, hv_Max, hv_Area2;

	void hobjectToQImg(HObject hImg, QImage& to);
	void getparam();
	void readini();
	void closeEvent(QCloseEvent * event);
//	void getRoi();
	ScaleLabelDemo ScaleLabelDemo_new;


	int Threshold1_min_vaule;
	int Threshold1_max_vaule;
	double circularity_min_vaule;
	double circularity_max_vaule;
	int Threshold2_min_vaule;
	int Threshold2_max_vaule;
	int first_select_vaule;
	int second_select_vaule;
private:
	Ui::debugdialog ui;
	MyLabel *m_pMyLabel;
	QWidget *m_pCenterWgt;
	QPushButton *m_pOpenBtn;
	//bool m_ischane = true;

signals:
	//void signals_change();
	//void mysignals();


private slots:
	void debugparam();
	void getRoi();
	void change();
	//void isok();
protected:

};


#pragma once
 
