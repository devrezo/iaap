//author ise2017001
//last written 06/10/2017 07:45:12
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *representative;
	struct node *next;
};

struct tnode {
	int key;
	struct node *value;
	struct tnode *right;
	struct tnode *left;
};

struct node * create_node(int input) {
	struct node *temp = NULL;

	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = input;
	temp->representative = NULL;
	temp->next = NULL;

	return temp;
}

struct tnode * create_tnode(int input, struct node *item) {
	struct tnode *temp = NULL;

	temp = (struct tnode *) malloc(sizeof(struct tnode));
	temp->key = input;
	temp->value = item;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void insert(int input, struct node *item, struct tnode **root_ref) {
	struct tnode *child = NULL;
	struct tnode *parent = NULL;

	child = (*root_ref);
	if (*root_ref == NULL) {
		*root_ref = create_tnode(input, item);
	}
	else {
		while (child != NULL) {
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

void make_set(int input, struct tnode **root_ref) {
	struct node *temp = NULL;

	temp = create_node(input);
	temp->representative = temp;
	insert(input, temp, root_ref);
}

struct node * find_set(struct node *item) {
	return item->representative;
}

struct node * get(int input, struct tnode **root_ref) {
	struct tnode *child = NULL;
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
	return NULL;
}

void print_set(int input, struct tnode **root_ref) {
	struct node *temp = NULL;
	struct node *rep = NULL;
	
	temp = get(input, root_ref);
	rep = find_set(temp);
	if (rep == NULL) {
		printf("{}");
	}
	temp = rep;
	printf("{");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("}\n");
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
	if ((rep1 == NULL) || (rep2 == NULL) || (rep1->data == rep2->data)) {
		return;
	}
	temp = rep1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = rep2;
	temp = rep2;
	while (temp != NULL) {
		temp->representative = rep1;
		temp = temp->next;
	}
}

int main (int argc, char *argv[]) {
	struct tnode *root = NULL;
	int data;
	int n;
	int key1;
	int key2;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &data);
		make_set(data, &root);
	}
	scanf("%d", &key1);
	scanf("%d", &key2);
	
	print_set(key1, &root);
	print_set(key2, &root);
	union_set(key1, key2, &root);
	print_set(key1, &root);
	print_set(key2, &root);

	return 0;
}
