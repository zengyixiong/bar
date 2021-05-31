#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_socket.h"
#include <QTcpSocket>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
private slots:
	void on_pushButton_Connect_clicked();

	void on_pushButton_Send_clicked();

	void socket_Read_Data();

	void socket_Disconnected();

	void socket_Clean();
private:
	Ui::MainWindow ui;
	QTcpSocket *socket;

};
#pragma once
