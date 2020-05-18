#include <stdio.h>
#include <stdlib.h>

struct sll {
	int num;
	struct sll *next;
};

void addAtMiddle(struct sll **hptr)
{
	int num;
	struct sll *ptr, *tmp;

	printf("Enter any num: ");
	scanf("%d", &num);

	ptr = (struct sll *) malloc(sizeof(int));
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
	return;
}


void mergeSLL(struct sll **hptr, struct sll *ptr1, struct sll *ptr2)
{
	int i;

	struct sll *tmp = *hptr = ptr1;
	ptr1 = ptr1->next;
	for (i = 1; ptr1 && ptr2; tmp = tmp->next, i++)
		if (i % 2) {
			tmp->next = ptr2;
			ptr2 = ptr2->next;
		}
		else {
			tmp->next = ptr1;
			ptr1 = ptr1->next;
		}

	if (ptr1 && ptr2 == 0)
		while (ptr1) {
			tmp->next = ptr1;
			ptr1 = ptr1->next;
			tmp = tmp->next;
		}
	else if (ptr1 == 0 && ptr2)
		while (ptr2) {
			tmp->next = ptr2;
			ptr2 = ptr2->next;
			tmp = tmp->next;
		}

	return;
}


int main()
{
	char ch;
	struct sll *hp1 = 0, *hp2 = 0, *hp3 = 0;

	printf("Create first linked list...\n");
	do {
		addAtMiddle(&hp1);
		printf("Want to continue(Y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');


	printf("\nCreate second linked list...\n");
	do {
		addAtMiddle(&hp2);
		printf("Want to continue(Y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	mergeSLL(&hp3, hp1, hp2);
	/*
	printf("\nFirst linked list: ");
	while (hp1) {
		printf("%d ", hp1->num);
		hp1 = hp1->next;
	}
	
	printf("\nSecond linked list: ");
	while (hp2) {
		printf("%d ", hp2->num);
		hp2 = hp2->next;
	}
	*/
	printf("\nMerged linked list: ");
	while (hp3) {
		printf("%d ", hp3->num);
		hp3 = hp3->next;
	}

	printf("\n");
	return 0;
}
