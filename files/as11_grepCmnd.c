#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[50];

	if (argc < 3) {
		printf("./a.out filename word\n");
		return 0;
	}

	fp = fopen(argv[1], "r");
	if (fp == 0) {
		printf("File not found.\n");
		return 0;
	}

	while(fgets(str, 50, fp)) 
		if (strstr(str, argv[2]))
				printf("%s", str);

	fclose(fp);
	return 0;
}
