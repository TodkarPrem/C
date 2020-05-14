#include <stdio.h>

void binaryPrint(int num);

int main()
{
	int num, pos, tmp1, tmp2, tmp3;

	printf("Enter number to operate on: ");
	scanf("%d", &num);

	printf("Enter bit position: ");
	scanf("%d", &pos);

	printf("Number without bit operations: ");
	binaryPrint(num);

	printf("Number after setting a bit: ");
	tmp1 = num | 1 << pos;
	binaryPrint(tmp1);

	printf("Number after clearing a bit: ");
	tmp2 = num & ~(1 << pos);
	binaryPrint(tmp2);

	printf("Number after complimenting a bit: ");
	tmp3 = num ^ 1 << pos;
	binaryPrint(tmp3);

	return 0;
}

void binaryPrint(int num)
{
	int i;

	for (i = 31; i >= 0; i--)
		printf("%d", num >> i & 1);
	printf("\n");
}
