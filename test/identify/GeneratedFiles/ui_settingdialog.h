/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingdialog
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_modify;
    QSpinBox *spinBox_imgExistDays;
    QLabel *label2;
    QLabel *label1;
    QSpinBox *spinBox_logExistDays;
    QCheckBox *checkBox_debugMode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *settingdialog)
    {
        if (settingdialog->objectName().isEmpty())
            settingdialog->setObjectName(QStringLiteral("settingdialog"));
        settingdialog->resize(423, 349);
        centralwidget = new QWidget(settingdialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_modify = new QPushButton(centralwidget);
        pushButton_modify->setObjectName(QStringLiteral("pushButton_modify"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(14);
        pushButton_modify->setFont(font);

        gridLayout->addWidget(pushButton_modify, 4, 2, 1, 1);

        spinBox_imgExistDays = new QSpinBox(centralwidget);
        spinBox_imgExistDays->setObjectName(QStringLiteral("spinBox_imgExistDays"));
        spinBox_imgExistDays->setFont(font);
        spinBox_imgExistDays->setMinimum(1);
        spinBox_imgExistDays->setMaximum(1000);
        spinBox_imgExistDays->setValue(30);

        gridLayout->addWidget(spinBox_imgExistDays, 0, 2, 1, 1);

        label2 = new QLabel(centralwidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setFont(font);

        gridLayout->addWidget(label2, 1, 0, 1, 2);

        label1 = new QLabel(centralwidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setFont(font);

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        spinBox_logExistDays = new QSpinBox(centralwidget);
        spinBox_logExistDays->setObjectName(QStringLiteral("spinBox_logExistDays"));
        spinBox_logExistDays->setFont(font);
        spinBox_logExistDays->setMinimum(1);
        spinBox_logExistDays->setMaximum(1000);
        spinBox_logExistDays->setValue(30);

        gridLayout->addWidget(spinBox_logExistDays, 1, 2, 1, 1);

        checkBox_debugMode = new QCheckBox(centralwidget);
        checkBox_debugMode->setObjectName(QStringLiteral("checkBox_debugMode"));
        checkBox_debugMode->setFont(font);

        gridLayout->addWidget(checkBox_debugMode, 2, 2, 1, 1);

        settingdialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(settingdialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 423, 26));
        settingdialog->setMenuBar(menubar);
        statusbar = new QStatusBar(settingdialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        settingdialog->setStatusBar(statusbar);

        retranslateUi(settingdialog);

        QMetaObject::connectSlotsByName(settingdialog);
    } // setupUi

    void retranslateUi(QMainWindow *settingdialog)
    {
        settingdialog->setWindowTitle(QApplication::translate("settingdialog", "MainWindow", nullptr));
        pushButton_modify->setText(QApplication::translate("settingdialog", "\344\277\256\346\224\271", nullptr));
        spinBox_imgExistDays->setSuffix(QApplication::translate("settingdialog", " \345\244\251", nullptr));
        label2->setText(QApplication::translate("settingdialog", "\346\223\215\344\275\234\346\227\245\345\277\227\344\277\235\345\255\230\346\227\266\351\227\264\357\274\232", nullptr));
        label1->setText(QApplication::translate("settingdialog", "\345\233\276\347\211\207\344\277\235\345\255\230\346\227\266\351\227\264\357\274\232", nullptr));
        spinBox_logExistDays->setSuffix(QApplication::translate("settingdialog", " \345\244\251", nullptr));
        checkBox_debugMode->setText(QApplication::translate("settingdialog", "\350\260\203\350\257\225\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingdialog: public Ui_settingdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
