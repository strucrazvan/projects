#include "Repository.h"
#include "RepositoryException.h"
#include <fstream>

using namespace std;

Repository::Repository(const std::string & fn) {
	this->filename = fn;
	this->readFromFile();
}

void Repository::addTask(Task & t) {
	this->tasks.push_back(t);
	this->writeToFile();
}

void Repository::deleteTask(Task & t) {
	int idx = this->findIndex(t);
	this->tasks.erase(this->tasks.begin() + idx);
	this->writeToFile();
}

int Repository::findIndex(Task & t) {
	for (int i = 0; i < this->tasks.size(); i++)
		if (this->tasks[i].getDescr() == t.getDescr())
			return i;
}

void Repository::startTask(Task & t) {
	int idx = this->findIndex(t);
	if (this->tasks[idx].getStatus() != "open")
		throw RepositoryException{ "Task is not open!" };
	this->tasks[idx] = t;
	this->writeToFile();
}

void Repository::finishTask(Task & t) {
	int idx = this->findIndex(t);
	if (this->tasks[idx].getStatus() != "in progress")
		throw RepositoryException{ "Task is not in progress!" };
	if (this->tasks[idx].getIdp() != t.getIdp())
		throw RepositoryException{ "Task is not done by you! " };
	this->tasks[idx] = t;
	this->writeToFile();
}


void Repository::readFromFile() {
	ifstream f(this->filename);
	if (!f.is_open()) return;
	
	Task t;
	while (f >> t)
		this->tasks.push_back(t);
	f.close();
}


void Repository::writeToFile() {
	ofstream f(this->filename);
	if (!f.is_open()) return;

	for (auto & t : this->tasks)
		f << t << '\n';
	f.close();
}