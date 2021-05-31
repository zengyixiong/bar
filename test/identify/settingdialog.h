#pragma once
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_settingdialog.h"
class settingdialog : public QMainWindow
{
	Q_OBJECT

public:
	settingdialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::settingdialog ui;
};
