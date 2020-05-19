#include <stdio.h>
#include <stdlib.h>

typedef struct singleLL
{
	int num;
	struct singleLL *next;
} SLL;


void addAtBegin(SLL **hptr)
{
	int num;
	printf("Enter any number: ");
	scanf("%d", &num);

	SLL *ptr = (SLL *)malloc(sizeof(int));
	ptr->num = num;
	ptr->next = *hptr;
	*hptr = ptr;

	return;
}


int addAtEnd(SLL **hptr)
{
	int num;
	SLL *temp = *hptr;

	printf("Enter number: ");
	scanf("%d", &num);

	SLL *ptr = (SLL *) malloc(sizeof(int));
	ptr->num = num;

	if (*hptr == 0) {
		ptr->next = 0;
		*hptr = ptr;
	}
	else {
		while(temp->next)
			temp = temp->next;
		temp->next = ptr;
		ptr->next = 0;
	}
	return 0;
}


int main()
{
	char ch;
	SLL *hptr = 0;

	do {
		addAtBegin(&hptr);
		printf("Want to continue adding node in linked list(Y/N): ");
		scanf(" %c", &ch);
	} while(ch == 'y' || ch == 'Y');

	printf("Nodes entered in single list are as follows(Add@Begin): ");
	while (hptr) {
		printf("%d ", hptr->num);
		hptr = hptr->next;
	}

	hptr = 0;
	printf("\n\nEnter num to add node at end...\n");
	do {
		addAtEnd(&hptr);
		printf("Want to continue adding node in linked list(Y/N): ");
		scanf(" %c", &ch);
	} while(ch == 'y' || ch == 'Y');


	printf("Nodes entered in single list are as follows(Add@End): ");
	while (hptr) {
		printf("%d ", hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
	return 0;
}
