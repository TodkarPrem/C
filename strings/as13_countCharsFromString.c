#include <stdio.h>

int main()
{
	int i, lcnt = 0, ucnt = 0, scnt = 0, dcnt = 0;
	char str[200];

	printf("Enter any string: ");
	scanf("%[^\n]", str);

	for (i = 0; str[i]; i++)
		if (str[i] >= '0' && str[i] <= '9')
			dcnt++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lcnt++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			ucnt++;
		else
			scnt++;

	printf("Total lower characters count in string: %d\n", lcnt);
	printf("Total upper characters count in string: %d\n", ucnt);
	printf("Total digit characters count in string: %d\n", dcnt);
	printf("Total special characters count in string: %d\n", scnt);

	return 0;
}
