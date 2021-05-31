#pragma once

#include <QtWidgets/QMainWindow>

class MyLabel;
class QPushButton;

class ScaleLabelDemo : public QMainWindow
{
	Q_OBJECT

public:
	ScaleLabelDemo(QWidget *parent = Q_NULLPTR);
	ScaleLabelDemo::~ScaleLabelDemo();
	void openImage();
	void saveROI();
//	void closeEvent();
protected:
	void closeEvent(QCloseEvent * event);
private slots:


private:
	MyLabel *m_pMyLabel;
	QWidget *m_pCenterWgt;
	QPushButton *m_pOpenBtn;
	QPushButton *m_pSaveBtn;
};
