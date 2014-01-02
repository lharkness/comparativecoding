#include <stdio.h>
#include <string.h>
#include "cm_impl.h"

int handle_create(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10], 
		char* newName, char* newAddress, char* newPhone,
		int curLength) 
{
	strcpy(names[curLength], newName);
	strcpy(addresses[curLength], newAddress);
	strcpy(phoneNumbers[curLength], newPhone);

	curLength++;

	save_contacts(names, addresses, phoneNumbers, curLength);

	return curLength;
}

void handle_update(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], 
	char* newName, char* newAddress, char* newPhone, char* index,
	int curLength) 
{
	int item = atoi(index) - 1;

	strcpy(names[item], newName);
	strcpy(addresses[item], newAddress);
	strcpy(phoneNumbers[item], newPhone);

	save_contacts(names, addresses, phoneNumbers, curLength);
}

int handle_delete(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char* index, int curLength) 
{
	int item = atoi(index) - 1;
	int i;
	for (i = item - 1; i++; i < curLength) {
		strcpy(names[i], names[i + 1]);
		strcpy(addresses[i], addresses[i + 1]);
		strcpy(phoneNumbers[i], phoneNumbers[i + 1]);
	}
	curLength --;
	save_contacts(names, addresses, phoneNumbers, curLength);

	return curLength;
}

void handle_retrieve(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char* index) 
{
	int item = atoi(index) - 1;
	printf(names[item]);
	printf(addresses[item]);
	printf(phoneNumbers[item]);
}

void handle_list(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10], int curLength) {
	int i;
	for (i = 0; i < curLength; i++) 
	{
		printf("contact: ");
		char curItem[10];
		sprintf(curItem, "%d", i + 1);
		printf(curItem);
		printf("\n");
		printf(names[i]);
		printf("\n");
		printf(addresses[i]);
		printf("\n");
		printf(phoneNumbers[i]);
		printf("\n");
		printf("\n");
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
		fgets(names[i], 20, infile);	
	}
	for (i = 0; i < numItems; i++) {
		fgets(addresses[i], 200, infile);	
	}
	for (i = 0; i < numItems; i++) {
		fgets(phoneNumbers[i], 10, infile);	
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
	}
	for (i = 0; i < numItems; i++) {
		fputs(addresses[i], outfile);
	}
	for (i = 0; i < numItems; i++) {
		fputs(phoneNumbers[i], outfile);
	}

	fclose(outfile);

}