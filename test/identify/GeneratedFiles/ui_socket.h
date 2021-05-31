/********************************************************************************
** Form generated from reading UI file 'socket.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKET_H
#define UI_SOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QLabel *label_IP;
    QLabel *label;
    QLabel *label_port;
    QLabel *label_status_2;
    QLabel *label_2;
    QPushButton *pushButton_listen_2;
    QPushButton *pushButton_connect;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_sendData;
    QLabel *label_4;
    QPushButton *pushButton_send;
    QPlainTextEdit *plainTextEdit_receiveData;
    QPushButton *pushButton_clearReceive;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(788, 616);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        label_IP = new QLabel(groupBox);
        label_IP->setObjectName(QStringLiteral("label_IP"));
        label_IP->setFont(font);

        gridLayout_4->addWidget(label_IP, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_port = new QLabel(groupBox);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setFont(font);

        gridLayout_4->addWidget(label_port, 1, 1, 1, 1);

        label_status_2 = new QLabel(groupBox);
        label_status_2->setObjectName(QStringLiteral("label_status_2"));
        label_status_2->setFont(font);

        gridLayout_4->addWidget(label_status_2, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        pushButton_listen_2 = new QPushButton(groupBox);
        pushButton_listen_2->setObjectName(QStringLiteral("pushButton_listen_2"));
        pushButton_listen_2->setFont(font);

        gridLayout_4->addWidget(pushButton_listen_2, 3, 1, 1, 1);

        pushButton_connect = new QPushButton(groupBox);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        gridLayout_4->addWidget(pushButton_connect, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 2, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        plainTextEdit_sendData = new QPlainTextEdit(centralwidget);
        plainTextEdit_sendData->setObjectName(QStringLiteral("plainTextEdit_sendData"));
        plainTextEdit_sendData->setFont(font);

        gridLayout->addWidget(plainTextEdit_sendData, 1, 1, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        pushButton_send = new QPushButton(centralwidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMaximumSize(QSize(150, 16777215));
        pushButton_send->setFont(font);

        gridLayout->addWidget(pushButton_send, 2, 2, 1, 1);

        plainTextEdit_receiveData = new QPlainTextEdit(centralwidget);
        plainTextEdit_receiveData->setObjectName(QStringLiteral("plainTextEdit_receiveData"));
        plainTextEdit_receiveData->setFont(font);
        plainTextEdit_receiveData->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit_receiveData, 3, 1, 1, 2);

        pushButton_clearReceive = new QPushButton(centralwidget);
        pushButton_clearReceive->setObjectName(QStringLiteral("pushButton_clearReceive"));
        pushButton_clearReceive->setMinimumSize(QSize(150, 0));
        pushButton_clearReceive->setFont(font);

        gridLayout->addWidget(pushButton_clearReceive, 4, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 788, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_connect, SIGNAL(clicked()), MainWindow, SLOT(on_pushButton_Connect_clicked()));
        QObject::connect(pushButton_send, SIGNAL(clicked()), MainWindow, SLOT(on_pushButton_Send_clicked()));
        QObject::connect(pushButton_clearReceive, SIGNAL(clicked()), MainWindow, SLOT(socket_Clean()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "    \347\253\257\345\217\243\357\274\232", nullptr));
        label_IP->setText(QString());
        label->setText(QApplication::translate("MainWindow", "  \350\277\236\346\216\245IP\357\274\232", nullptr));
        label_port->setText(QString());
        label_status_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_listen_2->setText(QApplication::translate("MainWindow", "\347\233\221\345\220\254", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\206\205\345\256\271\357\274\210\345\215\201\345\205\255\350\277\233\345\210\266\357\274\211\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\216\245\345\217\227\345\206\205\345\256\271\357\274\210\345\215\201\345\205\255\350\277\233\345\210\266\357\274\211\357\274\232", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton_clearReceive->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\345\217\227\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKET_H
