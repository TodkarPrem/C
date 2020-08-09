#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Usage: ./a.out num1 num2\n");
		return 0;
	}

	if (fork() == 0) {
		int x, y;
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		printf("In child... x = %d, y = %d\n", x, y);
		exit(x+y);
	}
	else {
		int s;
		wait(&s);
		s = s >> 8;
		printf("In parent... sum = %d\n", s);
	}

	return 0;
}

