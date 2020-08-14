#include <stdio.h>

struct one {
	char ch;
	int num1;
	float num2;
};

struct two {
	char ch;
	int num1;
	double num2;
};

struct three {
	char ch;
	char ch2;
	int num1;
	float num2;
	char ch3
};

struct four {
	int num1;
	double num2;
	int num3;
};

struct five {
	int num1;
	int num3;
	double num2;
};


int main()
{
	printf("%d %d %d %d %d\n", sizeof(struct one), sizeof(struct two),
			sizeof(struct three), sizeof(struct four),
			sizeof(struct five));
	return 0;
}
