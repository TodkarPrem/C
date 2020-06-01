#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[50], i, j, ch, flag = 0;

	if (argc <3) {
		printf("Usage: ./a.out fileName WordToReverse\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
		printf("%s file not present.\n", argv[1]);
		return 0;
	}

	while (fscanf(fp, "%s", str) != EOF)
		if (strcmp(str, argv[2]) == 0) 
			for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
				ch = str[i];
				str[i] = str[j];
				str[j] = ch;

				fseek(fp, -strlen(str), SEEK_CUR);
				fprintf(fp, "%s", str);
				flag = 1;
			}

	if (flag)
		printf("Given word %s reversed from %s file.\n", argv[2], argv[1]);
	else
		printf("%s word not found in %s file.\n", argv[2], argv[1]);
	return 0;
}
