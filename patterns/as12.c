#include <stdio.h>

int main()
{
	int i, j, k, rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	for (i = 1; i <= rows; i++) {
		for (j = 1 - rows; j < rows; j++) {
			j > 0 ? k = 5 - j: (k = 5 + j);

			if (k <= i )
				printf("%d", k);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
