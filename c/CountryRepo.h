#pragma once
#include "Country.h"
#include "DynamicArray.h"
typedef struct
{
                                                                                                                                                                                                                Country* countries[100];
    DynamicArray* arr;
                                                                                                                                                                                                            int length;

}CountryRepo;
CountryRepo* createRepo();
void destroyRepo(CountryRepo* r);
Country* find(CountryRepo* r,char name[]);
int add(CountryRepo* r, Country* c);
int removeCountry(CountryRepo* r, Country* c);
int getLength(CountryRepo* r);
int update(CountryRepo* r, Country* a,Country* b);
Country* getCountryOnPos(CountryRepo* r, int pos);
void testsCountryRepo();
