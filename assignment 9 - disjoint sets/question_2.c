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
	struct tnode *left;
	struct tnode *right;
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

struct node * get(int input, struct tnode **root_ref) {
	struct tnode *child = NULL;
	child = *root_ref;

	while (child != NULL) {
		if (input == child->key) {
			return child->value;
		}
		if (input < child->key) {
			child = child->left;
		}
		else if (input  > child->key) {
			child = child->right;
		}
	}

	return NULL;
}

void insert(int input, struct node *item, struct tnode **root_ref) {
	struct tnode *child = NULL;
	struct tnode *parent = NULL;
	if (*root_ref == NULL) {
		*root_ref = create_tnode(input, item);
	}
	else {
		child = *root_ref;
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
	if ((rep1 == rep2) || (rep1 == NULL) || (rep2 == NULL)) {
		return;
	}
	temp = rep1;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = rep2;
	temp = rep2;
	while(temp != NULL) {
		temp->representative = rep1;
		temp = temp->next;
	}
}

void print_set(int input, struct tnode **root_ref) {
	struct node *temp = NULL;
	struct node *rep = NULL;

	temp = get(input, root_ref);
	rep = find_set(temp);
	if (rep == NULL) {
		return;
	}
	temp = rep;
	printf("{");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("}\n");
}

int main(int argc, char *argv[]) {
	struct tnode *root = NULL;
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		make_set(i, &root);
	}
	
	union_set(1, 5, &root);
	print_set(1, &root);
   	union_set(3, 7, &root);
   	print_set(3, &root);
 	union_set(1, 4, &root);
   	print_set(1, &root);
   	union_set(5, 7, &root);
    	print_set(5, &root);
  	union_set(0, 8, &root);
   	print_set(0, &root);
   	union_set(6, 9, &root);
   	print_set(6, &root);
   	union_set(3, 9, &root);
   	print_set(3, &root);
	
	return 0;
}
