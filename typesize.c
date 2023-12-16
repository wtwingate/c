#include <stdio.h>

int main(void)
{
	printf("Size of int:\t%4li bytes\n", sizeof(int));
	printf("Size of short:\t%4li bytes\n", sizeof(short));
	printf("Size of long:\t%4li bytes\n", sizeof(long));
	printf("\n");
	printf("Size of char:\t%4li bytes\n", sizeof(char));
	printf("\n");
	printf("Size of float:\t%4li bytes\n", sizeof(float));
	printf("Size of double:\t%4li bytes\n", sizeof(double));
}
