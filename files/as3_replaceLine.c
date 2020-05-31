#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fd;
	char str[1000] = {}, ch;
	int i = 0, lnNum = 1, tmp;

	if (argc < 4) {
		printf("Usage: ./a.out fileName lineNo StringToReplace_SpecifiedLine\n");
		return 0;
	}

	fd = fopen(argv[1], "r+");
	while ((ch = fgetc(fd)) != EOF)
		str[i++] = ch;

	str[i] = 0;
	rewind(fd);
	tmp = atoi(argv[2]);
	i = 0;
	while (str[i]) {
		if (lnNum == tmp) {
			fprintf(fd, "%s\n", argv[3]);
			while (str[i++] != '\n');
		}
		if (str[i] == '\n')
			lnNum++;
		fputc(str[i++], fd);
	}

	printf("Replaced given line...\n");
	return 0;
}
