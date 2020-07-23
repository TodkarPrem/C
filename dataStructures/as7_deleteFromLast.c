#include <stdio.h>
#include <stdlib.h>

typedef struct singleLL {
	char ch;
	struct singleLL *next;
} SLL;


void addNode_middle(SLL **ptr)
{
	SLL *tmp, *tmp1;

	tmp = (SLL *) malloc(sizeof(SLL));
	printf("Enter alphabet char: ");
	scanf(" %c", &tmp->ch);

	if (*ptr == 0 || (*ptr)->ch > tmp->ch) {
		tmp->next = *ptr;
		*ptr = tmp;
	}
	else {
		tmp1 = *ptr;
		while (tmp1) {
			if (tmp1->next == 0 || tmp1->next->ch > tmp->ch) {
				tmp->next = tmp1->next;
				tmp1->next = tmp;
				break;
			}
			tmp1 = tmp1->next;
		}
	}
}


void print(SLL *p)
{
	while (p) {
		printf("%c", p->ch);
		p = p->next;
		if (p)
			printf(" -- ");
	}
	printf("\n");
}


int count(SLL *p)
{
	int c = 0;
	while (p) {
		c++;
		p = p->next;
	}
	return c;
}


void deleteNode(SLL **p)
{
	int cnt, node, i;
	SLL *tmp1, *tmp2 = 0;

	printf("Enter which node from last you want to delete from Linked List: ");
	scanf("%d", &node);

	cnt = count(*p);

	if (node > cnt) {
		printf("Node number out of range...\n");
		return;
	}

	tmp1 = *p;
	for (i = 0; i < cnt - node; i++) {
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}

	if (tmp2 == 0) {
		*p = tmp1->next;
		free(tmp1);
	}
	else {
		tmp2->next = tmp1->next;
		free(tmp1);
	}
	return;
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		addNode_middle(&hp);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'Y' || ch == 'y');

	print(hp);
	deleteNode(&hp);
	print(hp);

	return 0;
}
