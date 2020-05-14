#include <stdio.h>

int main()
{
	int num, bits, i;

	printf("Enter any num: ");
	scanf("%d", &num);
	printf("Enter how many bits to rotate: ");
	scanf("%d", &bits);

	printf("Before rotating bits: ");
	for (i = 31; i >= 0; printf("%d", num >> i-- & 1));

	num = num >> bits | num << (32 - bits);

	printf("\nAfter rotating bits : ");
	for (i = 31; i >= 0; printf("%d", num >> i-- & 1));
	printf("\n");
	return 0;
}
