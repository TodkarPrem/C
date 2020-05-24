#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[100];
	FILE *fp, *fd;
	int i = 1, tmp;

	if (argc != 3) {
	       printf("Usage: ./a.out filename line_No\n");
	       return 0;
	}

	fp = fopen(argv[1], "r+");
	fd = fopen("copied_file", "w");
	if (fp == 0) {
		printf("%s file not found.\n", argv[1]);
		return 0;
	}

	tmp = atoi(argv[2]);
	while (fgets(str, 100, fp))
		if (tmp != i++)
			fputs(str, fd);

	fclose(fp);
	fclose(fd);
	printf("Given line deleted from %s file.\n", argv[1]);
	return 0;
}
