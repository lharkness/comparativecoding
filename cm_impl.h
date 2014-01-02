#ifndef CMI_H_   /* Include guard */
#define CMI_H_

int load_contacts(char names[10][20], char addresses[10][200], 
		char phoneNumbers[10][10]);
void save_contacts(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], int curLength);

int handle_create(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], 
	char* newName, char* newAddress, char* newPhone, int curLength);
void handle_retrieve(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char* index);
void handle_update(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], 
	char* newName, char* newAddress, char* newPhone, char* index,
	int curLength);
int handle_delete(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], char* index, int curLength);
void handle_list(char names[10][20], char addresses[10][200], 
	char phoneNumbers[10][10], int curLength);

#endif