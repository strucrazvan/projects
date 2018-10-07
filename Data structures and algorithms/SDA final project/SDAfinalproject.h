#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SDAfinalproject.h"
#include "MultiMap.h"
#include <fstream>
#include <string>
using namespace std;

class SDAfinalproject : public QMainWindow
{
	Q_OBJECT

public:
	SDAfinalproject(QWidget *parent,string file);
private:
	MultiMap * multiMap;
	string fileName;
	void readFromFile();
	void populateList();
	void setNumberOfEmptyPositions();
	void addButtonEventHandler();
	void removeButtonEventHandler();
	void searchButtonEventHandler();
	int validInsert();

	Ui::SDAfinalprojectClass ui;
};
