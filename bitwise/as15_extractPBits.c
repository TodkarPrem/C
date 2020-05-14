#include <stdio.h>

int main()
{
	int num, pos, cnt, i;

	printf("Enter any num: ");
	scanf("%d", &num);
up:	printf("Enter how many bits u want to extract from above number: ");
	scanf("%d", &cnt);
	printf("Enter pos of starting bit: ");
	scanf("%d", &pos);

	if (pos < 0 || (pos+cnt > 31)) {
		printf("\nPlease provide proper input...\n");
		goto up;
	}
	
	printf("Extracted bits are: ");
	for (i = pos+cnt-1; i >= pos; printf("%d", num >> i&1), i--);
	printf("\n");
	return 0;
}
