#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}
void listAll(UI* ui)
{
    CountryRepo* repo=getRepo(ui->ctrl);
    int length=getLength(repo);
	if (length == 0)
	{
		char* str = "There are no countries.";
		printf("%s \n", str);
	}
int i = 0;
	for (i; i < getLength(repo); i++)
	{
		char str[200];
		toString(getCountryOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void printMenu()
{
	printf("\n\n1. add a country.\n");
	printf("2. list all.\n");
	printf("3. delete a country.\n");
	printf("4. update a country.\n");
	printf("5. migration.\n");
	printf("6. Search for countries with name.\n");
	printf("7. Print sorted by continent and population.\n");
	printf("8. Sort descending by given partial name or name and population.\n");
	printf("0 - to exit.\n");
}
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
void ui_add(UI* ui)
{
    char name[50],continent[10];
    int population=0;
    printf("Please insert the name: ");
    scanf("%s",name);
    printf("Please insert the continent: ");
    scanf("%s",continent);
     if(strcmp("Europe",continent) && strcmp(continent,"America") && strcmp(continent,"Africa") && strcmp(continent,"Australia") && strcmp(continent,"Asia"))
        {
            printf("Invalid continent");
        }
    else
        {
            printf("Please insert the country's population: ");
            scanf("%d",&population);
            if(addCountry(ui->ctrl,name,continent,population)==0)
                printf("Country not added!");
            else
                printf("Country Added!");

        }
}
void ui_delete(UI* ui)
{
    char name[50];
    printf("Please insert a name to be deleted: ");
    scanf("%s",name);
    if(deleteCountry(ui->ctrl,name))
        printf("Item deleted");
    else
        printf("Item not found!");
}
void ui_update(UI* ui)
{
      char name1[50];
    printf("Please insert a name to be updated: ");
    scanf("%s",name1);
    if(find(ui->ctrl->repo,name1)!=NULL)
       {
           char name[50],continent[10];
    int population=0;
    printf("Please insert the name: ");
    scanf("%s",name);
    printf("Please insert the continent: ");
    scanf("%s",continent);
     if(strcmp("Europe",continent) && strcmp(continent,"America") && strcmp(continent,"Africa") && strcmp(continent,"Australia") && strcmp(continent,"Asia"))
        {
            printf("Invalid continent");
        }
    else
        {
            printf("Please insert the country's population: ");
            scanf("%d",&population);
            Country* x= createCountry(name,continent,population);
            if(updateCountry(ui->ctrl,name1,x)==0)
                printf("Country not updated!");
            else
                printf("Country updated!");

        }
       }
    else
        printf("Item not found!");
}
void ui_migration(UI* ui)
{
     char name1[50],name2[50];
     int x;
    printf("Please insert a name to migrate from: ");
    scanf("%s",name1);
      printf("Please insert a name to migrate to: ");
    scanf("%s",name2);
    printf("Please insert the population to migrate: ");
    scanf("%d",&x);
    if(migration(ui->ctrl,name1,name2,x)==1)
        printf("Migration was done!");
    else
        printf("Invalid names or population too big!");
}
void ui_given_string(UI* ui)
{
    char name[50];
    int da=0;
    printf("Please insert the name or 0 to display all: ");
    scanf("%s",name);
    if(strlen(name)==1 && name[0]=='0')
    {
        int i=0;
    for(i;i<ui->ctrl->repo->length;i++)
        {
            char str[100];
            toString(ui->ctrl->repo->countries[i],str);
            printf("%s\n",str);
            da=1;
        }
    }
    else
    {
        int i=0;
    for(i;i<ui->ctrl->repo->length;i++)
        if(strstr(ui->ctrl->repo->countries[i]->name,name))
        {
            char str[100];
            toString(ui->ctrl->repo->countries[i],str);
            printf("%s\n",str);
            da=1;
        }
    }

    if(da==0)
        printf("No items containing %s",name);
}
void ui_given_continent(UI* ui)
{   char continent[50];
int population=0;
    printf("Please insert the continent: ");
    scanf("%s",continent);
    printf("Please insert the population: ");
    scanf("%d",&population);
    if(strlen(continent)==1 && continent[0]=='0')
    {
        CountryRepo* repo=ui->ctrl->repo;
        int i;
        int j;
        int da=0;
        for(i=0;i<repo->length-1;i++)
            for(j=i+1;j<repo->length;j++)
              if(repo->countries[i]->population>repo->countries[j]->population)
                {
                    Country* x=repo->countries[i]->population;
                    repo->countries[i]->population=repo->countries[j]->population;
                    repo->countries[j]->population=x;
                }
        for(i=0;i<repo->length;i++)
        if(ui->ctrl->repo->countries[i]->population>population)
        {
            char str[100];
            toString(ui->ctrl->repo->countries[i],str);
            printf("%s\n",str);
            da=1;
        }
        if(da==0)
            printf("No data to display!");

    }
    else if(strcmp("Europe",continent) && strcmp(continent,"America") && strcmp(continent,"Africa") && strcmp(continent,"Australia") && strcmp(continent,"Asia"))
        {
            printf("Invalid continent");
        }
    else
    {
           CountryRepo* repo=createRepo();
        int i;
        int da=0;
        for(i=0;i<ui->ctrl->repo->length;i++)
            if(strcmp(ui->ctrl->repo->countries[i]->continent,continent)==0)
                 add(repo,ui->ctrl->repo->countries[i]);
        int j;
        for(i=0;i<repo->length-1;i++)
            for(j=i+1;j<repo->length;j++)
              if(repo->countries[i]->population>repo->countries[j]->population)
                {
                    Country* x=repo->countries[i]->population;
                    repo->countries[i]->population=repo->countries[j]->population;
                    repo->countries[j]->population=x;
                }
        for(i=0;i<repo->length;i++)
        if(repo->countries[i]->population>population)
        {
            char str[100];
            toString(repo->countries[i],str);
            printf("%s\n",str);
            da=1;
        }
        if(da==0)
            printf("No data to display!");

    }


}
int printRepo(CountryRepo* repo)
{int i;
    for(i=0;i<repo->length;i++)
        {
            char str[100];
            toString(repo->countries[i],str);
            printf("%s\n",str);
        }
    if(repo->length==0)
        return 0;
    return 1;
}
void ui_name_given_string_sorted(UI* ui)
{   char name[50];
    printf("Please insert the string: ");
    scanf("%s",name);


     if(strlen(name)==1 && name[0]=='0')
    {    int i;
        CountryRepo* repo=createRepo();
        for(i=0;i<ui->ctrl->repo->length;i++)
            add(repo,ui->ctrl->repo->countries[i]);

        int j;
                                                                                                                                                                                                                        CountryRepo* Repo=createRepo();

        int da=0;
        for(i=0;i<repo->length-1;i++)
            for(j=i+1;j<repo->length;j++)
              if(repo->countries[i]->population < repo->countries[j]->population)
                {
                    Country* x=repo->countries[i]->population;
                    repo->countries[i]->population=repo->countries[j]->population;
                    repo->countries[j]->population=x;
                }
        for(i=0;i<repo->length;i++)
        {
            char str[100];
            toString(ui->ctrl->repo->countries[i],str);
            printf("%s\n",str);
            da=1;
        }
        if(da==0)
            printf("No data to display!");
        destroyRepo(Repo);

    }
    else
    {
           CountryRepo* repo=createRepo();
        int i;
        int da=0;
        for(i=0;i<ui->ctrl->repo->length;i++)
            if(strstr(ui->ctrl->repo->countries[i]->name,name)!=NULL)
                add(repo,ui->ctrl->repo->countries[i]);
        int j;
        for(i=0;i<repo->length-1;i++)
            for(j=i+1;j<repo->length;j++)
              if(repo->countries[i]->population<repo->countries[j]->population)
                {
                    Country* x=repo->countries[i]->population;
                    repo->countries[i]->population=repo->countries[j]->population;
                    repo->countries[j]->population=x;
                }

        if(printRepo(repo)==0)
            printf("No data to display!");

    }

}
void startUI(UI* ui)
{
    printf("5 HOURS OF WORK FOR THIS AMAZING PROGRAM!\n");
    while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
    switch(command)
    {
        case 1:
        {ui_add(ui);
            break;
        }
        case 2:
            {
                listAll(ui);
                break;
            }
        case 0:
                exit(1);
        case 3:
            {
                ui_delete(ui);
                break;
            }
        case 4:
            {
                ui_update(ui);
                break;
            }
        case 5:
            {
                ui_migration(ui);
                break;
            }
        case 6:
            {
                ui_given_string(ui);
                break;
            }
        case 7:
            {
                ui_given_continent(ui);
                break;
            }
        case 8:
            {
                ui_name_given_string_sorted(ui);
                break;
            }

        default:
            {
                printf("/nInvalid command!/n");
                break;
            }

    }


	}
}
