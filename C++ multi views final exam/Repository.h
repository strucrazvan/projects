#pragma once
#include "Task.h"
#include <string>
#include <vector>

class Repository
{
private:
	std::vector<Task> tasks;
	std::string filename;
public:
	Repository(const std::string & fn);
	void addTask(Task & t);
	/*deletes a task from repository
	Input: t - the task that will be deleted
	*/
	void deleteTask(Task & t);

	/* Updates the task => the task will be in progress and the prommamer will sign for the task
	Input: t - the task that will be updated
	*/
	void startTask(Task & t);

	/* Updates the task => the task will be finished
	Input: t - the task that will be completed
	*/
	void finishTask(Task & t);

	std::vector<Task> getTasks() { return this->tasks; }
private:
	void readFromFile();
	void writeToFile();
	int findIndex(Task & t);
};

