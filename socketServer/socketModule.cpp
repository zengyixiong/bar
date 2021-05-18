/*************************
author: WeiKe Yao
date: 2020.11.12
function: tcp/Ip 通讯模块
**************************/
#include "socketModule.h"
#include "QSettings"
#include "sysData.h"
#include "socketDlg.h"
#include "typeDefine.h"


QString Ip = "127.0.0.1";
int port = 4720;
socketModule::socketModule(int id, const QString &name)
	:ModuleBase(id, name)
	, m_server(nullptr)
	, m_client(nullptr)
	,m_connection(false)
{
	loadCfg();
	m_server = new QTcpSocket();
	m_client = new QTcpSocket(this);

	m_server->abort();
	connect(m_server, SIGNAL(newConnection()), this, SLOT(slot_newClient()));

	startListen();
	connect(m_server, SIGNAL(connected()), this, SLOT(slot_connected()));
	QVector<bool> ret;
	connect(m_server, SIGNAL(readyRead()), this, SLOT(slot_recvmessage()));

}

socketModule::~socketModule()
{
	if (nullptr != m_server)
		m_server->close();


}

void socketModule::slot_connected()
{
	m_connection = true;

}
void socketModule::slot_recvmessage()
{
	slot_receiveData();
	printf("work");
}
void socketModule::showCfgDlg()
{
	socketDlg dlg;
	dlg.exec();
}

bool socketModule::startListen()
{
	QString Ip = "127.0.0.1";
	int port = 4720;
	m_server->connectToHost(Ip, port);
	
	if (!m_server->waitForConnected(30000))
	{
		m_connection = 0;
	}
	else
	{
		m_connection = 1;
	}
	return m_connection;
}


void socketModule::disconnection()
{
	if (nullptr != m_server)
		m_server->close();

	m_connection = false;
}

void socketModule::getClientInfo(QString &ip, int &iport)
{

	ip = Ip;
	iport = port;
}

void socketModule::slot_sendData(barsData data)   //识别回复
{
	if (!m_connection)
		return;

	QMutexLocker locker(&m_mutex);

	QByteArray _retData;
	_retData.resize(30);
	_retData.fill('\0');

	char a = 0x4a;
	_retData.replace(0, 1, &a, 1);
	a = 0x47;
	_retData.replace(1, 1, &a, 1); //JG  

	a = 0x33;
	_retData.replace(2, 1, &a, 1);
	a = 0x44;
	_retData.replace(3, 1, &a, 1);  //3D

	a = 0x50;
	_retData.replace(5, 1, &a, 1);
	a = 0x4c;
	_retData.replace(6, 1, &a, 1);
	a = 0x43;
	_retData.replace(7, 1, &a, 1);//PLC

	a = 11;
	_retData.replace(8, 1, &a, 1); //功能码


								   //if (ret.at(0))
								   //{
								   //	a = 0x01;
								   //	_retData.replace(2, 1, &a, 1);
								   //}
								   //else
								   //{
								   //	a = 0x00;
								   //	_retData.replace(2, 1, &a, 1);
								   //}

	QByteArray _data;
	_data = valueToByteArray(data.barsNum);


	if (data.barsNum > 0)
	{
		a = 01;
		_retData.replace(9, 1, &a, 1); //识别成功；

	}
	else
	{
		a = 11;
		_retData.replace(9, 1, &a, 1); //识别失败；
	}


	//焊点1_x坐标
	_data = valueToByteArray(data.x1);
	a = _data.at(0);
	_retData.replace(10, 1, &a, 1);
	a = _data.at(1);
	_retData.replace(11, 1, &a, 1);
	a = _data.at(2);
	_retData.replace(12, 1, &a, 1);
	a = _data.at(3);
	_retData.replace(13, 1, &a, 1);

	//焊点1_y坐标
	_data = valueToByteArray(data.y1);
	a = _data.at(0);
	_retData.replace(14, 1, &a, 1);
	a = _data.at(1);
	_retData.replace(15, 1, &a, 1);
	a = _data.at(2);
	_retData.replace(16, 1, &a, 1);
	a = _data.at(3);
	_retData.replace(17, 1, &a, 1);

	//焊点1_z坐标
	_data = valueToByteArray(data.z1);
	a = _data.at(0);
	_retData.replace(18, 1, &a, 1);
	a = _data.at(1);
	_retData.replace(19, 1, &a, 1);
	a = _data.at(2);
	_retData.replace(20, 1, &a, 1);
	a = _data.at(3);
	_retData.replace(21, 1, &a, 1);



	a = 0x0a;
	_retData.replace(29, 1, &a, 1);

	m_server->write(_retData);
	m_server->waitForBytesWritten();


}



