#include <stdio.h>

int main()
{
	int i, j, k, l = 2;

	printf("Enter starting number: ");
	scanf("%d", &i);

	printf("Enter last number to be checked: ");
	scanf("%d", &j);

	printf("Twin Prime numbers are:\n");
	for( ; i <= j; i++) {
		for (k = 2; k < i; k++)
			if (i % k == 0)
				break;
		if (i == k) {
			if (k - l == 2)
				printf("%d %d\n", l, k);
			l = k;
		}
	}
}
