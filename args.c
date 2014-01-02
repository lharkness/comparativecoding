#include<stdio.h>

int main ( int argc, char *argv[] )
{
	char argvLength[80];
	sprintf(argvLength, "%d", argc);

	printf(argvLength);
	printf(" ");
	printf(argv[0]);
	printf(" ");
	printf(argv[1]);
}