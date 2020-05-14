#include <stdio.h>

char numArr[][10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void numToWords(int num)
{
	if (num)
	{
		numToWords(num/10);
		printf("%s ", numArr[num%10]);
	}
	return;
}

int main()
{
	int num;
	printf("Enter any num: ");
	scanf("%d", &num);

	numToWords(num);
	printf("\n");
	return 0;
}

