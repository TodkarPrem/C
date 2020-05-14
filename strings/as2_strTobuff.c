#include <stdio.h>

int main()
{
	char str[50], buff[50], i = 0;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	for (i=0; str[i]; buff[i] = str[i], i++);
	printf("Buff content after copy: %s\n", buff);
	return 0;
}
