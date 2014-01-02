#include <stdio.h>
#include <string.h>

void test(int v);
void test2(int v);

int main ( int argc, char *argv[] )
{	
	printf("test-");
	test(42);
}

void test(int val) {
	printf("test called-");
	int val2 = val;
	char buf[100];
	sprintf(buf, "%d",val);
	printf(buf);
	printf("\n");
	test2(val2);
}

void test2(int val) {
	printf("test2 called-");
	char buf[100];
	sprintf(buf, "%d",val);
	printf(buf);
}