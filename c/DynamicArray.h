
#pragma once
#include "Country.h"
#define CAPACITY 10

typedef Country* TElement;

typedef struct
{
	TElement* elems;
	int length;			// actual length of the array
	int capacity;		// maximum capacity of the array
} DynamicArray;


DynamicArray* createDynamicArray(int capacity);

void destroy(DynamicArray* arr);


void addArray(DynamicArray* arr, TElement t);


void deleteArray(DynamicArray* arr, int pos);


int getLengthArray(DynamicArray* arr);


TElement get(DynamicArray* arr, int pos);


