#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[50];

	if (argc < 2) {
		printf("Usage: ./a.out FileName\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
		printf("%s file not found.\n", argv[1]);
		return 0;
	}

	while (fscanf(fp, "%s", str) != EOF)
		if (str[0] >= 'a' && str[0] <= 'z') {
			str[0] = str[0] - 32;
			fseek(fp, -strlen(str), SEEK_CUR);
			fprintf(fp, "%s", str);
		}

	printf("Modified given file.\n");
	return 0;
}
