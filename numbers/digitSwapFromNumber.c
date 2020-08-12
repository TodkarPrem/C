#include <stdio.h>

int main()
{
	int num, pos, temp, i;
	int arr[12] = {};

	printf("Enter any num: ");
	scanf("%d", &num);

	printf("Enter position of digit to reverse from start & last: ");
	scanf("%d", &pos);

	i = 0;
	while (num) {
		arr[i++] = num % 10;
		num /= 10;
	}

	if (i/2 >= pos) {
		temp = arr[pos - 1];
		arr[pos - 1] = arr[i - pos];
		arr[i - pos] = temp;
	} else
		printf("ERROR: Invalid Position.\n");

	num = 0;
	while(i >= 0)
		num = num * 10 + arr[i--];

	printf("Number after digit reversal = %d\n", num);

	return 0;
}
