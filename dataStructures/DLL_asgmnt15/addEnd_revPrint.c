#include <stdio.h>
#include <stdlib.h>

typedef struct doublell {
	struct doublell *prev;
	int num;
	struct doublell *next;
} DLL;

DLL *hp = 0;

void add_end(void)
{
	DLL *temp1, *temp2;
	
	temp1 = (DLL *) malloc(sizeof(DLL));
	printf("Enter any number: ");
	scanf("%d", &temp1->num);

	temp1->prev = temp1->next = 0;
	if (hp == 0)
		hp = temp1;
	else {
		temp2 = hp;
		while (temp2->next)
			temp2 = temp2->next;

		temp1->prev = temp2;
		temp2->next = temp1;
	}
}


void reversePrint(void)
{
	DLL *p = hp;
	while (p->next)
		p = p->next;

	while (p) {
		printf("%d", p->num);
		p = p->prev;
		if (p)
			printf(" -- ");
	}
	printf("\n");
}


int main()
{
	char ch;

	do {
		add_end();
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nPrinting added nodes in reverse order: ");
	reversePrint();
}
