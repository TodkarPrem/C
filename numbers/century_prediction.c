#include <stdio.h>

int century(int year)
{
	if (year % 100)
		return (year / 100 + 1);
	else
		return (year / 100);
}

int main()
{
	int year, ret;

	printf("Enter year: ");
	scanf("%d", &year);

	ret = century(year);

	printf("Given year lies in %d century\n", ret);
	
	return 0;
}
