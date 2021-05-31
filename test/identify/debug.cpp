#include "debug.h"
#include "debug_param.h"
#include "identify.h "
QString qtFilePath;
#pragma execution_character_set("utf-8")

debug::debug(QWidget *parent)
	: QMainWindow(parent)
{

	//m_ischane = true;
	readini();
	ui.setupUi(this);
	getparam();

	connect(this, SIGNAL(debug::mysignals()), this, SLOT(debug::isok()), Qt::QueuedConnection);

}
void debug::debugparam()
{

	if (QStringLiteral("open") == ui.pushButton->text())
	{
		 qtFilePath = QFileDialog::getOpenFileName(this, "选择图片", "./", "图像文件(*.jpg *.png *.bmp *.tif)");

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
		if (m_roiRect_topLeft_x == m_roiRect_topLeft_y)
		{
			GenRectangle1(&ho_ROI_0, 271.5, 611.5, 621.5, 1001.5);
			//ui.ROILT->setPlaceholderText("271.5");
		}
		else{
			GenRectangle1(&ho_ROI_0, m_roiRect_topLeft_y, m_roiRect_topLeft_x, m_roiRect_bottomLeft_y, m_roiRect_bottomLeft_x);
			//ui.ROILT->setPlaceholderText(QString::number(m_roiRect_topLeft_x, '.', 0));
			//ui.ROIRT->setPlaceholderText(QString::number(m_roiRect_topLeft_y, '.', 0));
			//ui.ROILD->setPlaceholderText(QString::number(m_roiRect_bottomLeft_x, '.', 0));
			//ui.ROIRD->setPlaceholderText(QString::number(m_roiRect_bottomLeft_y, '.', 0));
		}

		ReduceDomain(ho_Image, ho_ROI_0, &ho_ImageReduced);
		//阈值需要调节
		Threshold(ho_ImageReduced, &ho_Region, Threshold1_min_vaule, Threshold1_max_vaule);
		OpeningRectangle1(ho_Region, &ho_RegionOpening, 5, 5);
		Connection(ho_RegionOpening, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "circularity", "and", circularity_min_vaule,
			circularity_max_vaule);
		SelectShape(ho_SelectedRegions, &ho_SelectedRegions2, "area", "and", 5000, 100000);
		ShapeTrans(ho_SelectedRegions2, &ho_RegionTrans, "outer_circle");
		ErosionRectangle1(ho_RegionTrans, &ho_shape, 16, 16);
		DilationCircle(ho_shape, &ho_RegionDilation, 1.5);
		Union1(ho_shape, &ho_RegionUnion);
		ReduceDomain(ho_Image, ho_RegionUnion, &ho_ImageReduced_3);


		MeanImage(ho_ImageReduced_3, &ho_ImageMean, 5, 5);
		//阈值需要调节
		Threshold(ho_ImageMean, &ho_DarkPixels, Threshold2_min_vaule, Threshold2_max_vaule);
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
			if (area1>first_select_vaule)
			{



				AreaCenter(ho_SelectedRegions_3, &hv_Area, &hv_Row, &hv_Column);
				hv_all_area = hv_Area.TupleSum();
				//				data2 = hv_all_area.D();

				if (hv_all_area > second_select_vaule)
				{

					//ui.plainTextEdit->cursorRect().left();
					////			ui.plainTextEdit->appendPlainText("协议：" + protocolName(aHost.protocol()));
					//ui.plainTextEdit->appendPlainText(currentDate + ":" + "出现异常");
					hobjectToQImg(ho_RegionDilation_2, to_new);
					QImage igScaled = to_new.scaled(ui.graphicsView->width(), ui.graphicsView->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
					QGraphicsScene *scene = new QGraphicsScene;
					scene->addPixmap(QPixmap::fromImage(igScaled));
					ui.graphicsView->setScene(scene);
					ui.graphicsView->show();
				}
				else
				{
					//ui.plainTextEdit->cursorRect().left();
					////			ui.plainTextEdit->appendPlainText("协议：" + protocolName(aHost.protocol()));
					//ui.plainTextEdit->appendPlainText(currentDate + ":" + "未检测异常");

				}

				ui.pushButton->setText(QStringLiteral("open"));
				return;
			}
			else
			{
				//ui.plainTextEdit->appendPlainText(currentDate + ":" + "请检查ROI区域");

				ui.pushButton->setText(QStringLiteral("open"));
				return;
			}
		}
		ui.pushButton->setText(QStringLiteral("open"));
	}

}
void debug::hobjectToQImg(HObject hImg, QImage& to)
{
	ptr = nullptr;
	ConvertImageType(hImg, &hImg, "byte");
	GetImagePointer1(hImg, &hv_pointer, &htype, &o_width, &o_height);
	ptr = (unsigned char *)hv_pointer[0].L();
	to = QImage(ptr, o_width, o_height, o_width, QImage::Format_Indexed8);
}
void debug::getparam()
{

	ui.Threshold1_min->setPlaceholderText(QString::number(Threshold1_min_vaule, '.', 0));
	ui.Threshold1_max->setPlaceholderText(QString::number(Threshold1_max_vaule, '.', 0));
	ui.Threshold2_min->setPlaceholderText(QString::number(Threshold2_min_vaule, '.', 0));
	ui.Threshold2_max->setPlaceholderText(QString::number(Threshold2_max_vaule, '.', 0));
	ui.circularity_min->setPlaceholderText(QString::number(circularity_min_vaule, '.', 1));
	ui.circularity_max->setPlaceholderText(QString::number(circularity_max_vaule, '.', 1));
	ui.area1->setPlaceholderText(QString::number(first_select_vaule, '.', 0));
	ui.area2->setPlaceholderText(QString::number(second_select_vaule, '.', 0));

}
void debug::getRoi()
{
	
	ScaleLabelDemo_new.show();
	
}
void debug::change()
{
	if (QStringLiteral("change") == ui.pushButton_change->text())
	{
//		QString a = ui.Threshold1_min->text();
		ui.Threshold1_min->setReadOnly(FALSE);
		ui.Threshold1_max->setReadOnly(FALSE);
		ui.area1->setReadOnly(FALSE);
		ui.area2->setReadOnly(FALSE);
		ui.circularity_max->setReadOnly(FALSE);
		ui.circularity_min->setReadOnly(FALSE);
		ui.Threshold2_max->setReadOnly(FALSE);
		ui.Threshold2_min->setReadOnly(FALSE);
	//	ui.pushButton_roi->isCheckable();
		ui.pushButton_change->setText(QStringLiteral("save"));
	}
	else if (QStringLiteral("save") == ui.pushButton_change->text())
	{
		Threshold1_min_vaule = ui.Threshold1_min->text().toDouble();
		Threshold1_max_vaule = ui.Threshold1_max->text().toDouble();
		Threshold2_min_vaule = ui.Threshold2_min->text().toDouble();
		Threshold2_max_vaule = ui.Threshold2_max->text().toDouble();
		circularity_min_vaule = ui.circularity_min->text().toDouble();
		circularity_max_vaule = ui.circularity_max->text().toDouble();
		first_select_vaule = ui.area1->text().toDouble();
		second_select_vaule = ui.area2->text().toDouble();


		ui.Threshold1_min->setReadOnly(TRUE);
		ui.Threshold1_max->setReadOnly(TRUE);
		ui.area1->setReadOnly(TRUE);
		ui.area2->setReadOnly(TRUE);
		ui.circularity_max->setReadOnly(TRUE);
		ui.circularity_min->setReadOnly(TRUE);
		ui.Threshold2_max->setReadOnly(TRUE);
		ui.Threshold2_min->setReadOnly(TRUE);
		ui.pushButton_change->setText(QStringLiteral("change"));
		
		
	}
}

