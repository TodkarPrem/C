#include <stdio.h>

void fibonacci(int num)
{
	static int i = 0, j = 1, tmp = 0;
	if (num > 1)
	{
		printf("%d ", j);
		tmp = i, i = j, j += tmp;
		fibonacci(--num);
	}
	else
		return;
}

int main()
{
	int num;
	do
	{
	printf("Enter how many number you want to print from fibonacci series(> 2): ");
	scanf("%d", &num);
	} while (num < 2);

	printf("0 ");
	fibonacci(num);
	printf("\n");

	return 0;
}

