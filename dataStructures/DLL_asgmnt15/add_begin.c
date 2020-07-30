#include <stdio.h>
#include <stdlib.h>

typedef struct doublell {
	struct doublell *prev;
	int num;
	struct doublell *next;
} DLL;

DLL *hp = 0;

void add_begin(void)
{
	DLL *temp = (DLL *) malloc(sizeof(DLL));
	printf("Enter any number: ");
	scanf("%d", &temp->num);

	temp->prev = temp->next = 0;
	if (hp == 0)
		hp = temp;
	else {
		temp->next = hp;
		hp->prev = temp;
		hp = temp;
	}
}


void print(void)
{
	DLL *p = hp;
	while (p) {
		printf("%d", p->num);
		p = p->next;
		if (p)
			printf(" -- ");
	}
	printf("\n");
}


int main()
{
	char ch;

	do {
		add_begin();
		printf("Want to continue adding nodes(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	print();
}
