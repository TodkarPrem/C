#include <stdio.h>

unsigned long int factorial(int num)
{
	if (num > 1)
		num *= factorial(num-1);
	else
		return 1;
}

int main()
{
	int num = 0;
       	unsigned long int retValue;

	do {
	printf("Enter any number(1 to 12):");
	scanf("%d", &num);
	} while (num > 12);

	retValue = factorial(num);
	printf("Factorial of given number is: %ld\n", retValue);

	return 0;
}
