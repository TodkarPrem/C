#include <stdio.h>
int main()
{
	char ch;

	printf("Enter any char: ");
	scanf("%c", &ch);

	printf("Converted char = %c\n", ch ^ 1 << 5);
	return 0;
}
