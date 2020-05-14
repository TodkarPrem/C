#include <stdio.h>

int main()
{
	int i, j, k, rows;

prev:	printf("Enter number of rows (odd): ");
	scanf("%d", &rows);

	if (rows % 2 == 0)
		goto prev;

	for (i = 0, k = 0; i <= rows; i++) {
		i > rows / 2 ? k-- : k++;

		for (j = rows / 2; j >= k; j--)
			printf(" ");

		for (j = 1; j < 2 * k; j++)
			printf("%d", j);
		printf("\n");
	}
}
