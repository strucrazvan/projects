#include "Controller.h"
#include <stdlib.h>
#include <string.h>
Controller* createController(CountryRepo* r)
{
    Controller* c=(Controller*)malloc(sizeof(Controller));
    c->repo=r;
    return c;
}
void destroyController(Controller* c)
{
    destroyRepo(c->repo);
    free(c);
}
int addCountry(Controller* c, char* name,char* continent, int population)
{
    Country* p=createCountry(name,continent,population);
    int res= add(c->repo,p);
    if(res==0)
        destroyCountry(p);

    return res;
}
int deleteCountry(Controller* c, char* name)
{
    int i=0;
    for(i; i<c->repo->length;i++)
    {
        if(strcmp(c->repo->countries[i]->name,name)==0)
        {
            removeCountry(c->repo,c->repo->countries[i]);

            return 1;

        }
    }
    return 0;
}
int updateCountry(Controller* c, char* name, Country* x)
{
    int i=0;
    for(i; i<c->repo->length;i++)
    {
        if(strcmp(c->repo->countries[i]->name,name)==0)
        {
            update(c->repo,c->repo->countries[i],x);
            return 1;
        }
    }
    return 0;
}
int migration(Controller* c,char* name1, char* name2, int x)
{
    if(find(c->repo,name1)==NULL||find(c->repo,name2)==NULL)
        return 0;
    int i=0;
    int j=0;
    while(strcmp(c->repo->countries[i]->name,name1))
        i++;
     while(strcmp(c->repo->countries[j]->name,name2))
        j++;
    if(getPopulation(c->repo->countries[i])<x)
        return 0;
    setPopulation(c->repo->countries[i],c->repo->countries[i]->population-x);
    setPopulation(c->repo->countries[j],c->repo->countries[j]->population+x);
    return 1;
}

CountryRepo* getRepo(Controller* c)
{
    return c->repo;
}

CountryRepo* filterByName(Controller* c, char name[]);
