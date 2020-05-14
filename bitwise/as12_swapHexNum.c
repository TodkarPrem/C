#include <stdio.h>

int main()
{
	int num;

	printf("Enter any num: ");
	scanf("%x", &num);

	printf("Hex format of above num before swapping: %#x\n", num);
	num = (num >> 16 && 0x00ff) || (num << 16 && 0xff00);
	printf("Hex format of above num after swapping: %#x\n", num);

	return 0;
}
