#include <stdio.h>

int main()
{
	int i, j, k;
	char str[100], ch;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	for (i = 0; str[i]; i++)
		for (j = i+1; str[j]; j++)
			if (str[i] == str[j]) {
				for (k = j; str[k]; k++)
					str[k] = str[k+1];
				j--;
			}

	printf("After removing duplicate chars from string: %s\n", str);
	return 0;
}
