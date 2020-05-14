#include <stdio.h>

int main()
{
	int first, last, temp1, sum, rem;

prev:	printf("Enter first number to be checked: ");
	scanf("%d", &first);

	printf("Enter last number to be checked: ");
	scanf("%d", &last);

	if (first <= 0 || last < first)
		goto prev;

	printf("Armstrong numbers in the given range are: ");
	for ( ; first <= last; first++) {
		for (temp1 = first, sum = 0; temp1; rem = temp1 % 10, temp1 /= 10)
			sum += rem * rem * rem;
		if (sum == first)
			printf("%d ", first);
	}
	printf("\n");
	return 0;
}
