#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;


void insert(int data) {
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->data = data;
	link->next = NULL;

	// If head is empty, create new list
	if(head==NULL) {
		head = link;
		head->next = link;
		return;
	}

	current = head;

	// move to the end of the list
	while(current->next != head)
		current = current->next;

	// Insert link at the end of the list
	current->next = link;

	// Link the last node back to head
	link->next = head;
}


void remove_data(int data) {
	int pos = 0;

	if(head==NULL) {
		printf("Linked List not initialized");
		return;
	} 

	if(head->data == data) {
		if(head->next != head) {
			current = head;
			while(current->next!=head) {
				current = current->next;
			}

			current->next = head->next;
			head = head->next;
			return;
		} else {
			head = NULL;
			printf("List is empty\n");
			exit(0);
		}

	} else if(head->data != data && head->next == NULL) {
		printf("%d not found in the list\n", data);
		return;
	}

	current = head;

	while(current->next != head && current->data != data) {
		prev = current;
		current = current->next;
	}        

	if(current->data == data) {
		prev->next = prev->next->next;
		free(current);
	} else
		printf("%d not found in the list.", data);
}


void printList() {
	struct node *ptr = head;

	printf("\n[head] =>");

	while(ptr->next != head) {        
		printf(" %d =>",ptr->data);
		ptr = ptr->next;
	}

	printf(" %d =>",ptr->data);
	printf(" [head]\n");
}


int main() {
	int num;
	char ch;

	do {
		printf("Enter number to insert in node: ");
		scanf("%d", &num);
		insert(num);

		printf("Want to continue adding node: ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nOriginal List -");
	printList();

	do {
		printf("Enter number to delete from node: ");
		scanf("%d", &num);
		remove_data(num);

		printf("Want to continue deleting node: ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nList after removal -");
	printList();

	return 0;
}
