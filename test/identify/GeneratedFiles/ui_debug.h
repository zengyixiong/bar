/********************************************************************************
** Form generated from reading UI file 'debug.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_H
#define UI_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugdialog
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLineEdit *circularity_min;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLineEdit *circularity_max;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *Threshold1_max;
    QLineEdit *area2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *Threshold1_min;
    QLabel *label_3;
    QLineEdit *area1;
    QPushButton *pushButton;
    QLabel *label_5;
    QLineEdit *Threshold2_max;
    QLineEdit *Threshold2_min;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_10;
    QPushButton *pushButton_roi;
    QPushButton *pushButton_change;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *debugdialog)
    {
        if (debugdialog->objectName().isEmpty())
            debugdialog->setObjectName(QStringLiteral("debugdialog"));
        debugdialog->resize(801, 567);
        centralwidget = new QWidget(debugdialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(430, 40, 371, 331));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        circularity_min = new QLineEdit(groupBox_2);
        circularity_min->setObjectName(QStringLiteral("circularity_min"));
        circularity_min->setMinimumSize(QSize(54, 21));
        circularity_min->setMaximumSize(QSize(54, 21));
        circularity_min->setReadOnly(true);
        circularity_min->setClearButtonEnabled(false);

        gridLayout->addWidget(circularity_min, 0, 2, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        circularity_max = new QLineEdit(groupBox_2);
        circularity_max->setObjectName(QStringLiteral("circularity_max"));
        circularity_max->setMinimumSize(QSize(54, 21));
        circularity_max->setMaximumSize(QSize(54, 21));
        circularity_max->setReadOnly(true);

        gridLayout->addWidget(circularity_max, 0, 5, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 4);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 2, 6, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 7, 1, 1);

        Threshold1_max = new QLineEdit(groupBox_2);
        Threshold1_max->setObjectName(QStringLiteral("Threshold1_max"));
        Threshold1_max->setMinimumSize(QSize(54, 21));
        Threshold1_max->setMaximumSize(QSize(54, 21));
        Threshold1_max->setReadOnly(true);

        gridLayout->addWidget(Threshold1_max, 1, 8, 1, 1);

        area2 = new QLineEdit(groupBox_2);
        area2->setObjectName(QStringLiteral("area2"));
        area2->setMaximumSize(QSize(54, 21));
        area2->setReadOnly(true);

        gridLayout->addWidget(area2, 4, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 8, 1, 1);

        Threshold1_min = new QLineEdit(groupBox_2);
        Threshold1_min->setObjectName(QStringLiteral("Threshold1_min"));
        Threshold1_min->setEnabled(true);
        Threshold1_min->setMinimumSize(QSize(54, 21));
        Threshold1_min->setMaximumSize(QSize(54, 21));
        Threshold1_min->setReadOnly(true);

        gridLayout->addWidget(Threshold1_min, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 5);

        area1 = new QLineEdit(groupBox_2);
        area1->setObjectName(QStringLiteral("area1"));
        area1->setMaximumSize(QSize(54, 21));
        area1->setReadOnly(true);

        gridLayout->addWidget(area1, 3, 5, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 8, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 3);

        Threshold2_max = new QLineEdit(groupBox_2);
        Threshold2_max->setObjectName(QStringLiteral("Threshold2_max"));
        Threshold2_max->setMinimumSize(QSize(54, 21));
        Threshold2_max->setMaximumSize(QSize(54, 21));
        Threshold2_max->setReadOnly(true);

        gridLayout->addWidget(Threshold2_max, 2, 8, 1, 1);

        Threshold2_min = new QLineEdit(groupBox_2);
        Threshold2_min->setObjectName(QStringLiteral("Threshold2_min"));
        Threshold2_min->setMinimumSize(QSize(54, 21));
        Threshold2_min->setMaximumSize(QSize(54, 21));
        Threshold2_min->setReadOnly(true);

        gridLayout->addWidget(Threshold2_min, 2, 5, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 4);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 6, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 3);

        pushButton_roi = new QPushButton(groupBox_2);
        pushButton_roi->setObjectName(QStringLiteral("pushButton_roi"));
        pushButton_roi->setFocusPolicy(Qt::StrongFocus);
        pushButton_roi->setAcceptDrops(true);
        pushButton_roi->setCheckable(false);
        pushButton_roi->setChecked(false);

        gridLayout->addWidget(pushButton_roi, 5, 5, 1, 1);

        pushButton_change = new QPushButton(groupBox_2);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));
        pushButton_change->setAutoDefault(false);
        pushButton_change->setFlat(false);

        gridLayout->addWidget(pushButton_change, 5, 8, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 10, 421, 381));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        debugdialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(debugdialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 801, 26));
        debugdialog->setMenuBar(menubar);
        statusbar = new QStatusBar(debugdialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        debugdialog->setStatusBar(statusbar);

        retranslateUi(debugdialog);
        QObject::connect(pushButton, SIGNAL(clicked()), debugdialog, SLOT(debugparam()));
        QObject::connect(pushButton_roi, SIGNAL(clicked()), debugdialog, SLOT(getRoi()));
        QObject::connect(pushButton_change, SIGNAL(clicked()), debugdialog, SLOT(change()));

        pushButton_roi->setDefault(false);
        pushButton_change->setDefault(true);


        QMetaObject::connectSlotsByName(debugdialog);
    } // setupUi

    void retranslateUi(QMainWindow *debugdialog)
    {
        debugdialog->setWindowTitle(QApplication::translate("debugdialog", "MainWindow", nullptr));
        groupBox_2->setTitle(QApplication::translate("debugdialog", "\351\230\210\345\200\274\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("debugdialog", "\345\234\206\345\272\246\350\214\203\345\233\264", nullptr));
        label_6->setText(QApplication::translate("debugdialog", "\342\200\224\342\200\224", nullptr));
        label_2->setText(QApplication::translate("debugdialog", "\347\254\254\344\270\200\346\254\241\345\244\204\347\220\206", nullptr));
        label_9->setText(QApplication::translate("debugdialog", "\342\200\224\342\200\224", nullptr));
        label_7->setText(QString());
        label_3->setText(QApplication::translate("debugdialog", "\347\254\254\344\272\214\346\254\241\345\244\204\347\220\206", nullptr));
        pushButton->setText(QApplication::translate("debugdialog", "open", nullptr));
        label_5->setText(QApplication::translate("debugdialog", "\345\210\244\346\226\255\350\214\203\345\233\264\351\230\210\345\200\274", nullptr));
        label_4->setText(QApplication::translate("debugdialog", "\345\210\244\346\226\255\346\230\257\345\220\246\345\274\202\345\270\270\351\230\210\345\200\274", nullptr));
        label_8->setText(QApplication::translate("debugdialog", "\342\200\224\342\200\224", nullptr));
        label_10->setText(QApplication::translate("debugdialog", "roi\345\214\272\345\237\237", nullptr));
        pushButton_roi->setText(QApplication::translate("debugdialog", "\351\207\215\351\200\211", nullptr));
        pushButton_change->setText(QApplication::translate("debugdialog", "change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debugdialog: public Ui_debugdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_H
