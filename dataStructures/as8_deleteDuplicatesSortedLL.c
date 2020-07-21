#include <stdio.h>
#include <stdlib.h>

typedef struct singleLL {
	int num;
	struct singleLL *next;
} SLL;


void addNode_sorted(SLL **hptr)
{
	int num;
	SLL *ptr, *tmp;

	printf("Enter integer value: ");
	scanf("%d", &num);

	ptr = (SLL *) malloc(sizeof(SLL));
	ptr->num = num;

	if (*hptr == 0 || (*hptr)->num > num) {
		ptr->next = *hptr;
		*hptr = ptr;
	}
	else {
		tmp = *hptr;
		while (tmp) {
			if (tmp->next == 0 || tmp->next->num > num) {
				ptr->next = tmp->next;
				tmp->next = ptr;
				break;
			}
			tmp = tmp->next;
		}
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
		if (tmp1->num == tmp1->next->num) {
			//printf("Duplicate Number found.\n");
			tmp2 = tmp1->next;
			tmp1->next = tmp1->next->next;
			free(tmp2);
		}
		tmp1 = tmp1->next;
	}
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		addNode_sorted(&hp);
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
