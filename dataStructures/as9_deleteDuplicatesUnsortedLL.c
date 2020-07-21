#include <stdio.h>
#include <stdlib.h>

typedef struct singleLL {
	int num;
	struct singleLL *next;
} SLL;


void addNode(SLL **hptr)
{
	int num;
	SLL *ptr, *tmp;

	printf("Enter integer value: ");
	scanf("%d", &num);

	ptr = (SLL *) malloc(sizeof(SLL));
	ptr->num = num;

	if (*hptr == 0) {
		ptr->next = *hptr;
		*hptr = ptr;
	}
	else {
		tmp = *hptr;
		while (tmp->next)
			tmp = tmp->next;
		ptr->next = 0;
		tmp->next = ptr;
	}
}


void print(SLL *ptr)
{
	while (ptr) {
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}


void deleteDuplicates(SLL *ptr)
{
	SLL *tmp1 = ptr, *tmp2, *dup;

	while (tmp1->next) {
		tmp2 = tmp1;
		while (tmp2->next) {
			if (tmp1->num == tmp2->next->num) {
				printf("Duplicate Number found.\n");
				dup = tmp2->next;
				tmp2->next = tmp2->next->next;
				free(dup);
			}
			else
				tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		addNode(&hp);
		printf("want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("Added nodes as it is: ");
	print(hp);
	deleteDuplicates(hp);
	printf("Nodes after deleting nodes: ");
	print(hp);

	return 0;
}
