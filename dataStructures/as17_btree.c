#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	struct tree *left;
	int num;
	struct tree *right;
}BTree;

void addNode(BTree **, int);
void inorder(BTree *ptr);
void preorder(BTree *ptr);
void postorder(BTree *ptr);

int main()
{
	int num;
	char ch;
	BTree *hptr = 0;

	do {
		printf("Enter number in node: ");
		scanf("%d", &num);
		addNode(&hptr, num);
		printf("Want to continue adding nodes(Y/N): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("\nInorder printing: ");
	inorder(hptr);
	printf("\nPre-order printing: ");
	preorder(hptr);
	printf("\nPost-order printing: ");
	postorder(hptr);

	printf("\n");
	return 0;
}


void addNode(BTree **ptr, int n)
{
	if (*ptr == 0) {
		*ptr = (BTree *) malloc(sizeof(BTree));
		(*ptr)->num = n;
		(*ptr)->left = (*ptr)->right = 0;
		return;
	}
	else if ((*ptr)->num > n)
		addNode(&(*ptr)->left, n);
	else
		addNode(&(*ptr)->right, n);
}

void inorder(BTree *ptr)
{
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->num);
		inorder(ptr->right);
	}
}

void preorder(BTree *ptr)
{
	if (ptr) {
		printf("%d ", ptr->num);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(BTree *ptr)
{
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->num);
	}
}
