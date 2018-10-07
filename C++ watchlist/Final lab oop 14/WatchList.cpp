#include "WatchList.h"
#include <iostream>

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Tutorial& tutorial)
{
	this->tutorials.push_back(tutorial);
}
Tutorial WatchList::getCurrentTutorial()
{
	if (this->current == this->tutorials.size())
		this->current = 0;
	return this->tutorials[this->current];
	return Tutorial{};
}
void WatchList::play()
{
	if (this->tutorials.size() >= 0)
	{
		this->current = 0;
		Tutorial currentTutorial = this->getCurrentTutorial();
		currentTutorial.accessLink();
	}
}
void WatchList::next()
{
	if (this->tutorials.size() >= 0)
	{
		this->current++;
		Tutorial currentTutorial = this->getCurrentTutorial();
		currentTutorial.accessLink();
	}
}
void WatchList::remove(const Tutorial& tutorial)
{

	this->tutorials.erase(this->tutorials.begin() + this->current);
	if (isEmpty())
		this->current = 0;
}
bool WatchList::isEmpty()
{
	return this->tutorials.size() == 0;
}
