#include <stdio.h>
int arith_progression(int n1, int n2, int ele)
{
	int temp = n2 - n1, retValue = n2;

	ele -= 2;

	while (ele--)
		retValue += temp;

	return retValue;
}

int main()
{
	int n1, n2, ele, ret;

	printf("Enter Number1: ");
	scanf("%d", &n1);
	
	printf("Enter Number2: ");
	scanf("%d", &n2);

	printf("Enter element in arithmatic progression: ");
	scanf("%d", &ele);

	ret = arith_progression(n1, n2, ele);

	printf("The number we want = %d\n", ret);

	return 0;
}
