#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *f1, *f2, *f3;
	char str[50];
	
	if (argc < 3) {
		printf("Usage: ./a.out file1 file2\n");
		return 0;
	}

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	
	if (!f1 || !f2) {
		printf("Input file not found.\n");
		return 0;
	}

	f3 = fopen("OPFile", "w");

	for (int i = 0, flag1 = 1, flag2 = 1; flag1 || flag2; i++) {
		if (i % 2) {
			if(fgets(str, 49, f2) != 0)
				fputs(str, f3);
			else
				flag1 = 0;
		}
		else
			if(fgets(str, 49, f1) != 0)
				fputs(str, f3);
			else
				flag2 = 0;
	}

	printf("Merged files into OPFile.\n");
	return 0;
}

