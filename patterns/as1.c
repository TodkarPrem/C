#include <stdio.h>
int main()
{
	int rows, i, j, k;

prev:	printf("Enter number of rows (odd value): ");
	scanf("%d", &rows);

	if (rows % 2 == 0)
		goto prev;

	for (i = -rows / 2; i <= rows / 2; i++) {
		k = i;
		if (k < 0)
			k = -k;
		for (j = 0; j <= rows / 2; j++)
			if (j >= k)
				printf("* ");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}
