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

int count_leaves(struct node *root) {
	if (!root) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	return count_leaves(root->left) + count_leaves(root->right);
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

	n = count_leaves(root);
	printf("%d", n);
	destroy_tree(root);

	return 0;
}
