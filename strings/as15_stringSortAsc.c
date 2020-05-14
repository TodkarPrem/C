#include <stdio.h>

int main()
{
	int i = 0, j;
	char str[100], tmpCh;

	printf("Enter any string: ");
	scanf("%s", str);

	for (i=0; str[i]; i++)
		for (j = i+1; str[j]; j++)
			if (str[i] > str[j]) {
				tmpCh = str[i];
				str[i] = str[j];
				str[j] = tmpCh;
			}

	printf("After sorting above string in ascending order: %s\n", str);
	return 0;
}
