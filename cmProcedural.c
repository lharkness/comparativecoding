#include <stdio.h>

void display_menu();

int main ( int argc, char *argv[] )
{
    char input[80];
    do 
    {
        display_menu();
        get_user_input("Enter Option:", input);
        handle_command(input[0]);
    }
    while (input[0] != 'Q');
}

void display_menu() 
{
    printf("%s", "[C]reate\n");
    printf("%s", "[R]etrieve\n");
    printf("%s", "[U]pdate\n");
    printf("%s", "[D]elete\n");
    printf("%s", "[L]ist\n");
    printf("\n");
    printf("%s", "[Q]uit\n");

    printf("\n");
}
