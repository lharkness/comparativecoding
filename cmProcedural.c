#include <stdio.h>

char get_user_input();

int main ( int argc, char *argv[] )
{
    char input;
    do 
    {
        input = get_user_input();
        printf("%c", input);
        handle_command(input);
    }
    while (input != 'Q');
}

char get_user_input() 
{
    printf("%s", "[C]reate\n");
    printf("%s", "[R]etrieve\n");
    printf("%s", "[U]pdate\n");
    printf("%s", "[D]elete\n");
    printf("%s", "[L]ist\n");
    printf("\n");
    printf("%s", "[Q]uit\n");

    printf("\n");
    printf("Enter Option: ");
    char input;
    scanf("%c", &input);

    return input;
}
