#include "cmd_processor.h"
#include "cm_impl.h"

int handle_command(char cmd) {
    
    char name[10][20];
    char address[10][200];
    char phoneNumber[10][10];

    int curLength = load_contacts(name, address, phoneNumber);

    if (cmd == 'C')
    {
        curLength = handle_create(name, address, phoneNumber, curLength);
    }
    else if (cmd == 'R')
    {
        handle_retrieve(name, address, phoneNumber);
    }
    else if (cmd == 'U')
    {
        handle_update(name, address, phoneNumber, curLength);
    }
    else if (cmd == 'D')
    {
        curLength = handle_delete(name, address, phoneNumber, curLength);
    }
    else if (cmd == 'L')
    { 
        handle_list(name, address, phoneNumber, curLength);
    }
}