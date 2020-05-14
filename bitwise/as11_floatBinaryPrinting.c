#include <stdio.h>

int main()
{
	float num;
	char *ptr, i, j;

	printf("Enter any float number: ");
	scanf("%f", &num);

	ptr = &num;
	printf("Binary representation of given float number is: ");
	for (i = 4, ptr += 3 ; i > 0; ptr--, i--)
		for (j = 7; j >= 0; j--)
			printf("%d", *ptr>>j&1);
	printf("\n");
	return 0;
}
