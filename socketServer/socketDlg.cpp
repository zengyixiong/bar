#include "socketDlg.h"
#include "ModuleMgr.h"
#include "ModuleId.h"
#include <QDateTime>

socketDlg::socketDlg(QWidget *parent)
	: QDialog(parent)
	, m_server(nullptr)
{
	ui.setupUi(this);
	QIcon icon = QIcon("./image/JG.ico");
	setWindowIcon(icon);
	m_server = getModule<IServer>(SOCKET_MODULE);

	this->setStyleSheet("QDialog{background-color: aliceblue;}");

	connect(m_server, SIGNAL(signal_newConnect()), this, SLOT(slot_newConnect()));
	connect(m_server, SIGNAL(signal_beat()), this, SLOT(slot_beat()));
	connect(m_server, SIGNAL(signal_receiveDataAll(QByteArray)), this, SLOT(slot_receiveDataAll(QByteArray)));
	connect(m_server, SIGNAL(signal_disconnect()), this, SLOT(slot_disconnect()));

	connect(ui.test, SIGNAL(clicked()), this, SLOT(on_pushButton_Send_clicked()));

	if (m_server->getListenStatus())
	{
		if (m_server->getConnectStatus())
		{
			QString Ip;
			int port;
			m_server->getClientInfo(Ip, port);
			ui.label_IP->setText(Ip);
			ui.label_port->setText(QString::number(port));
			ui.label_status->setText(QStringLiteral("¼àÌýÖÐ..."));
		}
		else
		{
			ui.label_status->setText(QStringLiteral("¼àÌýÖÐ..."));
			ui.label_IP->setText("");
			ui.label_port->setText("");
		}
		ui.pushButton_listen->setText(QStringLiteral("¶Ï¿ª"));
	}
	else
	{
		ui.label_status->setText(QStringLiteral("Î´¼àÌý"));
		ui.pushButton_listen->setText(QStringLiteral("¼àÌý"));
		ui.label_IP->setText("");
		ui.label_port->setText("");
	}

}

socketDlg::~socketDlg()
{
}


void socketDlg::on_pushButton_Connect_clicked()
{
	if (ui.pushButton_connect->text() == tr("connect"))
	{
		QString Ip = "192.168.150.126";
		int port = 4720;

		ui.pushButton_send->setEnabled(true);
		//ÐÞ¸Ä°´¼üÎÄ×Ö
		ui.pushButton_connect->setText("unconnect");
	}
	else
	{
		m_server->disconnection();
		ui.pushButton_connect->setText("connect");
		ui.pushButton_send->setEnabled(false);
		ui.label_IP->setText("");
		ui.label_port->setText("");
		return;
	}

	if (m_server->startListen())
	{
		ui.label_IP->setText("192.168.0.1");
		ui.label_port->setText("4720");
		ui.label_status->setText(QStringLiteral("Á¬½ÓÖÐ..."));
	}
	else
	{
		ui.label_IP->setText("");
		ui.label_port->setText("");
		ui.label_status->setText(QStringLiteral("Ê§°ÜÖÐ..."));
	}
}




 void socketDlg::on_pushButton_listen_clicked()
{
	 if (QStringLiteral("¶Ï¿ª") == ui.pushButton_listen->text())
	 {
		 ui.label_IP->setText("");
		 ui.label_port->setText("");
	     ui.label_status->setText(QStringLiteral("Î´¼àÌý"));
		 ui.pushButton_listen->setText(QStringLiteral("¼àÌý"));
		 m_server->disconnection();
		 return;
	 }

	if (m_server->startListen())
	{
		ui.label_status->setText(QStringLiteral("¼àÌýÖÐ..."));
		ui.pushButton_listen->setText(QStringLiteral("¶Ï¿ª"));

		if (m_server->getConnectStatus())
		{
			QString Ip;
			int port;
			m_server->getClientInfo(Ip, port);
			ui.label_IP->setText(Ip);
			ui.label_port->setText(QString::number(port));
		}
	}
	else
	{
		ui.label_IP->setText("");
		ui.label_port->setText("");
		ui.label_status->setText(QStringLiteral("¼àÌýÊ§°Ü"));
	}
}

 void socketDlg::slot_newConnect()
 {
	 QString Ip;
	 int port;
	 m_server->getClientInfo(Ip, port);
	 ui.label_IP->setText(Ip);
	 ui.label_port->setText(QString::number(port));
	 ui.label_status->setText(QStringLiteral("¼àÌýÖÐ..."));
 }

 void socketDlg::slot_disconnect()
 {
	 if (m_server->getListenStatus())
	 {
		 ui.label_status->setText(QStringLiteral("¼àÌýÖÐ..."));
		 ui.pushButton_listen->setText(QStringLiteral("¶Ï¿ª"));
	 }
	 else
	 {
		 ui.label_IP->setText("");
		 ui.label_port->setText("");
		 ui.label_status->setText(QStringLiteral("Î´¼àÌý"));
		 ui.pushButton_listen->setText(QStringLiteral("¼àÌý"));
	 }
	 ui.label_IP->setText("");
	 ui.label_port->setText("");
 }

 void socketDlg::slot_beat()
 {
	 QDateTime currentDateTime = QDateTime::currentDateTime();
	 QString currentDate = currentDateTime.toString("hh:mm:ss:z");
	 ui.plainTextEdit_beat->appendPlainText(currentDate);
 }

 void socketDlg::slot_receiveDataAll(QByteArray data)
 {

	 QByteArray hex = data.toHex();
	 ui.plainTextEdit_receiveData->appendPlainText(hex);
 }

 void socketDlg::on_pushButton_send_clicked()
 {
	 QByteArray inData = ui.plainTextEdit_sendData->toPlainText().toLatin1();
	 QByteArray str2 = QByteArray::fromHex(ui.plainTextEdit_sendData->toPlainText().toLatin1().data());
	 m_server->sendData(str2);
	 
 }