#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLL {
	struct doubleLL *prev;
	int num;
	struct doubleLL *next;
} DLL;

void add_middle(DLL **ptr)
{
	DLL *tmp1, *tmp2;

	tmp1 = malloc(sizeof(DLL));
	printf("Enter any num: ");
	scanf("%d", &tmp1->num);

	tmp1->next = tmp1->prev = 0;
	if (*ptr == 0 || (*ptr)->num > tmp1->num) {
		tmp1->next = *ptr;
		if (*ptr != 0)
			(*ptr)->prev = tmp1;
		*ptr = tmp1;
	}
	else {
		tmp2 = *ptr;
		while (tmp2) {
			if (tmp2->next == 0 || tmp2->next->num > tmp1->num) {
				tmp1->next = tmp2->next;
				if (tmp2->next != 0)
					tmp2->next->prev = tmp1;
				tmp2->next = tmp1;
				break;
			}
			tmp2 = tmp2->next;
		}
	}
}


void delete_node(DLL **ptr)
{
	DLL *tmp;
	int num;

	printf("Enter any number you want to delete from dll: ");
	scanf("%d", &num);

	tmp = *ptr;
	while (tmp) {
		if (tmp->num == num) {
			if (tmp == *ptr) {
				*ptr = tmp->next;
				tmp->next->prev = 0;
				free(tmp);
				return;
			}
			else if (tmp->next == 0) {
				tmp->prev->next = 0;
				free(tmp);
				return;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
				return;
			}
		}
		tmp = tmp->next;
	}
	printf("Number not found in DLL.\n");
}


void print(DLL *p)
{
	while (p) {
		printf("%d", p->num);
		p = p->next;
		if (p)
			printf(" -- ");
	}
	printf("\n");
}


int main()
{
	DLL *hp = 0;
	char ch;

	do {
		add_middle(&hp);
		printf("want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	print(hp);
	delete_node(&hp);
	printf("Nodes after deleting number: ");
	print(hp);

	return 0;
}	
