#include <stdio.h>

int sumOfDigits(int num)
{
	static int sum = 0;

	if (num)
	{
		sum += num % 10;
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

	retValue = sumOfDigits(num);
	printf("Sum of digits in %d num is %d\n", num, retValue);

	return 0;
}
