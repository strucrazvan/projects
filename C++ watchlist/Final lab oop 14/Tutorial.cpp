#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>

using namespace std;
Tutorial::Tutorial() : title(""), presenter(""), duration(Duration()), likes(0), link("") {}
Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& likes, const std::string& link)
{
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->link = link;
}


bool Tutorial::accessLink()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
	return true;

}
bool Tutorial::operator==(const Tutorial& t)
{
	if (this->title == t.getTitle())
		return true;
	return false;
}
istream & operator>>(istream & is, Tutorial & t)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	t.title = tokens[0];
	t.presenter = tokens[1];

	vector<string> durationTokens = tokenize(tokens[2], ':');
	if (durationTokens.size() != 2)
		return is;
	t.duration = Duration{ stod(durationTokens[0]), stod(durationTokens[1]) };
	t.likes = stod(tokens[3]);
	t.link = tokens[4];
	return is;
}
ostream & operator<<(ostream & os, const Tutorial & t)
{
	os << t.title << "," << t.presenter << "," << t.duration.getMinutes() << ":" << t.duration.getSeconds() << "," << t.likes << "," << t.link << "\n";
	return os;
}
