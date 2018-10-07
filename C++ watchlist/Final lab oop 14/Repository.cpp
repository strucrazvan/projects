#include "Repository.h"
#include <string>
#include <fstream>
#include "RepositoryExceptions.h"
using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addTutorial(const Tutorial& t)
{
	if (findPositionByTitle(t.getTitle()) != -1)
		throw DuplicateTutorialException();
	this->tutorials.push_back(t);
	this->writeToFile();
}
void Repository::removeTutorial(const Tutorial& t)
{
	if (findPositionByTitle(t.getTitle()) == -1)
		throw InexistentTutorialException();
	for (auto elem : this->tutorials)
		if (t.getTitle() == elem.getTitle())
		{
			this->tutorials.erase(this->tutorials.begin() + findPositionByTitle(t.getTitle()));
			this->writeToFile();
			break;
		}

}
void Repository::updateTutorial(Tutorial& t, const Tutorial& t1)
{

	if (findPositionByTitle(t.getTitle()) == -1)
		throw InexistentTutorialException();
	for (auto elem : this->tutorials)
		if (t.getTitle() == elem.getTitle())
		{
			this->tutorials[findPositionByTitle(t.getTitle())] = t1;
			this->writeToFile();
			break;
		}
}
Tutorial Repository::findTutorialByTitle(const std::string& title)
{

	for (auto t : this->tutorials)
		if (title == t.getTitle())
			return t;
	return Tutorial{};

}
void Repository::readFromFile()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Tutorial t;
	while (file >> t)
		this->tutorials.push_back(t);
	file.close();


}
void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");
	for (auto t : this->tutorials)
	{
		file << t;
	}
	file.close();
}
int Repository::findPositionByTitle(const std::string& title)
{

	for (int i = 0; i < this->tutorials.size(); i++)
		if (this->tutorials[i].getTitle() == title)
			return i;
	return -1;

}