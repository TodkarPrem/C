#include <stdio.h>

int fact(int num)
{
	int f;

	for (f = 1; num; f = f * num--);

	return f;
}

int main()
{
	int i, j, rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < rows - i; j++)
			printf(" ");

		for (j = 0; j <= i; j++)
			printf("%d ", fact(i)/(fact(i - j) * fact(j)));
		printf("\n");
	}
	return 0;
}
