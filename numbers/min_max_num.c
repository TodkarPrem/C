#include <stdio.h>

int tmpArr[2];

int * complex_code(int num, int dig)
{
	int temp, div = 10;
	tmpArr[0] = num;
	tmpArr[1] = 0;

	while (--dig)
		div *= div;

	for (num; num > 0; num /= 10) {
		if (num < div / 10)
			break;

		temp = num % div;

		if (temp < tmpArr[0])
			tmpArr[0] = temp;
		if (temp > tmpArr[1])
			tmpArr[1] = temp;
	}

	return tmpArr;
}

int main()
{
	int num, digits, *retArr;

	printf("Enter any num: ");
	scanf("%d", &num);

	printf("Enter how much digits u want in o/p: ");
	scanf("%d", &digits);

	retArr = complex_code(num, digits);

	printf("output for min number = %d and max number = %d\n", retArr[0], retArr[1]);

	return 0;
}
