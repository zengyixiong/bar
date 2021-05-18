#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include "param.h"

//������Ϣ
struct barsInfor
{
	int weldNum;
	QString batchNum;
	QString bundleNum;
	int barSpecs;
	int barsNum;

	barsInfor()
	{
		weldNum = 2;
		batchNum = "";
		bundleNum = "";
		barSpecs = 12;
		barsNum = 0;
	}
};

//ʶ������
struct barsData
{
	int barsNum;
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
	float x3;
	float y3;
	float z3;

	barsData()
	{
		barsNum = 0;
		x1 = 0.0;
		y1 = 0.0;
		z1 = 0.0;
		x2 = 0.0;
		y2 = 0.0;
		z2 = 0.0;
		x3 = 0.0;
		y3 = 0.0;
		z3 = 0.0;
	}
};

//ͨѶ���ݸ�ʽ
enum ComunicateDataStruct
{
	BEATHEART,		    //�����ź�
	CHECK_NUM,          //����֧������⺸��
	CHECK_WELDS,        //��⺸��
	CHECK_NEED,
};

class IServer : public QObject
{
public:
	virtual void showCfgDlg() = 0;
	virtual bool startListen() = 0;
	virtual void disconnection() = 0;
	virtual void getClientInfo(QString &ip, int &port) = 0;
	virtual void sendData(QByteArray data) = 0;
	virtual bool getListenStatus() = 0;
	virtual bool getConnectStatus() = 0;
	virtual void releaseRes() = 0;
};

#endif