void socketModule::slot_sendWeldRet(QVector<bool> ret) 
{
	QByteArray _data = m_server->readAll();
	emit signal_receiveDataAll(_data);
	if (!m_connection)
		return;

	QMutexLocker locker(&m_mutex);

	QByteArray _retData;
	_retData.resize(30);
	_retData.fill('\0');

	char a = 0x4a;
	_retData.replace(0, 1, &a, 1);
	a = 0x47;
	_retData.replace(1, 1, &a, 1); //JG   2byte

	a = 0x33;
	_retData.replace(2, 1, &a, 1);
	a = 0x44;
	_retData.replace(3, 1, &a, 1);  //3D   3byte

	a = 0x50;
	_retData.replace(5, 1, &a, 1);
	a = 0x4c;
	_retData.replace(6, 1, &a, 1);
	a = 0x43;
	_retData.replace(7, 1, &a, 1);//PLC    3byte

	a = 01;
	_retData.replace(8, 1, &a, 1); //功能码   1byte

	//if (m_pCam->getCamStatus())     //第一个相机
	//{

	//a = 0x01;
	//_retData.replace(9, 1, &a, 1);

	//}
	//else
	//{
	//a = 0x00;
	//_retData.replace(9, 1, &a, 1);

	//}


	//if (m_pCam->getCamStatus())     //第二个相机
	//{

	//a = 0x01;
	//_retData.replace(10, 1, &a, 1);

	//}
	//else
	//{
	//a = 0x00;
	//_retData.replace(10, 1, &a, 1);

	//}



	a = 0x0a;
	_retData.replace(29, 1, &a, 1);

	m_server->write(_retData);
	m_server->waitForBytesWritten();
} //心跳包

void socketModule::sendData(QByteArray data)
{
	QVector<bool> ret;
	barsData data1;
	slot_sendWeldRet(ret);
	slot_sendData(data1);
	m_server->write(data);
}


void socketModule::loadCfg()
{
	QSettings* setting = new QSettings("sysParam/sysParam.ini", QSettings::IniFormat);
	setting->setIniCodec("UTF-8");
	QHostAddress tempIp(setting->value("tcpServer/IP").toString());
	m_IP = tempIp;
	m_port = setting->value("tcpServer/Port").toInt();
}

void socketModule::slot_newClient()
{
	if (m_connection)
		return;

	m_socket = m_server;
	
	m_clientIp = Ip;
	m_clientPort = port;

	connect(m_server, SIGNAL(readyRead()), this, SLOT(slot_receiveData()));
	connect(m_server, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));
	m_connection = true;
	emit signal_newConnect();
}

void socketModule::slot_receiveData()   //接收
{
	QByteArray _data = m_server->readAll();
	emit signal_receiveDataAll(_data);

	int data_type;
	if ('J' == _data.at(0) && ('G' == _data.at(1)) && ('P' == _data.at(2)) && ('L' == _data.at(3)) && ('C' == _data.at(4)) && ('3' == _data.at(5)) && ('D' == _data.at(6)))
	{
		if ('0' == _data.at(8))
			data_type = BEATHEART;        //心跳包
		else if (('1' == _data.at(8)))
			data_type = CHECK_NEED;      //识别需求
	}
	else
	{
		return;
	}

	switch (data_type)
	{
	case BEATHEART://心跳包
	{
		if (0x00 == _data.at(9))   //0=禁用模式
		{

		}
		if (0x01 == _data.at(9))//1=远程模式
		{


		}
		if (0x02 == _data.at(9))//2=维护模式
		{


		}
		printf("recieve1");
	}break;
	case CHECK_NEED://识别需求
	{

		if (0x01 == _data.at(9))//1#3D执行识别；
		{
			m_server->write(_data);
			m_server->waitForBytesWritten();
			QByteArray tempData;
			tempData.clear();
			tempData.append(_data.at(2));
			tempData.append(_data.at(3));
			tempData.append(_data.at(4));
			tempData.append(_data.at(5));
			int weldFlag = 0;
			byteArrayToValue(tempData, weldFlag);
			if (0 == weldFlag)
				m_barsInfor.weldNum = 1;
			else if (1 == weldFlag)
				m_barsInfor.weldNum = 2;

			emit signal_checkBars(m_barsInfor);
			emit signal_dataIn(QStringLiteral("复核信号"), LOG_INFO);
		}
		if (0x02 == _data.at(9))//2#3D执行识别；
		{



		}
		printf("recieve2");
	}break;


	}
	}



bool socketModule::getListenStatus()
{
	return m_connection;
}

bool socketModule::getConnectStatus()
{
	return m_connection;
}

void socketModule::slot_disconnected()
{
	m_connection = false;
	emit signal_disconnect();
}

template<typename T>
QByteArray socketModule::valueToByteArray(T value)
{
	QByteArray res;
	res.resize(4);
	memcpy(res.data(), &value, sizeof(T));
	return res;
}

template<typename T>
void socketModule::byteArrayToValue(QByteArray arr, T& res)
{
	if (arr.size() < 4)
		return;
	QString _type = typeid(T).name();
	if ("int" == _type)
	{
		res = arr.toHex().toInt();
	}
	else if ("float" == _type)
	{
		res = arr.toHex().toFloat();
	}
	else if ("double" == _type)
	{
		res = arr.toHex().toDouble();
	}
}

MOUDLE_INIT(socketModule)