#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct qnode {
	struct node *tnode;
	struct qnode *next;
};

struct node * create_node(int input) {
	struct node *newnode = NULL;

	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->data = input;
	newnode->right = NULL;

	return newnode;
}

struct qnode * create_qnode(struct node *item) {
	struct qnode *newqnode = NULL;

	newqnode = (struct qnode *) malloc(sizeof(struct qnode));
	newqnode->tnode = item;
	newqnode->next = NULL;

	return newqnode;
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

struct destroy_tree(struct node *root) {
	if(!root) {
		return;
	}
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

void enq(struct node *item, struct qnode **front_ref, struct qnode **rear_ref) {
	if (*front_ref == NULL) {
		*front_ref = create_qnode(item);
		*rear_ref = *front_ref;
	}
	else {
		(*rear_ref)->next = create_qnode(item);
		*rear_ref = (*rear_ref)->next;
	}
}

struct qnode * get_front(struct qnode **front_ref) {
	if (*front_ref == NULL) {
		return NULL;
	}
	return *front_ref;
}

void deq(struct qnode **front_ref) {
	struct qnode *temp = NULL;
	if (*front_ref == NULL) {
		return;
	}
	temp = *front_ref;
	*front_ref = (*front_ref)->next;
	free(temp);
}

int is_qempty(struct qnode *front) {
	return (front == NULL) ? 1 : 0;
}

void destroy_q(struct node *front) {
	struct node *temp = NULL;

	while(front) {
		temp = front;
		front = front->next;
		free(temp);
	}
}

int main(int argc, char *argv[]) {
	int n;
	int input;
	struct node *root = NULL;

	return 0;
}
