#include <stdio.h>

#define CLEAR(num, pos) (num & ~(1 << pos))

int main()
{
	int num, pos;
	printf("Enter any num: ");
	scanf("%d", &num);
up:	printf("Enter position of a bit u want to clear: ");
	scanf("%d", &pos);
	if (pos > 31 || pos < 0)
		goto up;

	num = CLEAR(num, pos);
	printf("After clearing %d bit updated num is : %d\n", pos, num);
	return 0;
}
