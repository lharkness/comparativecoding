#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{

	printf("starting");
	printf("\n");

	int numItems;

	FILE *infile = fopen("test.dat", "r");

	if (infile != NULL) {
		printf("Reading File");
		printf("\n");
		fscanf(infile, "%d", &numItems);
		printf("data is read");
		char line[255];
		sprintf(line, "%d", numItems);
		puts(line);
	}
	fclose(infile);
	numItems = 42;
	FILE *outfile = fopen("test.dat", "w");
	printf("Writing file");
	fprintf(outfile, "%d", numItems);
	fclose(outfile);
	
	printf("Ending");
	printf("\n");
}