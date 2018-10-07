#include "Country.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Country* createCountry(char* name, char* continent, int population)
{
    Country* c=(Country*)malloc(sizeof(Country));
    c->name=(char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(c->name,name);
    c->continent=(char*)malloc(sizeof(char)*(strlen(continent)+1));
    strcpy(c->continent,continent);
    c->population=population;
    return c;
}
void destroyCountry(Country* c)
{
    free(c->continent);
    free(c->name);
    free(c);
}
char* getName(Country* c)
{
return c->name;
}
char* getContinent(Country* c)
{
    return c->continent;
}
int getPopulation(Country* c)
{
    return c->population;
}
void setPopulation(Country* c,int population)
{
    c->population=population;
}
void toString(Country* c,char str[])
{
    	sprintf(str, "Country: %s ; Continent: %s ; Population:  %d ", c->name, c->continent, c->population);

}
