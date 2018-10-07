#pragma once

#include "Tutorial.h"
#include <vector>
class Repository
{
private:
	std::vector<Tutorial> tutorials;
	std::string filename;
public:
	Repository(const std::string& filename);
	void addTutorial(const Tutorial& t);
	void removeTutorial(const Tutorial& t);
	void updateTutorial(Tutorial& t, const Tutorial& t1);
	Tutorial findTutorialByTitle(const std::string& title);
	std::vector<Tutorial> getTutorials() const { return tutorials; }
	int findPositionByTitle(const std::string& title);

private:
	void readFromFile();
	void writeToFile();
};

