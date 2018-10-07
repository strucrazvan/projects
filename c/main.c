#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "CountryRepo.h"

int main()
{
  /*  Country* c=createCountry("Analuta","Europe",123);
    char str[123];

    CountryRepo* repo=createRepo();
    Country* c2=createCountry("Analuta1","Europe",123);
    Country* c3=createCountry("Analuta2","Europe",123);
    add(repo,c);
    add(repo,c2);
    add(repo,c3);
    int i=0;
    for(i;i<repo->length;i++)
    {    toString(repo->countries[i],str);
        printf("%s\n",str);
    }
*/
    CountryRepo* repo=createRepo();
    Controller* ctrl=createController(repo);

    testsCountryRepo();
   char name[50]="Romania";
    char continent[50]="Europe";
    int population=120;
    int i=0;
   for(i;i<10;i++)
    {   addCountry(ctrl,name,continent,population);
        population++;
        strcat(name,"a");
    }

    UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

    return 0;
}
