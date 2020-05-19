#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	struct tree *left;
	int num;
	struct tree *right;
}BTree;

void addNode(BTree **hptr, int num)
{
	if (*hptr == 0) {
		(*hptr) = (BTree *) malloc(sizeof(BTree));
		(*hptr)->num = num;
		(*hptr)->left = (*hptr)->right = 0;
		return;
	}
	else if ((*hptr)->num > num)
		addNode(&(*hptr)->left, num);
	else
		addNode(&(*hptr)->right, num);
}

void inorder(BTree *p)
{
	if (p) {
		inorder(p->left);
		printf("%d ", p->num);
		inorder(p->right);
	}
}

BTree *search(BTree *ptr, int n)
{
	if (!ptr)
		return 0;
	else if (ptr->num == n)
		return ptr;
	else if (ptr->num > n)
		search(ptr->left, n);
	else
		search(ptr->right, n);
}

int main()
{
	BTree *hptr = 0, *node = 0;
	int num, num2;
	char ch;

	do {
		printf("Enter number in node: ");
		scanf("%d", &num);
		addNode(&hptr, num);
		printf("Want to continue(Y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nInorder printing of nodes: ");
	inorder(hptr);

	printf("\nEnter number to search in Btree: ");
	scanf("%d", &num2);
	
	node = search(hptr, num2);
	if (node)
		printf("Found number in Btree nodes. :)\n");
	else
		printf("Number not present in Btree nodes. :(\n");

	return 0;
}
