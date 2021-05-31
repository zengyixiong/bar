#include "ScaleLabelDemo.h"
#include "identify.h"
#include <QtWidgets/QApplication>
#include<QTextCodec> 
#include <QSettings>
#include <QTextCodec>
#include "debug_param.h"
int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	identify w;
	w.show();
	return a.exec();


	//QApplication a(argc, argv);
	//ScaleLabelDemo w;
	//w.show();
	//return a.exec();
}
