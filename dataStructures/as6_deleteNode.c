#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct singleLL {
	int rn;
	char nm[20];
	float avg;
	struct singleLL *next;
} SLL;


void add_middle(SLL **ptr)
{
	SLL *tmp, *tmp1;

	tmp = (SLL *) malloc(sizeof(SLL));
	printf("Enter rn, first name & avg marks of student: ");
	scanf("%d %s %f", &tmp->rn, tmp->nm, &tmp->avg);

	if (*ptr == 0 || (*ptr)->rn > tmp->rn) {
		tmp->next = *ptr;
		*ptr = tmp;
	}
	else {
		tmp1 = *ptr;
		while (tmp1) {
			if (tmp1->next == 0 || tmp1->next->rn > tmp->rn) {
				tmp->next = tmp1->next;
				tmp1->next = tmp;
				break;
			}
			tmp = tmp->next;
		}
	}
}


void print(SLL *ptr)
{
	while (ptr) {
		printf("%d %s %f\n", ptr->rn, ptr->nm, ptr->avg);
		ptr = ptr->next;
	}
}


void deleteNode(SLL **ptr)
{
	SLL *tmp = *ptr, *tmp1;
	char ch, nm[20];
	int rn;
	float avg;

up:	printf("\n1. Delete Node using roll num.");
	printf("\n2. Delete Node using first name.");
	printf("\n3. Delete Node using avg marks.");
	printf("\n\nEnter choice(1/2/3): ");
	scanf(" %c", &ch);

	switch (ch) {
		case '1':
			printf("Enter roll number which needs to be deleted: ");
			scanf("%d", &rn);
			while (tmp) {
				if (tmp->rn == rn) {
					if (tmp == *ptr) {
						*ptr = tmp->next;
						free(tmp);
						return;
					}
					else {
						tmp1->next = tmp->next;
						free(tmp);
						return;
					}
				}
				tmp1 = tmp;
				tmp = tmp->next;
			}
			printf("Entered roll number not found.\n");
			break;
		case '2':
			printf("Enter first name which needs to be deleted: ");
			scanf("%s", nm);
			while (tmp) {
				if (strcmp(tmp->nm, nm) == 0) {
					if (tmp == *ptr) {
						*ptr = tmp->next;
						free(tmp);
						return;
					}
					else {
						tmp1->next = tmp->next;
						free(tmp);
						return;
					}
				}
				tmp1 = tmp;
				tmp = tmp->next;
			}
			printf("Entered name not found.\n");
			break;

		case '3':
			printf("Enter avg marks which needs to be deleted: ");
			scanf("%f", &avg);
			while (tmp) {
				if (tmp->avg == avg) {
					if (tmp == *ptr) {
						*ptr = tmp->next;
						free(tmp);
						return;
					}
					else {
						tmp1->next = tmp->next;
						free(tmp);
						return;
					}
				}
				tmp1 = tmp;
				tmp = tmp->next;
			}
			printf("Entered marks not found.\n");
			break;
		default:
			printf("Please enter valid entry.\n");
			goto up;
	}
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		add_middle(&hp);
		printf("want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("Entered student entries:\n");
	print(hp);

	deleteNode(&hp);
	printf("Student entries after deleting node:\n");
	print(hp);

	return 0;
}
