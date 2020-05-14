#include <stdio.h>

int main()
{
	int num, i, j, m, n;

	printf("Enter any num: ");
	scanf("%d", &num);

	printf("\nBefore reversing nibble: ");
	for (i = 31; i >= 0; printf("%d", num >> i-- & 1));

	for (i = 31, j = 0; j < 4; i--, j++) {
		m = num >> i & 1;
		n = num >> j & 1;

		if (m != n) {
			num = num ^ 1 << i;
			num = num ^ 1 << j;
		}
	}

	printf("\nAfter reversing nibble : ");
	for (i = 31; i >= 0; printf("%d", num >> i-- & 1));
	printf("\n");

	return 0;
}
