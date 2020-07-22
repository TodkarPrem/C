#include <stdio.h>

int main()
{
	int num1, num2, sum1, sum2, tmp1;

	printf("Enter last number to be checked: ");
	scanf("%d", &num1);

	printf("Enter first number to be checked: ");
	scanf("%d", &num2);

	for (tmp1 = 1, sum1 = 0; tmp1 <= num1 / 2; tmp1++)
		if (num1 % tmp1 == 0)
			sum1 += tmp1;

	for (tmp1 = 1, sum2 = 0; tmp1 <= num2 / 2; tmp1++)
		if (num2 % tmp1 == 0)
			sum2 += tmp1;

	if (sum1 == num2 && sum2 == num1)
		printf("%d and %d are friendly ammicable numbers.\n", num1, num2);
	else
		printf("%d and %d are not friendly ammicable numbers.\n", num1, num2);
	return 0;
}
