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


void enq(struct node *item, struct qnode **front_ref, struct qnode **rear_ref) {
	struct qnode *newqnode = NULL;

	newqnode = create_qnode(item);
	if(*front_ref == NULL) {
		*front_ref = newqnode;
		*rear_ref = newqnode;

		return;
	}
	(*rear_ref)->next = newqnode;
	*rear_ref = newqnode;
	
	return; 
}

void deq(struct qnode **front_ref) {
	struct qnode *temp = NULL;

	if (*front_ref == NULL) {
		return;
	}
	temp = *front_ref;
	*front_ref = (*front_ref)->next;
	free(temp);
	
	return;
}

int is_empty(struct qnode **front_ref) {
	return (*front_ref == NULL) ? 1 : 0;
}

struct node * get_front(struct qnode **front_ref) {
	struct node *temp = NULL;

	if (*front_ref == NULL) {
		return NULL;
	}
	temp = (*front_ref)->tnode;
	return temp;
}

void bfs(struct node *root) {
	struct qnode *front = NULL;
	struct qnode *rear = NULL;
	struct node *current = NULL;

	if (root == NULL) {
		return;
	}
	enq(root, &front, &rear);
	while (!is_empty(&front)) {
		current = get_front(&front);
		printf("%d ", current->data);
		if(current->left != NULL) {
			enq(current->left, &front, &rear);
		}
		if(current->right != NULL) {
			enq(current->right, &front, &rear);
		}
		deq(&front);
	}
	printf("\n");

	return;
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
	struct node *root = NULL;
	int n;
	int input;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &input);
		insert(input, &root);
	}

	bfs(root);

	return 0;
}