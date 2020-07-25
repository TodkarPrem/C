#include <stdio.h>
#include <stdlib.h>

typedef struct binarySearch {
	struct binarySearch *left;
	int num;
	struct binarySearch *right;
} BST;

BST *PARENT;

void addNode(BST **ptr, int n)
{
	if (*ptr == 0) {
		*ptr = (BST *) malloc(sizeof(BST));
		(*ptr)->num = n;
		(*ptr)->left = (*ptr)->right = 0;
		return;
	}
	else if ((*ptr)->num > n)
		addNode(&(*ptr)->left, n);
	else
		addNode(&(*ptr)->right, n);
}

void inorder(BST *ptr)
{
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->num);
		inorder(ptr->right);
	}
}


BST *search(BST *ptr, int n)
{
	if (ptr == 0)
		return 0;
	else if (ptr->num == n)
		return ptr;
	else if (ptr->num > n) {
		PARENT = ptr;
		search(ptr->left, n);
	}
	else {
		PARENT = ptr;
		search(ptr->right, n);
	}
}


void deleteNode(BST **ptr)
{
	BST *q, *r;
	int n;

	printf("\nEnter the number to be deeleted from binary search tree: ");
	scanf(" %d", &n);

	q = search(*ptr, n);
	if (q == 0) {
		printf("Node not found.\n");
		return;
	}

	if (q->left != 0 && q->right != 0) {
		r = q->left;		// r = q->right
		PARENT = q;
		while(r->right) {
			PARENT = r;
			r = r->right;
		}
		q->num = r->num;
		q = r;
	}

	if (q->left != 0 && q->right == 0) {
		if (PARENT->right == q) {
			PARENT->right = q->left;
			free(q);
		}
		else {
			PARENT->left = q->left;
			free(q);
		}
	}

	if (q->left == 0 && q->right != 0) {
		if (PARENT->right == q) {
			PARENT->right = q->right;
			free(q);
		}
		else {
			PARENT->left = q->right;
			free(q);
		}
	}

	if (q->left == 0 && q->right == 0) {
		if (PARENT->left == q) {
			PARENT->left = 0;
			free(q);
		}
		else {
			PARENT->right = 0;
			free(q);
		}
	}
}


int main()
{
	BST *hp = 0;
	char ch;
	int num;

	do {
		printf("Enter any number: ");
		scanf("%d", &num);
		addNode(&hp, num);
		printf("Want to continue(y/n): ");
		scanf(" %c", &ch);
	} while (ch == 'y' || ch == 'Y');

	printf("Printing data in inorder format: ");
	inorder(hp);

	deleteNode(&hp);
	printf("\nPrinting data in inorder format after deleting node: ");
	inorder(hp);

	printf("\n");
	return 0;
}
