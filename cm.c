#include <stdio.h>
#include <string.h>

int main ( int argc, char *argv[] )
{
	int load_contacts(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10]);
	void save_contacts(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10], int curLength);

	char name[10][20];
	char address[10][200];
	char phoneNumber[10][10];

	int curLength = load_contacts(name, address, phoneNumber);

    if (strcmp(argv[1], "create") == 0)
    {
    	strcpy(name[curLength], argv[2]);
    	strcpy(address[curLength], argv[3]);
    	strcpy(phoneNumber[curLength], argv[4]);

    	curLength++;

    	save_contacts(name, address, phoneNumber, curLength);
    }
    if (strcmp(argv[1], "retrieve") == 0)
    {
    	int item = atoi(argv[2]);
    	printf(name[item]);
    	printf(address[item]);
    	printf(phoneNumber[item]);
    }
    if (strcmp(argv[1], "update") == 0)
    {
    	int item = atoi(argv[2]) - 1;

    	strcpy(name[item], argv[3]);
    	strcpy(address[item], argv[4]);
    	strcpy(phoneNumber[item], argv[5]);

    	save_contacts(name, address, phoneNumber, curLength);

    }
    if (strcmp(argv[1], "delete") == 0)
    {
    	int item = atoi(argv[2]) - 1;
    	int i;
    	for (i = item - 1; i++; i < curLength) {
    		strcpy(name[i], name[i + 1]);
    		strcpy(address[i], address[i + 1]);
    		strcpy(phoneNumber[i], phoneNumber[i + 1]);
    	}
    	curLength --;
    	save_contacts(name, address, phoneNumber, curLength);
    } 
    if (strcmp(argv[1], "list") == 0) 
    {    	
    	int i;
    	for (i = 0; i < curLength; i++) 
    	{
    		printf("contact: ");
    		char curItem[10];
    		sprintf(curItem, "%d", i + 1);
    		printf(curItem);
    		printf("\n");
    		printf(name[i]);
    		printf("\n");
    		printf(address[i]);
    		printf("\n");
    		printf(phoneNumber[i]);
    		printf("\n");
    		printf("\n");
    	}
    }   
}

int load_contacts(char names[10][20], char addresses[10][200], char phoneNumbers[10][10]) {
	int numItems = 0;
	FILE *infile = fopen("contacts.dat", "r");
	if (infile == NULL) {
		return 0;
	}

	fscanf(infile, "%d", &numItems);

	if (numItems >= 10) {
		numItems = 10;
	}

	int i;
	for (i = 0; i < numItems; i++) {
		fscanf(infile, "%s", names[i]);	
	}
	for (i = 0; i < numItems; i++) {
		fscanf(infile, "%s", addresses[i]);
	}
	for (i = 0; i < numItems; i++) {
		fscanf(infile, "%s", phoneNumbers[i]);
	}

	fclose(infile);

	return numItems;

}

void save_contacts(char names[10][20], char addresses[10][200], char phoneNumbers[10][10], int numItems) {
	FILE *outfile = fopen("contacts.dat", "w");
	if (outfile == NULL) {
		return;
	}

	fprintf(outfile, "%d", numItems);

	int i;
	for (i = 0; i < numItems; i++) {
		fputs(names[i], outfile);
		fputs("\n", outfile);
	}
	for (i = 0; i < numItems; i++) {
		fputs(addresses[i], outfile);
		fputs("\n", outfile);
	}
	for (i = 0; i < numItems; i++) {
		fputs(phoneNumbers[i], outfile);
		fputs("\n", outfile);
	}

	fclose(outfile);

}
