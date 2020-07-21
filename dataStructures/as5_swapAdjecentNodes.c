#include <stdio.h>
#include <stdlib.h>

int node_count = 0;

typedef struct singleLL {
	char ch;
	struct singleLL *next;
} SLL;


void addAtEnd(SLL **ptr)
{
	SLL *temp1, *temp2;

	temp1 = (SLL *) malloc(sizeof(SLL));
	printf("Enter char to store in Linked list: ");
	scanf(" %c", &temp1->ch);

	if (*ptr == 0) {
		temp1->next = *ptr;
		*ptr = temp1;
	}
	else {
		temp2 = *ptr;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp1;
		temp1->next = 0;
	}
}


void swap(SLL *ptr)
{
	int n, i;
	char ch;
	SLL *tmp1;

	tmp1 = ptr;
	for (i = 0; i < node_count / 2; i++) {
		ch = tmp1->ch;
		tmp1->ch = tmp1->next->ch;
		tmp1->next->ch = ch;

		tmp1 = tmp1->next->next;
	}
}


void print(SLL *ptr)
{
	while (ptr) {
		printf("%c", ptr->ch);
		ptr = ptr->next;
		if (ptr)
			printf(" -- ");
	}
	printf("\n");
}

int main()
{
	SLL *hp = 0;
	char choice;

	do {
		addAtEnd(&hp);
		printf("Want to continue(y/n) : ");
		scanf(" %c", &choice);
		node_count++;
	} while (choice == 'y' || choice == 'Y');

	printf("Before Swap: ");
	print(hp);
	
	swap(hp);
	printf("After Swap: ");
	print(hp);

	return 0;
}
