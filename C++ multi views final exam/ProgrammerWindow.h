#pragma once
#include "Controller.h"
#include "Observer.h"
#include <QWidget>
#include "Programmer.h"
#include "ui_ProgrammerWindow.h"

class ProgrammerWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ProgrammerWindow(Controller & ctrl, Programmer & p, QWidget *parent = Q_NULLPTR);
	~ProgrammerWindow();

	void update() override;
	void addTask();
	void deleteTask();
	void startTask();
	void finishTask();

	Programmer getProgrammer() override { return this->p; }

private:
	Ui::ProgrammerWindow ui;
	Controller & ctrl;
	Programmer p;


	static std::vector<std::string> tokenize(std::string line, char del);
};