void debug::readini()
{
	QSettings* setting = new QSettings("F:/sysParam.ini", QSettings::IniFormat);
	setting->setIniCodec("UTF-8");
	Threshold1_min_vaule= setting->value("halcon/Threshold1_min").toInt();
	Threshold1_max_vaule = setting->value("halcon/Threshold1_max").toInt();
	circularity_min_vaule = setting->value("halcon/circularity_min").toDouble();
	circularity_max_vaule = setting->value("halcon/circularity_max").toDouble();
	Threshold2_min_vaule = setting->value("halcon/Threshold2_min").toInt();
	Threshold2_max_vaule = setting->value("halcon/Threshold2_max").toInt();
	first_select_vaule = setting->value("halcon/first_select").toInt();
	second_select_vaule = setting->value("halcon/second_select").toInt();
	m_roiRect_topLeft_y = setting->value("halcon/x1").toInt();
	m_roiRect_topLeft_x = setting->value("halcon/y1").toInt();
	m_roiRect_bottomLeft_y = setting->value("halcon/x2").toInt();
	m_roiRect_bottomLeft_x = setting->value("halcon/y2").toInt();



}
void debug::closeEvent(QCloseEvent *event)
{
	QMessageBox::StandardButton result = QMessageBox::question(this, "确认", "是否保存參數？",
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		QMessageBox::No);

	if (result == QMessageBox::Yes)
	{
		QSettings* setting = new QSettings("F:/sysParam.ini", QSettings::IniFormat);

		setting->setIniCodec("UTF-8");
		setting->setValue("halcon/Threshold1_min", Threshold1_min_vaule);
		setting->setValue("halcon/Threshold1_max", Threshold1_max_vaule);
		setting->setValue("halcon/first_select", first_select_vaule);
		setting->setValue("halcon/second_select", second_select_vaule);
		setting->setValue("halcon/circularity_max", circularity_max_vaule);
		setting->setValue("halcon/circularity_min", circularity_min_vaule);

		setting->setValue("halcon/x1", m_roiRect_topLeft_y);
		setting->setValue("halcon/y1", m_roiRect_topLeft_x);
		setting->setValue("halcon/x2", m_roiRect_bottomLeft_y);
		setting->setValue("halcon/y2", m_roiRect_bottomLeft_x);
		//emit mysignals();
	}
	else
		{
		printf("don't work");
		//emit mysignals();
		//emit signals_change();
		}

}
//void debug::isok()
//{
//	printf("wokr");
//
//}