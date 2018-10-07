#pragma once

#include <QWidget>
#include "ui_FilePickClass.h"

class FilePickClass : public QWidget
{
	Q_OBJECT

public:
	FilePickClass(QWidget *parent = Q_NULLPTR);
	void CSV();
	void HTML();
	~FilePickClass();

private:
	Ui::FilePickClass ui;
};
