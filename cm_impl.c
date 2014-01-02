#include <stdio.h>
#include <string.h>
#include "cm_impl.h"

int handle_create(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10], char *argv[], int curLength) {
	strcpy(names[curLength], argv[2]);
	strcpy(addresses[curLength], argv[3]);
	strcpy(phoneNumbers[curLength], argv[4]);

	curLength++;

	save_contacts(names, addresses, phoneNumbers, curLength);

	return curLength;
}

void handle_update(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char *argv[], int curLength) {
	int item = atoi(argv[2]) - 1;

	strcpy(names[item], argv[3]);
	strcpy(addresses[item], argv[4]);
	strcpy(phoneNumbers[item], argv[5]);

	save_contacts(names, addresses, phoneNumbers, curLength);
}

int handle_delete(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char *argv[], int curLength) {
	int item = atoi(argv[2]) - 1;
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
	char phoneNumbers[10][10], char *argv[]) {
	int item = atoi(argv[2]);
	printf(names[item]);
	printf(addresses[item]);
	printf(phoneNumbers[item]);
}

void handle_list(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10], char *argv[], int curLength) {
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