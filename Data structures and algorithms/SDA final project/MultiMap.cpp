#include "stdafx.h"
#include "MultiMap.h"
#include <assert.h>
#include <iostream>
using namespace std;

MultiMap::Iterator::Iterator(MultiMap &m):multiMap(m)
{
	//init funcitojn for iterator
	this->currentPosition = -1;
	next();
}


bool MultiMap::Iterator::valid()
{ 
	//validate function for iterator, when currentPosition is in the capacity
	if (currentPosition < multiMap.getCapacity())
		return true;
	return false;
}

void MultiMap::Iterator::next()
{
	//going to the next element
	currentPosition++;
	while (valid())
	{
		if (getCurrent()->getKey() != -1)
			break;
		currentPosition++;
	}
}

TElem * MultiMap::Iterator::getCurrent()
{
	//returns the current element
	if (valid())
		return multiMap.element(currentPosition);
}


MultiMap::Iterator::~Iterator()
{
	//destructor
}



bool MultiMap::checkIfEqual(int i,int key,int value)
{
	if (elements[i]->getKey() == key && elements[i]->getValue() == value)
		return 1;
	return 0;
}

MultiMap::MultiMap(const int & capacity)
{
	//Init function for multimap
	this->capacity = capacity;
	this->elements = new TElem*[capacity];//creates the Elements[] which has the size capacity

	for (int i = 0; i < capacity; i++)
	{
		this->elements[i] = new TElem();//allocates memory for each memory in elements[]
		assert(elements[i]->getKey() == -1);
	}
}

int MultiMap::add(TElem *t)
{
//Description: add a new <key, value> pair to the multimap
//	Pre : mm ∈ MM, key ∈ TKey, value ϵ TValue
//	Post : mm’ ∈ MM, mm’ = mm ∪ <key, value>

	H.resetI();
	int pos = H.getPosition(t->getKey(), capacity);
	while (elements[pos + H.getI()]->getKey() != -1)
	{
		if (elements[pos + H.getI()]->getKey() == t->getKey() && elements[pos + H.getI()]->getValue() == t->getValue())
			return 0;
		H.incrementI();
		if (pos + H.getI() >= capacity)
		{
			H.resetI();
			pos=0;
		}
	}

	elements[pos+ H.getI()] = t;
	return 1;
	//cout << H.getPosition(key, capacity) + H.getI() << " ";
	//cout << elements[H.getPosition(key, capacity) + H.getI()]->getKey() << " ";
	//cout << elements[H.getPosition(key, capacity) + H.getI()]->getValue() << "\n";
}

bool MultiMap::remove(TElem * t)
{
	//removes an element t from the multimap
	H.resetI();
	while (elements[H.getI()]->getKey() != t->getKey() || elements[H.getI()]->getValue()!=t->getValue())
	{
		H.incrementI();
		if (H.getPosition(t->getKey(), capacity) + H.getI() >= capacity)
			return 0;

	}
	free(elements[H.getI()]);//free's the memory
	elements[H.getI()] = new TElem();
	return 1;
}

void MultiMap::iterator(MultiMap::Iterator it)
{
	//iterator over multimap
	while (it.valid())
	{
		if(it.getCurrent()->getKey()!=-1)
			cout << it.getCurrent()->getKey() << " " << it.getCurrent()->getValue() << "\n";
		it.next();
	}

}

int MultiMap::search(int key, int value)
{


	return 0;
}



MultiMap::~MultiMap()
{
	for (int i = 0; i < capacity; i++)
		free(elements[i]);
}

