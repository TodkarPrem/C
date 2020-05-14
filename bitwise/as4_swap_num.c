#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Before swap:\n");
	printf("Enter a: ");
	scanf("%d", &a);

	printf("Enter b: ");
	scanf("%d", &b);

	a ^= b;
	b ^= a;
	a ^= b;

	printf("After swap: a = %d b = %d\n", a, b);
	return 0;
}
