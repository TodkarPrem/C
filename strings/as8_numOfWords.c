#include <stdio.h>

int main()
{
	unsigned char str[1000] = {}, cnt = 0, SpaceFlag = 0, i = 0;

	printf("Enter string with spaces: ");
	scanf("%[^\n]", str);

	while(str[i]) {
		if (str[i++] == ' ')
			SpaceFlag = 1;
		else if (SpaceFlag || str[i] == 0) {
			SpaceFlag = 0;
			cnt++;
		}
	}

	printf("Number of words present in string are: %d\n", cnt);
	return 0;
}
