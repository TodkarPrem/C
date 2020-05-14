#include <stdio.h>

int main()
{
	int first, last, rev, temp;

prev:	printf("Enter first number to be checked: ");
	scanf("%d", &first);

	printf("Enter last number to be checked: ");
	scanf("%d", &last);

	if (first < 10 || last < first)
		goto prev;

	printf("Pallindrome numbers in given range are: ");
	for ( ; first <= last; first++) {
		for(temp = first, rev = 0; temp; temp = temp / 10)
			rev = rev * 10 + temp % 10;

		if (rev == first)
			printf("%d ", first);
	}
	printf("\n");
	return 0;
}
