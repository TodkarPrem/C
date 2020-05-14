#include <stdio.h>

int versionCompare(const char *ptr1, const char *ptr2)
{
	int i = 0, j = 0, n1, n2;

	while(ptr1[i])
		if (ptr1[i++] == '.' || (ptr1[i] > 47 && ptr1[i] < 58)) {
			for (j = i, n1 = n2 = 0; ptr1[i] != '.' && ptr2[j] != '.' && ptr1[j] && ptr2[j]; j++) {
				n1 = n1*10 + ptr1[j]-48;
				n2 = n2*10 + ptr2[j]-48;
			}
			if (ptr1[j] != ptr2[j])
				return ptr1[j]-ptr2[j];
			if (n1 != n2)
				return n1-n2;
			i = j;
		}
	return 0;
}

int main(int argc, char *argv[])
{
	int retValue;

	if (argc < 3) {
		printf("Usage: ./a.out version1 version2\n");
		return 0;
	}

	retValue = versionCompare(argv[1], argv[2]);
	if (retValue > 0)
		printf("%s is higher version than %s\n", argv[1], argv[2]);
	else if (retValue < 0)
		printf("%s is lower version than %s\n", argv[1], argv[2]);
	else
		printf("%s is equal version to %s\n", argv[1], argv[2]);

	return 0;
}


