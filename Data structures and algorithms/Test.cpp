#include "stdafx.h"
#include "Test.h"
#include <assert.h>
#include "MultiMap.h"
#include <iostream>
using namespace std;
Test::Test()
{
}

void Test::runTests()
{

	/*testTElem();
	testTFunction();
	testMultiMap();
	testIterator();*/
}


void Test::testTElem()
{
	//TESTS FORM TELEM
	TElem x{ 1,2 };
	assert(x.getKey() == 1);
	assert(x.getValue() == 2);
	TElem y;
	assert(y.getKey() == -1);
	assert(y.getValue() == -1);
}

void Test::testTFunction()
{
	//TESTS FOR TFUNCTON
	TFunction H;
	assert(H.getPosition(5, 10) == 5);
	assert(H.getPosition(6, 10) + H.getI() == 6);
	H.incrementI();
	assert(H.getPosition(6, 10) + H.getI() == 7);
	H.resetI();
	assert(H.getPosition(6, 10) + H.getI() == 6);

}

void Test::testMultiMap()
{
	//TESTS FOR MULTIMAP
	MultiMap m{ 5 };
	assert(m.add(new TElem{ 3, 3 }) == 1);
	assert(m.add(new TElem{ 2, 4 }) == 1);
	//assert(m.search(3, 3) == 1);
	//assert(m.search(3, 2) == 0);

	assert(m.add(new TElem{ 2, 5 }) == 1);
	assert(m.add(new TElem{ 5, 5 }) == 1);
	assert(m.add(new TElem{ 5, 5 }) == 0);
	assert(m.add(new TElem{ 1, 3 }) == 1);
	TElem x{ 2,4 };
	assert(m.element(2)->getKey() == x.getKey());
	assert(m.element(2)->getValue() == x.getValue());
	m.remove(new TElem{ 2, 4 });
	assert(m.element(2)->getKey() == -1);
	m.add(new TElem{ 1, 4 });
	assert(m.getCapacity() == 5);
	TElem x2{ 1,4 };

	assert(m.element(2)->getKey() == x2.getKey());
	assert(m.element(2)->getValue() == x2.getValue());


	MultiMap m1{ 4 };
	assert(m1.add(new TElem{ 3, 3 }) == 1);
	assert(m1.add(new TElem{ 3, 4 }) == 1);
	assert(m1.add(new TElem{ 3, 5 }) == 1);
	assert(m1.add(new TElem{ 3, 6 }) == 1);
	assert(m1.remove(new TElem{ 3,12 }) == 0);
}

void Test::testIterator()
{
	//TESTS FOR ITERATOR
	MultiMap *m=new MultiMap(5);
	m->add(new TElem{ 3, 3 });
	m->add(new TElem{ 2, 4 });
	m->add(new TElem{ 3, 4 });
	m->add(new TElem{ 5, 5 });
	//m.add(1, 3);

	MultiMap::Iterator iter(*m);
	m->iterator(iter);
	assert(iter.valid() == true);
	assert(iter.getCurrent()->getKey() == 5);
	iter.next();
	assert(iter.getCurrent()->getKey() == -1);
	iter.next();
	assert(iter.getCurrent()->getKey() == 2);
	iter.next();
	assert(iter.getCurrent()->getKey() == 3);
}


