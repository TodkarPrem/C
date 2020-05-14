#include <stdio.h>

void print(int *);

int main()
{
	int i, j, l, m, n, sum, first, last;
	int perfect[500] = {}, abundunt[500] = {}, deficient[500] = {};

prev:	printf("Enter first number to check: ");
	scanf("%d", &first);

	printf("Enter last number to check: ");
	scanf("%d", &last);

	if (first <= 0 || last <= 0)
		goto prev;

	for (l = m = n = 0 ; first <= last; first++) {
		i = first / 2;

		for (j = 1, sum = 0; j <= i; j++)
			if (first % j == 0)
				sum += j;

		if (first == sum)
			perfect[l++] = first;
		else if (first > sum)
			deficient[n++] = first;
		else
			abundunt[m++] = first;
	}

	printf("\nPerfect numbers in given range are:\n");
	print(perfect);
	printf("Abundunt numbers in given range are:\n");
	print(abundunt);
	printf("Deficient numbers in given range are:\n");
	print(deficient);
}


void print(int *arr)
{
	int i;

	for (i = 0; arr[i] != 0; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}
