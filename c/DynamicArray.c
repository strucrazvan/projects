
#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	// allocate space for the elements
	da->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
		return NULL;

	return da;
}

void destroy(DynamicArray* arr)
{
	if (arr == NULL)
		return;
int i ;
	// considering that the dynamic array takes responsibility of all the elements, it will have to deallocate the memory for these
	for (i= 0; i < arr->length; i++)
		destroyCountry(arr->elems[i]);
	// !!! The function destroyPlanet is called here, so it is assumed that we know that the array contains pointers: Planet*
	// For a more generic implementation, please see the project Seminar1_Version4

	// free the space allocated for the elements
	free(arr->elems);
	arr->elems = NULL;

	// free the space allocated for the dynamic array
	free(arr);
	arr = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;

	// version 1 - using realloc
	//TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
	//if (aux == NULL)
	//	return - 1;
	//arr->elems = aux;

	// version 2 - allocate new memory, copy everything and deallocate the old memory
	TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
		int i ;
	for (i= 0; i < arr->length; i++)
		aux[i] = arr->elems[i];
	free(arr->elems);
	arr->elems = aux;

	return 0;
}

void addArray(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void deleteArray(DynamicArray* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	// !!! Considering the code below, we will no longer have access to the allocated memory.
	// How can we avoid a memory leak?
int i ;
	for (i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}

int getLengthArray(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

TElement get(DynamicArray* arr, int pos)
{
	return arr->elems[pos];
}

// ------------------------------------------------------------------------------------------------------------
