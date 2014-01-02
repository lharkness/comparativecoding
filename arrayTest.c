#include<stdio.h>
#include<string.h>

int main ( int argc, char *argv[] )
{
	char name[10][20];
	char address[10][200];
	char phoneNumber[10][10];

	int curLength = 1;

	printf("here");

	strcpy(name[0], "Test");
	strcpy(address[0], "address");
	strcpy(phoneNumber[0], "phoneNumber");

    if (strcmp(argv[1], "create") == 0)
    {
    	strcpy(name[curLength], argv[2]);
    	strcpy(address[curLength], argv[3]);
    	strcpy(phoneNumber[curLength], argv[4]);

    	curLength++;

    	printf("Added Record");
    }
    if (strcmp(argv[1], "retrieve") == 0)
    {
    	printf ("user wants to retrieve");
    }
    if (strcmp(argv[1], "update") == 0)
    {
    	printf ("user wants to update");
    }
    if (strcmp(argv[1], "delete") == 0)
    {
    	printf ("user wants to delete");
    } 
    if (strcmp(argv[1], "list") == 0) 
    {
    	printf("here");
    	int i;
    	for (i = 0; i < curLength; i++) 
    	{
    		printf(name[i]);
    		printf(address[i]);
    		printf(phoneNumber[i]);
    	}
    }   
}