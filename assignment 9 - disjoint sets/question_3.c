#include <stdio.h>
#include <stdlib.h>

struct  node {
	int data;
	int rank;
	struct node *representative;
};

struct tnode {
	int key;
	struct node *value;
	struct tnode *left;
	struct tnode *right;
};

void insert(int input, struct node *item, struct tnode **root_ref);
void union_set(int data1, int data2, struct tnode **root_ref);

struct node * create_node (int input) {
	struct node *temp = NULL;
	
	temp = (struct node *) malloc(sizeof(struct node));
	temp->rank = 0;
	temp->data = input;
	temp->representative = NULL;

	return temp;
}

struct tnode *create_tnode(int input, struct node *item) {
	struct tnode *temp = NULL;

	temp = (struct tnode *) malloc(sizeof(struct tnode));
	temp->key = input;
	temp->value = item;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node * get(int input, struct tnode **root_ref) {
	struct tnode *child = NULL;
	if (*root_ref = NULL) {
		return NULL;
	}
	child = (*root_ref);
	while (child != NULL) {
		if (input == child->key) {
			return child->value;
		}
		if (input < child->key) {
			child = child->left;
		}
		else if (input > child->key) {
			child = child->right;
		}
	}
}

void make_set(int input, struct tnode **root_ref) {
	struct node *temp = NULL;

	temp = create_node(input);
	temp->representative = temp;
	insert(input, temp, root_ref);
}

void insert(int input, struct node *item, struct tnode **root_ref) {
	struct tnode *child = NULL;
	struct tnode *parent = NULL;

	child = *root_ref;
	if (*root_ref == NULL) {
		*root_ref = create_tnode(input, item);

		return;
	}
	else {
		while (child != NULL){
			parent = child;
			if (input <= child->key) {
				child = child->left;
			}
			else if (input > child->key) {
				child = child->right;
			}
		}
		if (input <= parent->key) {
			parent->left = create_tnode(input, item);
		}
		else if (input > parent->key) {
			parent->right = create_tnode(input, item);
		}
	}
}

struct node * find_set(struct node *item) {
	struct node *temp = NULL;
	temp = item->representative;
	if (item = temp) {
		return item;
	}
	return find_set(item->representative);
}

int find_set_using_data(int input, struct tnode **root_ref) {
	struct node *n = NULL;
	struct node *rep = NULL;
	int element;

	n = get(input, root_ref);
	rep = find_set(n);
	element = rep->data;
	return element;
}

void union_set(int data1, int data2, struct tnode **root_ref) {
	struct node *n1 = NULL;
	struct node *n2 = NULL;
	struct node *rep1 = NULL;
	struct node *rep2 = NULL;
	struct node *temp = NULL;

	n1 = get(data1, root_ref);
	n2 = get(data2, root_ref);
	rep1 = find_set(n1);
	rep2 = find_set(n2);
	if ((rep1 == NULL) || (rep2 == NULL) || (rep1 == rep2)) {
		return;
	}
	if (rep1->rank >= rep2->rank) {
		rep2->representative = rep1;
		if (rep1->rank == rep2->rank) {
			rep1->rank = rep1->rank + 1;
		}
	}
	else {
		rep1->representative = rep2;
	}
}

int main(int argc, char *argv[]) {
	struct tnode *root = NULL;
	struct node *temp = NULL;
	struct node *rep = NULL;
	int i;

	for (i = 0; i <= 9; i++) {
		make_set(i, &root);
	}
	union_set(1, 5, &root);
	union_set(3, 7, &root);
	union_set(1, 4, &root);
	union_set(5, 7, &root);
	union_set(0, 8, &root);
	union_set(6, 9, &root);
	union_set(3, 9, &root);

	printf ("\nvertex\trepresentative\tdisjoint set ");
	for (i = 0; i <= 9; i++) {
		temp = get(i, &root);
		rep = temp->representative;
		printf ("%d\t%d\t%d", i, rep->data, find_set_using_data(i, &root));
	}

	return 0;
}
