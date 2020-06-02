#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[30], tmp[1000], i;

	if (argc < 4) {
		printf("Usage: ./a.out fileName wordToreplace ReplacementWord\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
		printf("%s file not found.\n");
		return 0;
	}

	while (fscanf(fp, "%s", str) != EOF) {
		if (strcmp(str, argv[2]) == 0) {
			i = 0;
			len = strlen(str);
			while((tmp[i++] = fgetc(fp)) != EOF);
			fseek(fp, -i, SEEK_CUR);
			fprintf(fp, "%s", argv[3]);
			i = len;
			while(temp[i])
				fputc(temp[i++], fp);
		}
	}

	printf("%s word replaced with %s in given file.\n", argv[2], argv[3]);
	return 0;
}

