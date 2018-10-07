#include "Task.h"
#include <sstream>
using namespace std;

std::vector<std::string> Task::tokenize(std::string line, char del) {
	std::string elem;
	std::stringstream ss(line);
	std::vector<std::string> tokens;
	while (std::getline(ss, elem, del))
		tokens.push_back(elem);
	return tokens;
}

std::istream& operator>>(std::istream& is, Task & t) {
	std::string line;
	getline(is, line);
	vector<string> tokens = Task::tokenize(line, ',');
	t.idP = -1;
	if (tokens.size() < 2) return is;
	t.description = tokens[0];
	t.status = tokens[1];
	if (tokens.size() == 3)
		t.idP = stoi(tokens[2]);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Task & t) {
	os << t.description << "," << t.status << "," << t.idP;
	return os;
}