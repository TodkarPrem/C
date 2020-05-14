#include <stdio.h>

int main()
{
	int i, j, rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i++) {
		for (j = rows; j > i; j--)
			printf(" ");
		for (j = 1; j < 2 * i; j++)
			printf("%d", j);
		printf("\n");
	}
}
