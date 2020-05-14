#include <stdio.h>

char *strrev(char *ptr)
{
	static char str[50] = {}, j = 0;
	if (*ptr) {
		strrev(ptr+1);
		str[j++] = *ptr;
	}
	return str;
}


int main()
{
	char str[50], lrev[50], *rrev, i, j = 0;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	while (str[j++]);
	for (i=0, j -= 2; j >= 0; i++, j--)
		lrev[i] = str[j];
	printf("string reversed using loop: %s\n", lrev);

	rrev = strrev(str);
	printf("string reversed using recursion: %s\n", rrev);
	return 0;
}
