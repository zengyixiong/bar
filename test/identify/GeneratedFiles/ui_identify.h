/********************************************************************************
** Form generated from reading UI file 'identify.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDENTIFY_H
#define UI_IDENTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_identifyClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_camStatus;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_clientStatus;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *clean;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *identifyClass)
    {
        if (identifyClass->objectName().isEmpty())
            identifyClass->setObjectName(QStringLiteral("identifyClass"));
        identifyClass->resize(791, 647);
        centralWidget = new QWidget(identifyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_camStatus = new QLabel(groupBox);
        label_camStatus->setObjectName(QStringLiteral("label_camStatus"));
        label_camStatus->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_camStatus->sizePolicy().hasHeightForWidth());
        label_camStatus->setSizePolicy(sizePolicy);
        label_camStatus->setMaximumSize(QSize(27, 27));
        label_camStatus->setScaledContents(true);

        horizontalLayout->addWidget(label_camStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_clientStatus = new QLabel(groupBox);
        label_clientStatus->setObjectName(QStringLiteral("label_clientStatus"));
        label_clientStatus->setMaximumSize(QSize(27, 27));
        label_clientStatus->setScaledContents(true);

        horizontalLayout->addWidget(label_clientStatus);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_2->addWidget(groupBox, 0, 1, 2, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(204, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        clean = new QPushButton(groupBox_2);
        clean->setObjectName(QStringLiteral("clean"));

        gridLayout->addWidget(clean, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 5, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 6, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 3, 2, 1, 1);

        identifyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(identifyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 26));
        identifyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(identifyClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        identifyClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(identifyClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        identifyClass->setStatusBar(statusBar);

        retranslateUi(identifyClass);
        QObject::connect(pushButton, SIGNAL(clicked()), identifyClass, SLOT(image()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), identifyClass, SLOT(debug()));

        QMetaObject::connectSlotsByName(identifyClass);
    } // setupUi

    void retranslateUi(QMainWindow *identifyClass)
    {
        identifyClass->setWindowTitle(QApplication::translate("identifyClass", "identify", nullptr));
        groupBox->setTitle(QApplication::translate("identifyClass", "\347\212\266\346\200\201", nullptr));
        label_2->setText(QApplication::translate("identifyClass", "\347\233\270\346\234\272\347\212\266\346\200\201", nullptr));
        label_camStatus->setText(QString());
        label_3->setText(QApplication::translate("identifyClass", "\351\200\232\350\256\257\347\212\266\346\200\201", nullptr));
        label_clientStatus->setText(QString());
        groupBox_2->setTitle(QApplication::translate("identifyClass", "\350\277\220\350\241\214\344\277\241\346\201\257", nullptr));
        clean->setText(QApplication::translate("identifyClass", "\346\270\205\347\251\272", nullptr));
        pushButton->setText(QApplication::translate("identifyClass", "open", nullptr));
        pushButton_2->setText(QApplication::translate("identifyClass", "debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class identifyClass: public Ui_identifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDENTIFY_H
