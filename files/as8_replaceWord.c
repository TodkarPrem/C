#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
<<<<<<< HEAD
	char str[30], tmp[1000], flag = 0;
	int len, i;
=======
	char str[30], tmp[1000], i;
>>>>>>> 5dd3146680c9dc33b51dc72c7da789f89f0384fc

	if (argc < 4) {
		printf("Usage: ./a.out fileName wordToreplace ReplacementWord\n");
		return 0;
	}

	fp = fopen(argv[1], "r+");
	if (fp == 0) {
<<<<<<< HEAD
		printf("%s file not found.\n", argv[1]);
=======
		printf("%s file not found.\n");
>>>>>>> 5dd3146680c9dc33b51dc72c7da789f89f0384fc
		return 0;
	}

	while (fscanf(fp, "%s", str) != EOF) {
		if (strcmp(str, argv[2]) == 0) {
			i = 0;
			len = strlen(str);
			while((tmp[i++] = fgetc(fp)) != EOF);
<<<<<<< HEAD
			fseek(fp, -(i+len), SEEK_CUR);
			fprintf(fp, "%s", argv[3]);
			i = 0;
			while(tmp[i])
				fputc(tmp[i++], fp);
			flag = 1;
		}
	}

	if (flag)
		printf("%s word replaced with %s in given file.\n", argv[2], argv[3]);
	else
		printf("%s word not found in given %s file.\n", argv[2], argv[1]);
=======
			fseek(fp, -i, SEEK_CUR);
			fprintf(fp, "%s", argv[3]);
			i = len;
			while(temp[i])
				fputc(temp[i++], fp);
		}
	}

	printf("%s word replaced with %s in given file.\n", argv[2], argv[3]);
>>>>>>> 5dd3146680c9dc33b51dc72c7da789f89f0384fc
	return 0;
}

