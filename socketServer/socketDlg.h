#ifndef SOCKETDLG_H
#define SOCKETDLG_H

#include <QDialog>
#include "ui_socketDlg.h"
#include <IServer.h>
#include <QTcpSocket>
#include <QHostAddress>
class socketDlg : public QDialog
{
	Q_OBJECT

public:
	socketDlg(QWidget *parent = Q_NULLPTR);
	~socketDlg();

private:
	Ui::socketDlg ui;
	IServer* m_server;
	IServer* m_socket;


private slots:
	void on_pushButton_listen_clicked();
	void on_pushButton_send_clicked();
	void slot_receiveDataAll(QByteArray data);
	void slot_newConnect();
	void slot_disconnect();
	void slot_beat();


	void on_pushButton_Connect_clicked();


};

#endif


