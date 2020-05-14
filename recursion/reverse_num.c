#include <stdio.h>

int reverseDigits(int num)
{
	static int sum = 0;

	if (num)
	{
		sum = sum*10 + num % 10;
		sumOfDigits(num / 10);
	}
	else
		return 0;
	return sum;
}

int main()
{
	int num, retValue;
	printf("Enter any number: ");
	scanf("%d", &num);

	retValue = reverseDigits(num);
	printf("Reverse num is %d\n", retValue);

	return 0;
}
