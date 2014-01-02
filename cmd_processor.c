#include<stdio.h>

#include "cmd_processor.h"
#include "cm_impl.h"

int handle_command(char cmd) {
    
    char name[10][20];
    char address[10][200];
    char phoneNumber[10][10];

    int curLength = load_contacts(name, address, phoneNumber);

    if (cmd == 'C')
    {
        char newName[80];
        char newAddress[80];
        char newPhone[80];

        get_user_input("Name: ", newName);
        get_user_input("Address: ", newAddress);
        get_user_input("Phone: ", newPhone);

        curLength = handle_create(name, address, phoneNumber, 
            newName, newAddress, newPhone, curLength);
    }
    else if (cmd == 'R')
    {
        char index[80];
        get_user_input("Index: ", index);

        handle_retrieve(name, address, phoneNumber, index);
    }
    else if (cmd == 'U')
    {
        char newName[80];
        char newAddress[80];
        char newPhone[80];
        char index[80];

        get_user_input("Index: ", index);
        get_user_input("Name: ", newName);
        get_user_input("Address: ", newAddress);
        get_user_input("Phone: ", newPhone);

        handle_update(name, address, phoneNumber,
            newName, newAddress, newPhone, index,
            curLength);
    }
    else if (cmd == 'D')
    {
        char index[80];        
        get_user_input("Index: ", index);
        curLength = handle_delete(name, address, phoneNumber, index, curLength);
    }
    else if (cmd == 'L')
    { 
        handle_list(name, address, phoneNumber, curLength);
    }
}

void get_user_input(char* prompt, char* input) 
{
    printf(prompt);
    fgets(input, 80, stdin);
}