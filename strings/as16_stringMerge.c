#include <stdio.h>

int main()
{
	int i, j, k;
	char str1[100], str2[100], str3[200];

	printf("Enter string1: ");
	scanf("%s", str1);
	printf("Enter string2: ");
	scanf(" %s", str2);

	for (i=0, j=0, k=0; str1[i] && str2[j]; )
		if (k % 2 == 0)
			str3[k++] = str1[i++];
		else
			str3[k++] = str2[j++];

	if (str1[i] == '\0' && str2[j] != '\0')
		for ( ; str2[j]; j++)
			str3[k++] = str2[j];
	
	if (str1[i] != '\0' && str2[j] == '\0')
		for ( ; str1[i]; i++)
			str3[k++] = str1[i];

	str3[k] = '\0';
	printf("Final merged string is: %s\n", str3);
	return 0;
}
