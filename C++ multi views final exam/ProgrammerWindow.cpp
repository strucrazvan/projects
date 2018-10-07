#include "ProgrammerWindow.h"
#include <sstream>
#include "qmessagebox.h"
#include "RepositoryException.h"

using namespace std;

ProgrammerWindow::ProgrammerWindow(Controller & ctrl, Programmer & p, QWidget *parent)
	: ctrl{ ctrl }, p{ p }, QWidget{ parent }
{
	ui.setupUi(this);
	this->ctrl.addObs(this);
	this->setWindowTitle(QString::fromStdString(p.getName()));
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &ProgrammerWindow::addTask);
	QObject::connect(this->ui.deleteButton, &QPushButton::clicked, this, &ProgrammerWindow::deleteTask);
	QObject::connect(this->ui.startButton, &QPushButton::clicked, this, &ProgrammerWindow::startTask);
	QObject::connect(this->ui.doneButton, &QPushButton::clicked, this, &ProgrammerWindow::finishTask);

	this->ctrl.notify();
}

void ProgrammerWindow::addTask() {
	std::string descr = this->ui.descriptionEdit->text().toStdString();
	this->ctrl.addTask(descr);
	this->ctrl.notify();
}

void ProgrammerWindow::deleteTask() {
	string line = this->ui.listWidget->currentItem()->text().toStdString();
	vector<string> members = ProgrammerWindow::tokenize(line, ',');
	this->ctrl.deleteTask(members[0]);
	this->ctrl.notify();
}

void ProgrammerWindow::startTask() {
	string line = this->ui.listWidget->currentItem()->text().toStdString();
	vector<string> members = ProgrammerWindow::tokenize(line, ',');
	try {
		this->ctrl.startTask(members[0], this->p);
		this->ctrl.notify();
	}
	catch (RepositoryException& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}
}

void ProgrammerWindow::finishTask() {
	string line = this->ui.listWidget->currentItem()->text().toStdString();
	vector<string> members = ProgrammerWindow::tokenize(line, ',');
	try {
		this->ctrl.finishTask(members[0], this->p);
		this->ctrl.notify();
	}
	catch (RepositoryException& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}
	
}

bool sortfunction(const Task & t1, const Task & t2) {
	if (t1.getDescr() == "open") return true;
	if (t1.getDescr() == "done") return false;
	if (t1.getDescr() == "in progress")
		if (t2.getDescr() == "open") return false;
	return true;
}

void ProgrammerWindow::update() {
	this->ui.listWidget->clear();
	vector<Task> tsk = this->ctrl.getRepo().getTasks();
	//sort(tsk.begin(), tsk.end(), sortfunction);
	for (auto & t : this->ctrl.getRepo().getTasks()) {
		string line = t.getDescr() + "," + t.getStatus();
		if (t.getStatus() != "open")
			line = line + "," + this->ctrl.getPrName(t);
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(line) };
		this->ui.listWidget->addItem(item);
	}
}



std::vector<std::string> ProgrammerWindow::tokenize(std::string line, char del) {
	std::string elem;
	std::stringstream ss(line);
	std::vector<std::string> tokens;
	while (std::getline(ss, elem, del))
		tokens.push_back(elem);
	return tokens;
}

ProgrammerWindow::~ProgrammerWindow()
{
}
