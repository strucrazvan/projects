#include "Controller.h"

void Controller::addObs(Observer* o) {
	this->obsv.push_back(o);
}

void Controller::addTask(const std::string & descr) {
	Task t{ descr, "open", -1 };
	this->repo.addTask(t);
}

void Controller::deleteTask(const std::string & descr) {
	Task t{ descr, "open", -1 };
	this->repo.deleteTask(t);
}

void Controller::startTask(const std::string & descr, const Programmer& p) {
	Task t{ descr, "in progress", p.getId()};
	this->repo.startTask(t);
}

void Controller::finishTask(const std::string & descr, const Programmer& p) {
	Task t{ descr, "done", p.getId() };
	this->repo.finishTask(t);
}

std::string Controller::getPrName(Task & t) {
	for (auto o : this->obsv)
		if (t.getIdp() == o->getProgrammer().getId())
			return o->getProgrammer().getName();
	return std::string{};
}

int Controller::getPrId(Task & t) {
	return 0;
}

void Controller::notify() {
	for (auto o : this->obsv)
		o->update();
}