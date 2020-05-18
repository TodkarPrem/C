#include <stdio.h>
#include <stdlib.h>

struct sll{
	int num;
	struct sll *next;
};

void addATMiddle(struct sll **hptr)
{
	int num;
	struct sll *ptr, *tempPtr1;

	printf("Enter any num: ");
	scanf("%d", &num);

	ptr = (struct sll *) malloc(sizeof(int));
	ptr->num = num;

	if (*hptr == 0 || (*hptr)->num > num) {
		ptr->next = *hptr;
		*hptr = ptr;
	}
	else {
		tempPtr1 = *hptr;
		while (tempPtr1) {
			if (tempPtr1->next == 0 || tempPtr1->next->num > num) {
				ptr->next = tempPtr1->next;
				tempPtr1->next = ptr;
				break;
			}
			tempPtr1 = tempPtr1->next;
		}
	}
	return;
}


int main()
{
	char ch;
	struct sll *hptr = 0;

	do {
		addATMiddle(&hptr);
		printf("Want to continue adding numbers(Y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nEntered numbers in ascending order as follows: ");
	while (hptr) {
		printf("%d ", hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
	return 0;
}

