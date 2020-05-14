#include <stdio.h>

int main()
{
	char str[50], ch, cnt = 0, i = 0;

	printf("Enter string: ");
	scanf("%[^\n]", str);
	printf("Enter char to search in string: ");
	scanf(" %c", &ch);

	while(str[i])
		if (str[i++] == ch)
			cnt++;

	printf("Char found %d times in given string.\n", cnt);
	return 0;
}
