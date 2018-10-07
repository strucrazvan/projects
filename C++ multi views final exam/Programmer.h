#pragma once
#include <string>
#include <vector>

class Programmer
{
private:
	std::string name;
	int id;
public:
	Programmer() {}
	Programmer(const std::string & name, int id) : name{ name }, id{ id } {}

	std::string getName() const { return this->name; }
	int getId() const { return this->id; }

	friend std::istream& operator>>(std::istream& is, Programmer & t);
private:
	static std::vector<std::string> tokenize(std::string line, char del);
};

