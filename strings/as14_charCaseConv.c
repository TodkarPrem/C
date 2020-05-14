#include <stdio.h>

int main()
{
	int i = 0;
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	for (i; str[i]; i++)
		str[i] = str[i] ^ 32;

	printf("After converting case of string: %s\n", str);
	return 0;
}
