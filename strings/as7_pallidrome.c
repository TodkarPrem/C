#include <stdio.h>

int main()
{
	char str[50], revStr[50], i=0, j=0;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	while(str[i++]);
	for (j=0, i -= 2; i >= 0; revStr[j]=str[i], j++, i--);

	printf("Rev string is: %s\n", revStr);
	if (!strcasecmp(str, revStr))
		printf("Given string is pallindrome\n");
	else
		printf("Given string is not pallindrome\n");

	return 0;
}
