#include <stdio.h>

int main()
{
	int num;

	printf("Enter any num: ");
	scanf("%d", &num);

	num & 7 ? printf("Not divisible by 8.\n") : printf("Divisible by 8\n");
	return 0;
}
