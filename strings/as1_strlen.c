#include <stdio.h>

int main()
{
	char str1[50], *ptr, len = 0;

	printf("Enter string: ");
	scanf("%[^\n]", str1);

	ptr = str1;
	while(*ptr++)
		len++;

	printf("Length of given string is %d\n", len);
	return 0;
}
