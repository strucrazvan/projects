#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Finallaboop14.h"
#include "Controller.h"
class Finallaboop14 : public QMainWindow
{
	Q_OBJECT

public:
	Finallaboop14(QWidget *parent, Controller& ctrl);


	void initTutorialList();

	void initWatchList();
	void addButtonEventHandler();
	void removeButtonEventHandler();
	void updateButtonEventHandler();
	void filterButtonEventHandler();
	void addToWatchListButtonEventHandler();
	void playButtonEventHandler();
	void nextButtonEventHandler();
	void printFileButtonEventHandler();
	void list_short();
	void undoButtonEventHandler();
	void redoButtonEventHandler();
	void undoWatchListButtonEventHandler();
	void redoWatchListButtonEventHandler();
private:
	Controller ctrl;
	Ui::Finallaboop14Class ui;
};
