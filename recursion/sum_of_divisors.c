#include <stdio.h>

int sumOfDivisors(int num)
{
	static int sum, i = 1;

	if (i != num)
	{
		if (num % i == 0)
			sum += i;
		i++;
		sumOfDivisors(num);
	}
	return sum;
}

int main()
{
	int num, retValue;

	printf("Enter any num: ");
	scanf("%d", &num);

	retValue = sumOfDivisors(num);
	printf("Sum of all divisors of given num is: %d\n", retValue);

	return 0;
}
