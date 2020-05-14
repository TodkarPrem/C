#include <stdio.h>
int main()
{
	int rows, i, j, k;

prev:	printf("Enter number of rows (odd): ");
	scanf("%d", &rows);

	if (rows % 2 == 0)
		goto prev;

	for (i = -rows / 2; i <= rows /2; i++) {
		k = i;
		if (k < 0)
			k = -k;

		for (j = rows + k - 2 ; j > 0; j--)
			if (j <= 2 * k + 1)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}
