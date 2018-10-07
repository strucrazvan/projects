#include "CountryRepo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

CountryRepo* createRepo()
{
    CountryRepo* r=(CountryRepo*)malloc(sizeof(CountryRepo));
                                                                                                                                                                                                                r->length=0;
    r->arr=createDynamicArray(CAPACITY);
    return r;
}
void destroyRepo(CountryRepo* r)
{   int i;
    for(i=0;i<r->length;i++)
        destroyCountry(r->countries[i]);
    free(r);
}
Country* find(CountryRepo* r,char name[])
{   int i;
    for (i= 0; i < r->length; i++)
	{
		if (strcmp(r->countries[i]->name, name) == 0)
			return r->countries[i];
	}
	return NULL;
}
int add(CountryRepo* r, Country* c)
{
    if (find(r, c->name) != NULL)
		return 0;

	r->countries[r->length] = c;
	r->length++;

	return 1;
}
int update(CountryRepo* r, Country* a,Country* b)
{
     if (find(r, a->name) == NULL)
		return 0;
    int i=0;
    while(r->countries[i]->name!=a->name)
        i++;
    r->countries[i]=b;
    return 1;
}
int removeCountry(CountryRepo* r, Country* c)
{
    if (find(r, c->name) == NULL)
		return 0;

    int i=0;
    while(r->countries[i]->name!=c->name)
        i++;
    for(i;i<r->length-1;i++)
        r->countries[i]=r->countries[i+1];
    r->length--;
    return 1;
}
int getLength(CountryRepo* r)
{
    	return r->length;

}
Country* getCountryOnPos(CountryRepo* r, int pos)
{
    if (pos < 0 || pos >= r->length)
		return NULL;
	return r->countries[pos];
}




void testAdd()
{
    CountryRepo* repo=createRepo();
    Country* c=createCountry("asd","Europe",10);
    add(repo,c);
    assert(getLength(repo)==1);
    assert(repo->countries[0]->population==10);

}

void testsCountryRepo()
{
	testAdd();
}
