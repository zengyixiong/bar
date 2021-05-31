#include "identify.h"


#pragma execution_character_set("utf-8")
identify::identify(QWidget *parent)
	: QMainWindow(parent)
{
	QWidget::update();
	ui.setupUi(this);
	init();
	//connect(this, SIGNAL(signals_change()), this, SLOT(slot_change()));
	//connect(this, SIGNAL(debug::mysignals()), this, SLOT(myslots()));

}
void identify::init()
{
	ui.menuBar->addAction("相机设置", this, SLOT());
	ui.menuBar->addAction("通讯设置", this, SLOT(socket_show()));
	ui.menuBar->addAction("系统设置", this, SLOT(setting()));

	QIcon icon = QIcon("F:/study/study_write/vs_write/identify/image/JG.ico");
	setWindowIcon(icon);
	m_greenLed.load("F:/study/study_write/vs_write/identify/image/Led Green.png");
	m_redLed.load("F:/study/study_write/vs_write/identify/image/Led Red.png");
	m_yellowLed.load("F:/study/study_write/vs_write/identify/image/Led Yellow.png");
	ui.label_camStatus->setPixmap(m_redLed);
	ui.label_clientStatus->setPixmap(m_redLed);;
	readparam();
}
void identify::image()
{

	if (QStringLiteral("open") == ui.pushButton->text())
	{
		QString qtFilePath = QFileDialog::getOpenFileName(this, "选择图片", "./", "图像文件(*.jpg *.png *.bmp *.tif)");

		if (qtFilePath.isEmpty())
		{

			QMessageBox::information(this, "ERROR", QStringLiteral("取图失败"));

			return;

		}

		hv_name = qtFilePath.toStdString().c_str();
		ReadImage(&ho_Image, hv_name);
		GetImageSize(ho_Image, &o_width, &o_height);
		hobjectToQImg(ho_Image, to);
		QImage igScaled = to.scaled(ui.graphicsView->width(), ui.graphicsView->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		QGraphicsScene *scene = new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(igScaled));
		ui.graphicsView->setScene(scene);
		ui.graphicsView->show();
		ui.pushButton->setText(QStringLiteral("run"));
		return;
	}
	else
	{
		readparam();
		GenRectangle1(&ho_ROI_0, 271.5, 611.5, 621.5, 1001.5);//
		ReduceDomain(ho_Image, ho_ROI_0, &ho_ImageReduced);
		//阈值需要调节
		Threshold(ho_ImageReduced, &ho_Region, 60, 255);
		OpeningRectangle1(ho_Region, &ho_RegionOpening, 5, 5);
		Connection(ho_RegionOpening, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "circularity", "and", 0.3,
			1);
		SelectShape(ho_SelectedRegions, &ho_SelectedRegions2, "area", "and", 5000, 100000);
		ShapeTrans(ho_SelectedRegions2, &ho_RegionTrans, "outer_circle");
		ErosionRectangle1(ho_RegionTrans, &ho_shape, 16, 16);
		DilationCircle(ho_shape, &ho_RegionDilation, 1.5);
		Union1(ho_shape, &ho_RegionUnion);
		ReduceDomain(ho_Image, ho_RegionUnion, &ho_ImageReduced_3);


		MeanImage(ho_ImageReduced_3, &ho_ImageMean, 5, 5);
		//阈值需要调节
		Threshold(ho_ImageMean, &ho_DarkPixels, 20, 80);
		Connection(ho_DarkPixels, &ho_ConnectedRegions_2);
		SelectShape(ho_ConnectedRegions_2, &ho_SelectedRegions_3, "area", "and", 100, 50000);
		DilationCircle(ho_SelectedRegions_3, &ho_RegionDilation_2, 1.5);
		RegionToBin(ho_RegionDilation_2, &ho_RegionDilation_2, 255, 0, o_width, o_height);

		QDateTime currentDateTime = QDateTime::currentDateTime();
		QString currentDate = currentDateTime.toString("MM.dd.hh.mm.ss");
		CountObj(ho_SelectedRegions2, &hv_num);
		AreaCenter(ho_SelectedRegions2, &hv_Area, &hv_Row, &hv_Column);
		hv_all_area = hv_Area.TupleSum();
		area1 = hv_all_area.TupleReal();
//			hv_all_area.D();
		if (hv_num > 0)
		{
			if (area1>30000)
			{



				AreaCenter(ho_SelectedRegions_3, &hv_Area, &hv_Row, &hv_Column);
				hv_all_area = hv_Area.TupleSum();
				//				data2 = hv_all_area.D();

				if (hv_all_area > 1000)
				{

					ui.plainTextEdit->cursorRect().left();
					//			ui.plainTextEdit->appendPlainText("协议：" + protocolName(aHost.protocol()));
					ui.plainTextEdit->appendPlainText(currentDate + ":" + "出现异常");
					hobjectToQImg(ho_RegionDilation_2, to_new);
					QImage igScaled = to_new.scaled(ui.graphicsView->width(), ui.graphicsView->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
					QGraphicsScene *scene = new QGraphicsScene;
					scene->addPixmap(QPixmap::fromImage(igScaled));
					ui.graphicsView->setScene(scene);
					ui.graphicsView->show();
				}
				else
				{
					ui.plainTextEdit->cursorRect().left();
					//			ui.plainTextEdit->appendPlainText("协议：" + protocolName(aHost.protocol()));
					ui.plainTextEdit->appendPlainText(currentDate + ":" + "未检测异常");

				}

				ui.pushButton->setText(QStringLiteral("open"));
				return;
			}
			else
			{
				ui.plainTextEdit->appendPlainText(currentDate + ":" + "请检查ROI区域");

				ui.pushButton->setText(QStringLiteral("open"));
				return;
			}
		}
		}
		
}
void identify::hobjectToQImg(HObject hImg, QImage& to)
{	
	ptr = nullptr;
	ConvertImageType(hImg, &hImg, "byte");
	GetImagePointer1(hImg, &hv_pointer, &htype, &o_width, &o_height);
	ptr = (unsigned char *)hv_pointer[0].L();
	to = QImage(ptr, o_width, o_height, o_width, QImage::Format_Indexed8);
}
void identify::socket_show()
{
	newwindow.show();
}
void identify::setting()
{
	settingdialog.show();
}

void identify::debug()
{
	debugdialog.show();
}
void  identify::readparam()
{
	QSettings* setting = new QSettings("F:/sysParam.ini", QSettings::IniFormat);
	setting->setIniCodec("UTF-8");
	int Threshold1_min, Threshold1_max, Threshold2_min, Threshold2_max, first_select, second_select;
	double circularity_min, circularity_max;
	Threshold1_min= setting->value("halcon/Threshold1_min").toInt();
	 Threshold1_max = setting->value("halcon/Threshold1_max").toInt();
	 circularity_min = setting->value("halcon/circularity_min").toDouble();
	 circularity_max = setting->value("halcon/circularity_max").toDouble();
	 Threshold2_min = setting->value("halcon/Threshold2_min").toInt();
	 Threshold2_max = setting->value("halcon/Threshold2_max").toInt();
	 first_select = setting->value("halcon/first_select").toInt();
	 second_select = setting->value("halcon/second_select").toInt();
	m_roiRect_topLeft_y = setting->value("halcon/x1").toInt();
	m_roiRect_topLeft_x = setting->value("halcon/y1").toInt();
	m_roiRect_bottomLeft_y = setting->value("halcon/x2").toInt();
	m_roiRect_bottomLeft_x = setting->value("halcon/y2").toInt();
}
void  identify::slot_change()
{
	int a;
}
void  identify::getit()
{
	int a;
}
void identify::myslots()
{
	printf("ok");
	ui.plainTextEdit->appendPlainText( "未检测异常");

}