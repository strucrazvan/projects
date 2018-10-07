#pragma once
#include "TElem.h"
#include <stdlib.h>
#include "TFunction.h"
using namespace std;
class MultiMap
{


public :class Iterator
	{
		MultiMap &multiMap;
		int currentPosition;
	public:
			Iterator(MultiMap &m);
			
			bool valid();
			void next();
			int getCurrentPosition() { return currentPosition; }
			TElem * getCurrent();
			~Iterator();
	};
	/*MultiMap :
	elements : TElem[]
	capacity : Integer(capacity)
	function : TFunction*/
private:
	//vector<TElem> elements;
	TElem ** elements;
	int capacity;
	TFunction H;
	bool checkIfEqual(int i,int key,int value);

public:
	MultiMap(const int& capacity);
	int add(TElem *t);
	bool remove(TElem *t);
	TElem *element(int i) { return elements[i]; }
	void iterator(MultiMap::Iterator it);
	int search(int key, int value);

	int getCapacity() const { return capacity; }

	~MultiMap();
	

};


