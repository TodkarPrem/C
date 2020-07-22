#include <stdio.h>

void main()
{
	int i=2;
	int j=3;

	printf("%u %u %u\n", &i, &j, &j - &i);
	if (&i > &j)
		printf("stack grown downwards.\n");
	else 
		printf("stack grows upwards.\n");
}
