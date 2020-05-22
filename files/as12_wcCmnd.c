#include <stdio.h>

int main(int argc, char *argv[])
{
	int size = 0, wordCnt = 0, lines = 0;
	char ch, wordFlag;
	FILE *fp;

	if (argc < 2) {
		printf("Usage: ./a.out filename\n");
		return 0;
	}

	fp = fopen(argv[1], "r");
	if (fp == 0) {
		printf("File not found.\n");
		return 0;
	}

	while ((ch = fgetc(fp)) != EOF) {
		size++;
		if (ch == '\n')
			lines++;
		if (ch == '\n' || ch == ' ')
			wordFlag = 1;
		if (wordFlag && ch != ' ' && ch != '\n') {
			wordCnt++;
			wordFlag = 0;
		}
	}

	printf(" %d %d %d %s\n", lines, wordCnt, size, argv[1]);
	return 0;
}
