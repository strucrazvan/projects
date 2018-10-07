#pragma once

#include <QWidget>
#include "ui_WatchListWidget.h"

class WatchListWidget : public QWidget
{
	Q_OBJECT

public:
	WatchListWidget(QWidget *parent = Q_NULLPTR);
	~WatchListWidget();

private:
	Ui::WatchListWidget ui;
};
