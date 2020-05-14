#include <stdio.h>

int main()
{
	char str1[50], str2[50], i = -1;

	printf("Enter string1: ");
	scanf("%[^\n]", str1);
	printf("Enter string2: ");
	scanf(" %[^\n]", str2);
	
	while(str1[++i])
		if (str1[i] != str2[i])
			break;
	if (str1[i] == str2[i])
		printf("Both strings are equal\n");
	else if (str1[i] > str2[i])
		printf("String1 is greater than string2\n");
	else
		printf("String1 is less than string2\n");

	return 0;
}
