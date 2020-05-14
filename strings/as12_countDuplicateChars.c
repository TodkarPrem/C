#include <stdio.h>

int main()
{
	int i, j, k, cnt;
	char str[100], tmp[100], ch;

	printf("Enter string: ");
	scanf("%[^\n]", str);

	strcpy(tmp, str);
	for (i = 0; tmp[i]; i++) {
		for (cnt = 1, j = i+1; tmp[j]; j++)
			if (tmp[i] == tmp[j]) {
				for (k = j; str[k]; k++)
					tmp[k] = tmp[k+1];
				cnt++;
			}
		if (cnt > 1)
			printf("%c ---- %d\n", tmp[i], cnt);
	}
	return 0;
}
