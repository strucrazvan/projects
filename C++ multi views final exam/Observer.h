#pragma once
#include "Programmer.h"

class Observer
{
public:
	virtual void update() = 0;
	virtual Programmer getProgrammer() = 0;
	virtual ~Observer() {}
};

