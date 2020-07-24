#include <stdio.h>
#include <stdlib.h>

static int nodeCount = 0;

typedef struct singleLL {
	int rn;
	char nm[20];
	float avg;
	struct singleLL *next;
} SLL;


void addNode_middle(SLL **ptr)
{
	SLL *tmp1, *tmp2;

	tmp1 = (SLL *) malloc(sizeof(SLL));
	printf("Enter roll number, first name & average marks of a student: ");
	scanf("%d %s %f", &tmp1->rn, tmp1->nm, &tmp1->avg);

	if (*ptr == 0 || (*ptr)->rn > tmp1->rn) {
		tmp1->next = *ptr;
		*ptr = tmp1;
	}
	else {
		tmp2 = *ptr;
		while (tmp2) {
			if (tmp2->next == 0 || tmp2->next->rn > tmp1->rn) {
				tmp1->next = tmp2->next;
				tmp2->next = tmp1;
				break;
			}
			tmp2 = tmp2->next;
		}
	}
}


void print(SLL *p)
{
	while (p) {
		printf("%d %s %f\n", p->rn, p->nm, p->avg);
		p = p->next;
	}
}


void reverse_data(SLL *p)
{
	SLL *tmp1, *tmp2, *tmp3, var;
	int i, j;

	tmp1 = p;
	for (i = 0; i < nodeCount/2; i++) {
		tmp2 = p;
		for (j = 0; j < nodeCount-i-1; j++)
			tmp2 = tmp2->next;

		var = *tmp1;
		*tmp1 = *tmp2;
		*tmp2 = var;

		tmp3 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp3;

		tmp1 = tmp1->next;
	}
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		addNode_middle(&hp);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
		nodeCount++;
	} while (ch == 'y' || ch == 'Y');

	print(hp);
	reverse_data(hp);
	printf("\nAfter reversing the data.\n\n");
	print(hp);

	return 0;
}
