#include <stdio.h>
#include <string.h>

int toDigit(char ch)
{
    return (ch - '0');
}

int main(int argc, char *argv[])
{
	int n = strlen(argv[1]);
    	int sumofdigit[n];

    	sumofdigit[0] = toDigit(argv[1][0]);
    	int res = sumofdigit[0];

	for (int i = 1; i < n; i++) {
        	int numi = toDigit(argv[1][i]);

	        sumofdigit[i] = (i + 1) * numi + 10 * sumofdigit[i - 1];
        	res += sumofdigit[i];
    	}

   	printf("Result: %d\n", res);
	return 0;
}
