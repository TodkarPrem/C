#include <stdio.h>

int main()
{
	int i, j, rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < i; j++)
			printf(" ");
		for (j = rows - i; j > 0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
