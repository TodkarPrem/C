#include <stdio.h>

int main()
{
	int i, j;
	char str[200], ch;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	printf("Enter character u want to delete from given string: ");
	scanf(" %c", &ch);

	for (i = 0; str[i]; i++)
		if (str[i] == ch) {
			for (j = i; str[j]; j++)
				str[j] = str[j+1];
			i--;
		}

	printf("String after deleting %c char : %s\n", ch, str);
	return 0;
}
