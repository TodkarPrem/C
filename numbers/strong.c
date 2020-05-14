#include <stdio.h>

int fact(int);

int main()
{
	int num, sum = 0, tmp;

	printf("Enter any num: ");
	scanf("%d", &num);

	tmp = num;
	while (tmp) {
		sum = fact(tmp % 10) + sum;
		tmp = tmp / 10;
	}

	if (sum == num)
		printf("Given num is strong number.\n");
	else
		printf("Given num is not strong num.\n");

	return 0;
}

int fact(int num)
{
	int tmp = 1;

	while (num)
		tmp = num-- * tmp;
	return tmp;
}
