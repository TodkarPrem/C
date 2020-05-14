#include <stdio.h>

void primeNum(int cnt)
{
	static int num = 2;
	int i; 

	if (cnt) {
		for (i=2; i < num; i++)
			if (num % i == 0)
				break;
		if (num == i) {
			printf("%d ", num);
			cnt--;
		}
		num++;
		primeNum(cnt);
	}
	return;
}

int main()
{
	int cnt;

	printf("Enter how many prime numbers u want to print(2 onwards): ");
	scanf("%d", &cnt);
	primeNum(cnt);

	printf("\n");
	return 0;
}
