#include <stdio.h>

int main(int argc, char *argv[])
{
	char ch, i = 2;
	FILE *fp, *fd;

	if (argc < 3) {
		printf("Usage: a.out sourceFile destFile...\n");
		return 0;
	}

	fp = fopen(argv[1], "r");
	if(fp == 0) {
		printf("File not found...\n");
		return 0;
	}

	while (argc-- > 2) {
		fd = fopen(argv[i++], "w");
		while ((ch = fgetc(fp)) != EOF)
			fputc(ch, fd);
		rewind(fp);
	}

	printf("Files copied successfully...\n");
	return 0;
}
