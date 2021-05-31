#include "ScaleLabelDemo.h"
#include <QImage>
#include "MyLabel.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QStandardPaths>
#include <debug.h>
#pragma execution_character_set("utf-8")

ScaleLabelDemo::ScaleLabelDemo(QWidget *parent)
	: QMainWindow(parent)
{	

	QWidget::update();
	void openImage();
	m_pCenterWgt = new QWidget(this);
	m_pMyLabel = new MyLabel(this);
	m_pOpenBtn = new QPushButton("Ë¢ÐÂ", this);
	m_pSaveBtn = new QPushButton("±£´æ", this);
	connect(m_pOpenBtn, &QPushButton::clicked, this, &ScaleLabelDemo::openImage);
	connect(m_pSaveBtn, &QPushButton::clicked, this, &ScaleLabelDemo::saveROI);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(m_pOpenBtn);
	mainLayout->addWidget(m_pSaveBtn);
	mainLayout->addWidget(m_pMyLabel);

	mainLayout->addStretch();
	m_pCenterWgt->setLayout(mainLayout);

	this->setCentralWidget(m_pCenterWgt);
	this->resize(800, 600);
}
ScaleLabelDemo::~ScaleLabelDemo()
{
	delete m_pCenterWgt;
}
void ScaleLabelDemo::openImage()
{
	//QString fileName = QFileDialog::getOpenFileName(this, "open", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), "image (*.bmp *.png *.jpg)");

	//if (fileName.isEmpty())
	//{
	//	return;
	//}

	QImage image(qtFilePath);
	m_pMyLabel->setBackImage(image);
}
void ScaleLabelDemo::saveROI()
{
	//QString fileName = QFileDialog::getOpenFileName(this, "open", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), "image (*.bmp *.png *.jpg)");

	//if (fileName.isEmpty())
	//{
	//	return;
	//}
	m_pMyLabel->saveROIImage();
	QMessageBox::information(this, "save", QStringLiteral("OK"));
	
}
void ScaleLabelDemo::closeEvent(QCloseEvent *event)
{
	

}