#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i = 0, j = 0, tmp = 0;
	char str[1000] = {}, ch;
	
	if (argc < 2) {
		printf("Usage: ./a.out fileName\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
		printf("%s file not found\n", argv[1]);
		return 0;
	}

	while ((str[i++] = fgetc(fp)) != EOF);
	rewind(fp);
<<<<<<< HEAD
	tmp = --i;

	for (j = 0, i--; j < i; j++, i--) {
=======
	tmp = i--;

	for (j = 0; j < i; j++, i--) {
>>>>>>> 5dd3146680c9dc33b51dc72c7da789f89f0384fc
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}

	i = 0;
	while (tmp--)
		fputc(str[i++], fp);

	printf("File contents reversed.\n");
	return 0;
}
