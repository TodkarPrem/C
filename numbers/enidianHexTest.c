#include <stdio.h>

int main()
{
	int num = 0x12345678, i;

	for (i = 31; i >= 0; printf("%d", num >> i & 1), i--);

	printf("\n");
	return 0;
}
