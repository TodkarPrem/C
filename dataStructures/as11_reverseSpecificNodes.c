#include <stdio.h>
#include <stdlib.h>

static int nodeCount = 0;

typedef struct singleLL {
	int rn;
	char nm[20];
	float avg;
	struct singleLL *next;
} SLL;


void addNode_Middle(SLL **ptr)
{
	SLL *tmp1, *tmp2;

	tmp1 = (SLL *) malloc(sizeof(SLL));
	printf("Enter roll number, first name & avg marks of student: ");
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
        int i, j, nu;

	printf("Enter number of nodes to reverse: ");
	scanf(" %d", &nu);
	if (nu > nodeCount/2) {
		printf("Nodes to reverse should be less than half of total nodes.\n");
		exit(0);
	}

        tmp1 = p;
        for (i = 0; i < nu; i++) {
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
		addNode_Middle(&hp);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
		nodeCount++;
	} while (ch ==  'y' || ch == 'Y');

	print(hp);
	printf("\nAfter reversing specific nodes.\n");
	reverse_data(hp);
	print(hp);

	return 0;
}
