#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	int rn;
	char name[20];
	float avg;
	struct student *next;
} SLL;

void addNodeMiddle(SLL **hptr)
{
	SLL *tmp, *tmp1;

	tmp = (SLL *) malloc(sizeof(SLL));
	printf("Enter roll number, name & avg marks of student: ");
	scanf("%d %s %f", &tmp->rn, tmp->name, &tmp->avg);

	if (*hptr == 0 || (*hptr)->rn > tmp->rn) {
		tmp->next = *hptr;
		*hptr = tmp;
	}
	else {
		tmp1 = *hptr;
		while (tmp1) {
			if (tmp1->next == 0 || tmp1->next->rn > tmp->rn) {
				tmp->next = tmp1->next;
				tmp1->next = tmp;
				break;
			}
			tmp1 = tmp1->next;
		}
	}
	return;
}


void print(SLL *hp)
{
	while (hp) {
		printf("%d %s %f\n", hp->rn, hp->name, hp->avg);
		hp = hp->next;
	}
}


void saveFile(SLL *hp)
{
	FILE *fp = fopen("StudentDatabase.txt", "w");
	while (hp) {
		fprintf(fp, "%d %s %f\n", hp->rn, hp->name, hp->avg);
		hp = hp->next;
	}
}


void readFile(SLL **hp)
{
	SLL var, *ptr, *tmp;
	FILE *fp;
	fp = fopen("StudentDatabase.txt", "r");
	if (fp == 0) {
		printf("File not found...\n");
		return;
	}

	while (fscanf(fp, "%d %s %f", &var.rn, var.name, &var.avg) != EOF) {
		ptr = (SLL *) malloc(sizeof(SLL));
		ptr->rn = var.rn;
		strcpy(ptr->name, var.name);
		ptr->avg = var.avg;

		if (*hp == 0) {
			ptr->next = *hp;
			*hp = ptr;
			tmp = ptr;
		}
		else {
			ptr->next = tmp->next;
			tmp->next = ptr;
			tmp = ptr;
		}
	}
}


int main()
{
	SLL *hp1 = 0;
	char ch;

	printf("\n*** Data Read From Databse***\n");
	readFile(&hp1);
	print(hp1);

	do {
		addNodeMiddle(&hp1);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	print(hp1);
	saveFile(hp1);

	return 0;
}
