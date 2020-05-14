#include <stdio.h>

int main()
{
	int i, j;
	char str[200];

	printf("Enter string: ");
	scanf("%[^\n]", str);

	for (i = 0; str[i]; i++)
		if (str[i] == ' ')
			if (str[i+1] == ' ') {
				for (j = i; str[j]; j++)
					str[j] = str[j+1];
				i--;
			}

	printf("String after removeal of spaces: %s\n", str);
	return 0;
}
