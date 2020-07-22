#include <stdio.h>

int main()
{
	int start, end, temp;

	printf("Enter starting number: ");
	scanf("%d", &start);

	printf("Enter last number to check: ");
	scanf("%d", &end);

	printf("Prime numbers between range %d to %d are as follows: ", start, end);
	for( ; start <=end; start++) {
		for (temp = 2; temp < start; temp++)
			if (start % temp == 0)
				break;
		if (start == temp)
			printf("%d ", temp);
	}
	printf("\n");
	return 0;
}
