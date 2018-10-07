#include "stdafx.h"
#include "TElem.h"



TElem::TElem() :key{ -1 }, value{ -1 }
{
}

TElem::TElem(const int & key, const int & value)
{
	this->key = key;
	this->value = value;
}

