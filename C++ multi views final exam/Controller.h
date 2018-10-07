#pragma once
#include "Repository.h"
#include "Observer.h"

class Controller
{
private:
	Repository & repo;
	std::vector<Observer*> obsv;
public:
	Controller(Repository & r) : repo{ r } {}

	void notify();
	Repository& getRepo() { return this->repo; }


	std::string getPrName(Task & t);
	int getPrId(Task & t);

	void addObs(Observer* o);
	void addTask(const std::string & descr);

	/*deletes a task from repository
	  Input: descr - the description of the task that will be deleted
	*/
	void deleteTask(const std::string & descr);
	/* Updates the task => the task will be in progress and the prommamer will sign for the task
	   Input: descr - the decription of the task that will be updated
		      p - the programmer whowill complete the task
	*/
	void startTask(const std::string & descr, const Programmer& p);

	/* Updates the task => the task will be finished
	Input: descr - the decription of the task that was completed
		   p - the programmer who completed the task
	*/
	void finishTask(const std::string & descr, const Programmer& p);
	
};

