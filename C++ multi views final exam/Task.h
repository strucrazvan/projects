#pragma once
#include <string>
#include <istream>
#include <ostream>
#include <vector>

class Task
{
private:
	std::string description;
	std::string status;
	int idP;
public:
	Task() {}
	Task(const std::string & descr, const std::string & status, int idP) : description{ descr }, status{ status }, idP{ idP } {}
	
	std::string getDescr() const { return this->description; }
	std::string getStatus() const { return this->status; }
	int getIdp() const { return this->idP; }

	friend std::istream& operator>>(std::istream& is, Task & t);
	friend std::ostream& operator<<(std::ostream& os, const Task & t);
private:
	static std::vector<std::string> tokenize(std::string line, char del);
};

