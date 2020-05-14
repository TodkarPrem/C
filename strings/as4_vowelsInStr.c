#include <stdio.h>

int main()
{
	char str[50], i = 0;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	printf("Vowels found in given string are:\n");
	while(str[i])
		switch(str[i++]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				printf("%c ", str[i-1]);
		}
	printf("\n");
	return 0;
}
