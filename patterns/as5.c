#include <stdio.h>
int main()
{
	int i, j, k, rows;

prev:	printf("Enter number of rows (odd): ");
	scanf("%d", &rows);

	if (rows % 2 == 0)
		goto prev;

	for (i = 0, k = -1; i < rows; i++) {
		i <= rows / 2 ? k++ : k--; 
		for(j = 0; j <= k * 2; j++)
			if (j % 2 == 0)
				printf("%d", k + 1);
			else
				printf("*");
		printf("\n");
	}
	return 0;
}
