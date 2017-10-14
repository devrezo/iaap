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

void insert(int input, struct node **root_ref) {
	struct node *child = NULL;
	struct node *parent = NULL;
	struct node *newnode = NULL;

	newnode = create_node(input);
	child = (*root_ref);
	if (*root_ref== NULL) {
		*root_ref = newnode;
		return;
	}
	while (child != NULL) {
		parent = child;
		if (input <= child->data) {
			child = child->left;
		}
		else {
			child = child->right;
		}
	}
	if (input <= parent->data) {
		parent->left = newnode;
	}
	else {
		parent->right = newnode;
	}
}

void destroy_tree(struct node *root) {
	if(!root) {
		return;
	}
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

void count_leaves(struct node *root, int *counter) {
	if (!root) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		*counter = *counter + 1;
		return;
	}
	count_leaves(root->left, counter);
	count_leaves(root->right, counter);
}

int main(int argc, char *argv[]) {
	int n;
	int input;
	struct node *root = NULL;
	struct qnode *front = NULL;
	struct qnode *rear = NULL;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &input);
		insert(input, &root);
	}
	n = 0;
	count_leaves(root, &n);
	printf("%d", n);
	destroy_tree(root);
	
	return 0;
}