#include <stdio.h>

int main()
{
	int i, j, k, rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	for (i = 0; i < rows; i++) {
		for (j = 1 - rows; j < rows; j++) {
			k = j;
			if (k < 0)
				k = -k;

			if (i <= k)
				printf("%c", 64 + rows - k);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
