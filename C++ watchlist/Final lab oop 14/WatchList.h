#pragma once
#include "Tutorial.h"
#include <vector>
using namespace std;
class WatchList
{
protected:
	std::vector<Tutorial> tutorials;
	int current;
public:
	WatchList();
	void add(const Tutorial& tutorial);
	Tutorial getCurrentTutorial();
	void play();
	void next();
	std::vector<Tutorial> getTutorials() const { return tutorials; }
	void remove(const Tutorial& tutorial);
	bool isEmpty();
};

