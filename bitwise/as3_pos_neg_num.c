#include <stdio.h>

int main()
{
	int num;

	printf("Enter any number: ");
	scanf("%d", &num);

	num & 1 << 31 ? printf("Negative number.\n") : printf("Positive number.\n");

	return 0;
}
