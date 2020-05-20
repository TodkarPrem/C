#include <stdio.h>
#include <stdlib.h>

typedef struct single_list {
	int num;
	struct single_list *next;
} SLL;

void addNode(SLL **hptr, int num)
{
	SLL *ptr, *tmp;
	ptr = (SLL *) malloc(sizeof(SLL));
	ptr->num = num;

	if (*hptr == 0 || (*hptr)->num > num) {
		ptr->next = *hptr;
		*hptr = ptr;
	}
	else {
		tmp = *hptr;
		while(tmp) {
			if (tmp->next == 0 || tmp->next->num > num) {
				ptr->next = tmp->next;
				tmp->next = ptr;
				break;
			}
			tmp = tmp->next;
		}
	}
}


void printList(SLL *ptr)
{
	while (ptr) {
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
}


int countNodes(SLL *ptr)
{
	int cnt = 0;
	while (ptr)
		cnt++, ptr = ptr->next;
	
	return cnt;
}


void reversePrint(SLL *ptr)
{
	int nodes, i, j;
	SLL *tmp;
	nodes = countNodes(ptr);

	for (i = 0; i < nodes; i++) {
		tmp = ptr;
		for (j = 0; j < nodes-1-i; j++)
			tmp = tmp->next;
		printf("%d ", tmp->num);
	}
}


int main()
{
	SLL *hptr = 0;
	int num;
	char ch;

	do {
		printf("Enter number in node: ");
		scanf("%d", &num);
		addNode(&hptr, num);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("Nodes printed in ascending order(added): ");
	printList(hptr);
	printf("\nNodes printed in reverse order: ");
	reversePrint(hptr);

	printf("\n");
	return 0;
}
