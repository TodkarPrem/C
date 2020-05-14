#include <stdio.h>

int main()
{
	int num;

	printf("Enter any num: ");
	scanf("%d", &num);

	num & num-1 ? printf("Not a power of 2.\n") : printf("Power of 2.\n");

	return 0;
}
