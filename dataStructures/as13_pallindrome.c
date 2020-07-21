#include <stdio.h>
#include <stdlib.h>

typedef struct singlell {
	int num;
	struct singlell *next;
} SLL;


void addNode_end(SLL **ptr)
{
	SLL *tmp1, *tmp2;

	tmp1 = (SLL *) malloc(sizeof(SLL));
	printf("Enter number in a node: ");
	scanf("%d", &tmp1->num);

	if (*ptr == 0) {
		tmp1->next = *ptr;
		*ptr = tmp1;
	}
	else {
		tmp2 = *ptr;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
		tmp1->next = 0;
	}
}


void print(SLL *ptr)
{
	while (ptr) {
		printf("%d", ptr->num);
		ptr = ptr->next;
		if (ptr)
			printf(" -- ");
	}
	printf("\n");
}


int pallindrome_check(SLL *p)
{
	int n1 = 0, n2, sum = 0;

	while (p) {
		n1 = n1*10 + p->num;
		p = p->next;
	}

	for (n2 = n1; n1; sum = sum*10 + n1%10, n1 /= 10);
	if (n2 == sum)
		return 1;
	else
		return 0;
}


int main()
{
	SLL *hp = 0;
	char ch;

	do {
		addNode_end(&hp);
		printf("Want to continue adding node(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	print(hp);
	int ret = pallindrome_check(hp);
	if (ret)
		printf("Given linked list is pallindrome...\n");
	else
		printf("Given linked list isn't pallindrome...\n");

	return 0;
}
