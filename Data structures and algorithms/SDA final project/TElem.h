#pragma once
class TElem
{
	//TElem :
	//key : Integer
	//value : Integer

private:
	int key;
	int value;
public:
	TElem();
	TElem(const int& key, const int& value);
	int getKey() const { return key; }
	int getValue() const { return value; }
};


