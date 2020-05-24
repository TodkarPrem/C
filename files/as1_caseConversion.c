#include <stdio.h>

int main(int argc, char *argv[])
{
	char *tempPtr, ch;
	int i = 0;
	FILE *fp;

	if (argc != 2) {
		printf("Usage: ./a.out filename\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
		printf("%s File not found.\n", argv[1]);
		return 0;
	}

	while ((ch = fgetc(fp)) != EOF)
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <='z')) {
			fseek(fp, -1, SEEK_CUR);
			ch = ch ^ 32;
			fputc(ch, fp);
		}

	fclose(fp);
	printf("Character case of given file is inverted.\n");
	return 0;
}
