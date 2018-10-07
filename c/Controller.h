#pragma once
#include "CountryRepo.h"
#include "OperationStack.h"
typedef struct
{
    CountryRepo* repo;
}Controller;
Controller* createController(CountryRepo* r);
void destroyController(Controller* c);
int addCountry(Controller* c, char* name,char* continent, int population);
CountryRepo* getRepo(Controller* c);
int deleteCountry(Controller* c, char* name);
int updateCountry(Controller* c, char* name, Country* x);
int migration(Controller* c,char* name1, char* name2, int x);
CountryRepo* filterByName(Controller* c, char name[]);
