#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include "socketserver_global.h"
#include "IServer.h"
#include "moduleBase.h"
#include <QTcpServer>
#include <QTcpSocket>
#include "param.h"
#include <QMutex>

class SOCKETSERVER_EXPORT socketModule : public IServer, public ModuleBase 
{
	Q_OBJECT
public:
	socketModule(int id, const QString &name);
	~socketModule();
	void releaseRes() { delete this; }

	void showCfgDlg();
	bool startListen();

	void disconnection();
	void getClientInfo(QString &ip, int &port);
	bool getListenStatus();
	bool getConnectStatus();
	void sendData(QByteArray data);

public slots:
	void slot_sendData(barsData data);
	void slot_sendWeldRet(QVector<bool> ret);


private:
	QHostAddress m_IP;
	int m_port;
	QTcpSocket* m_server;
	QTcpSocket* m_socket;
	QTcpSocket* m_client;  //client



	QString m_clientIp;
	int m_clientPort;

	bool m_connection;
	QMutex m_mutex;
	barsInfor m_barsInfor;

private:
	void loadCfg();
	template<typename T>
	QByteArray valueToByteArray(T value);
	template<typename T>
	void byteArrayToValue(QByteArray arr, T& res);
	bool isconnetion;
private slots:
	void slot_newClient();
	void slot_receiveData();
	void slot_disconnected();


	void slot_connected();
	void slot_recvmessage();
signals:

	void signal_newConnect();
	void signal_disconnect();
	void signal_receiveDataAll(QByteArray);

	void signal_beat();
	void signal_checkBars(barsInfor infor);
	void signal_checkWeld(int pos);
	void signal_dataIn(QString str, int type);
};

#endif