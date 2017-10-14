
#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct node * create_node(int input) {
	struct node *newnode = NULL;

	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->data = input;
	newnode->right = NULL;

	return newnode;
}

struct node * create_cbt(int index, int n, int *arr, struct node *root) {
	if (index > n-1) {
		return NULL;
	}
	if (index <= n-1) {
		root = create_node(arr[index]);
		root->left = create_cbt(2 * index + 1, n, arr, root);
		root->right = create_cbt(2 * index + 2, n, arr, root);
	}

	return root;
}

void inorder(struct node *root) {
	if (root == NULL) {
		return;
	}
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
}

int main(int argc, char *argv[]) {
	int n;
	struct node *root = NULL;
	int i;
	int *arr = NULL;

	scanf("%d", &n);
	arr = (int *) malloc(sizeof(int) * n);
	i = 0;
	while (i <= n-1) {
		scanf("%d", &arr[i]);
		i++;
	}
	
	root = create_cbt(0, n, arr, root);
	printf ("created cbt\n");
	inorder(root);

	return 0;
}
