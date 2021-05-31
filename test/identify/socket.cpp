#pragma execution_character_set("utf-8")
#include "socket.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket();

	QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
	QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);
	ui.label_IP->setText("127.0.0.1");
	ui.label_port->setText("8765");

}

//MainWindow::~MainWindow()
//{
//	delete this->socket;
//
//}
void MainWindow::on_pushButton_Connect_clicked()
{
	if (ui.pushButton_connect->text() == tr("����"))
	{
		QString IP;
		int port;


		IP = ui.label_IP->text();
		port = ui.label_port->text().toInt();
		socket->abort();
		socket->connectToHost(IP, port);
		ui.pushButton_connect->setText("�Ͽ�����");
	}
	else
	{
		//�Ͽ�����
		socket->disconnectFromHost();
		//�޸İ�������
		ui.pushButton_connect->setText("����");
		ui.pushButton_send->setEnabled(false);
	}
}

void MainWindow::on_pushButton_Send_clicked()
{

	socket->write(ui.plainTextEdit_sendData->toPlainText().toLatin1());
	socket->flush();
}

void MainWindow::socket_Read_Data()
{
	QByteArray buffer;
	//��ȡ����������
	buffer = socket->readAll();
	if (!buffer.isEmpty())
	{
		QString str = ui.plainTextEdit_receiveData->toPlainText();
		str += tr(buffer);
		//ˢ����ʾ
		ui.plainTextEdit_receiveData->setPlainText(str);
	}
}

void MainWindow::socket_Disconnected()
{
	//���Ͱ���ʧ��
	ui.pushButton_send->setEnabled(false);
	//�޸İ�������
	ui.pushButton_connect->setText("����");

}
void MainWindow::socket_Clean()
{
	ui.plainTextEdit_receiveData->setPlainText("");
}