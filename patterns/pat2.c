#include <stdio.h>

int main() 
{
	int i, j, row;

	printf("Enter number rows: ");
	scanf("%d", &row);

	for (i = 0; i < row; i++) {
		for (j = row - i; j > 0; j--)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
