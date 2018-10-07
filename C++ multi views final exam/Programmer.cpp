#include "Programmer.h"
#include <vector>
#include <sstream>
using namespace std;

std::vector<std::string> Programmer::tokenize(std::string line, char del) {
	std::string elem;
	std::stringstream ss(line);
	std::vector<std::string> tokens;
	while (std::getline(ss, elem, del))
		tokens.push_back(elem);
	return tokens;
}

std::istream& operator>>(std::istream& is, Programmer & t) {
	std::string line;
	getline(is, line);
	vector<string> tokens = Programmer::tokenize(line, ',');
	if (tokens.size() != 2) return is;
	t.name = tokens[0];
	t.id = stoi(tokens[1]);
	return is;
}
