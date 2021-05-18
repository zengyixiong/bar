/********************************************************************************
** Form generated from reading UI file 'socketDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCKETDLG_H
#define UI_SOCKETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_socketDlg
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_IP;
    QLabel *label;
    QLabel *label_port;
    QLabel *label_status;
    QLabel *label_2;
    QPushButton *pushButton_listen;
    QPushButton *pushButton_connect;
    QPlainTextEdit *plainTextEdit_sendData;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_beat;
    QPushButton *pushButton_send;
    QPlainTextEdit *plainTextEdit_receiveData;
    QLabel *label_5;
    QPushButton *pushButton_clearBeat;
    QPushButton *pushButton_clearReceive;
    QLabel *label_4;
    QPushButton *test;

    void setupUi(QDialog *socketDlg)
    {
        if (socketDlg->objectName().isEmpty())
            socketDlg->setObjectName(QStringLiteral("socketDlg"));
        socketDlg->resize(784, 558);
        gridLayout_3 = new QGridLayout(socketDlg);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(socketDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_IP = new QLabel(groupBox);
        label_IP->setObjectName(QStringLiteral("label_IP"));
        label_IP->setFont(font);

        gridLayout->addWidget(label_IP, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_port = new QLabel(groupBox);
        label_port->setObjectName(QStringLiteral("label_port"));
        label_port->setFont(font);

        gridLayout->addWidget(label_port, 1, 1, 1, 1);

        label_status = new QLabel(groupBox);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setFont(font);

        gridLayout->addWidget(label_status, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        pushButton_listen = new QPushButton(groupBox);
        pushButton_listen->setObjectName(QStringLiteral("pushButton_listen"));
        pushButton_listen->setFont(font);

        gridLayout->addWidget(pushButton_listen, 3, 1, 1, 1);

        pushButton_connect = new QPushButton(groupBox);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        gridLayout->addWidget(pushButton_connect, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 2, 3);

        plainTextEdit_sendData = new QPlainTextEdit(socketDlg);
        plainTextEdit_sendData->setObjectName(QStringLiteral("plainTextEdit_sendData"));
        plainTextEdit_sendData->setFont(font);

        gridLayout_3->addWidget(plainTextEdit_sendData, 1, 3, 1, 2);

        label_3 = new QLabel(socketDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 0, 3, 1, 1);

        plainTextEdit_beat = new QPlainTextEdit(socketDlg);
        plainTextEdit_beat->setObjectName(QStringLiteral("plainTextEdit_beat"));
        plainTextEdit_beat->setFont(font);
        plainTextEdit_beat->setReadOnly(true);

        gridLayout_3->addWidget(plainTextEdit_beat, 4, 0, 1, 3);

        pushButton_send = new QPushButton(socketDlg);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMaximumSize(QSize(150, 16777215));
        pushButton_send->setFont(font);

        gridLayout_3->addWidget(pushButton_send, 2, 4, 2, 1);

        plainTextEdit_receiveData = new QPlainTextEdit(socketDlg);
        plainTextEdit_receiveData->setObjectName(QStringLiteral("plainTextEdit_receiveData"));
        plainTextEdit_receiveData->setFont(font);
        plainTextEdit_receiveData->setReadOnly(true);

        gridLayout_3->addWidget(plainTextEdit_receiveData, 4, 3, 1, 2);

        label_5 = new QLabel(socketDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        pushButton_clearBeat = new QPushButton(socketDlg);
        pushButton_clearBeat->setObjectName(QStringLiteral("pushButton_clearBeat"));
        pushButton_clearBeat->setMaximumSize(QSize(150, 16777215));
        pushButton_clearBeat->setFont(font);

        gridLayout_3->addWidget(pushButton_clearBeat, 6, 2, 1, 1);

        pushButton_clearReceive = new QPushButton(socketDlg);
        pushButton_clearReceive->setObjectName(QStringLiteral("pushButton_clearReceive"));
        pushButton_clearReceive->setMinimumSize(QSize(150, 0));
        pushButton_clearReceive->setFont(font);

        gridLayout_3->addWidget(pushButton_clearReceive, 6, 4, 1, 1);

        label_4 = new QLabel(socketDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 3, 3, 1, 1);

        test = new QPushButton(socketDlg);
        test->setObjectName(QStringLiteral("test"));

        gridLayout_3->addWidget(test, 6, 0, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);

        retranslateUi(socketDlg);
        QObject::connect(pushButton_clearReceive, SIGNAL(clicked()), plainTextEdit_receiveData, SLOT(clear()));
        QObject::connect(pushButton_connect, SIGNAL(clicked()), socketDlg, SLOT(on_pushButton_Connect_clicked()));

        QMetaObject::connectSlotsByName(socketDlg);
    } // setupUi

    void retranslateUi(QDialog *socketDlg)
    {
        socketDlg->setWindowTitle(QApplication::translate("socketDlg", "\351\200\232\350\256\257\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("socketDlg", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_6->setText(QApplication::translate("socketDlg", "    \347\253\257\345\217\243\357\274\232", nullptr));
        label_IP->setText(QString());
        label->setText(QApplication::translate("socketDlg", "  \350\277\236\346\216\245IP\357\274\232", nullptr));
        label_port->setText(QString());
        label_status->setText(QString());
        label_2->setText(QApplication::translate("socketDlg", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_listen->setText(QApplication::translate("socketDlg", "\347\233\221\345\220\254", nullptr));
        pushButton_connect->setText(QApplication::translate("socketDlg", "connect", nullptr));
        label_3->setText(QApplication::translate("socketDlg", "\345\217\221\351\200\201\345\206\205\345\256\271\357\274\210\345\215\201\345\205\255\350\277\233\345\210\266\357\274\211\357\274\232", nullptr));
        pushButton_send->setText(QApplication::translate("socketDlg", "\345\217\221\351\200\201", nullptr));
        label_5->setText(QApplication::translate("socketDlg", "\345\277\203\350\267\263\357\274\232", nullptr));
        pushButton_clearBeat->setText(QApplication::translate("socketDlg", "\346\270\205\347\251\272\345\277\203\350\267\263", nullptr));
        pushButton_clearReceive->setText(QApplication::translate("socketDlg", "\346\270\205\347\251\272\346\216\245\345\217\227\345\206\205\345\256\271", nullptr));
        label_4->setText(QApplication::translate("socketDlg", "\346\216\245\345\217\227\345\206\205\345\256\271\357\274\210\345\215\201\345\205\255\350\277\233\345\210\266\357\274\211\357\274\232", nullptr));
        test->setText(QApplication::translate("socketDlg", "test2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class socketDlg: public Ui_socketDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCKETDLG_H
