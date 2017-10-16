#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct snode {
	struct node *tnode;
	struct snode *next;
};

struct node * create_node(input) {
	struct node *newnode = NULL;

	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->data = input;
	newnode->right = NULL;

	return newnode;
}

struct snode * create_snode(struct node *item) {
	struct snode *newsnode = NULL;

	newsnode = (struct snode *) malloc(sizeof(struct snode));
	newsnode->tnode = item;
	newsnode->next = NULL;

	return newsnode;
}

void push(struct node *item, struct snode **top_ref) {
	struct snode *newsnode = NULL;

	newsnode = create_snode(item);
	if(*top_ref == NULL) {
		*top_ref = newsnode;
		return;
	}
	newsnode->next = *top_ref;
	*top_ref = newsnode;
 
 	return;
}

struct node * get_top(struct snode **top_ref){
	if (*top_ref == NULL) {
		return NULL;
	}
	return (*top_ref)->tnode;
}

struct node * pop(struct snode **top_ref) {
	struct snode *temp = NULL;
	struct node *top_tnode = NULL;

	if (*top_ref == NULL) {
		return NULL;
	}
	temp = *top_ref;
	top_tnode = (*top_ref)->tnode;
	*top_ref = (*top_ref)->next;
	free(temp);

	return top_tnode;
	/*we can get the node from here 
	declare a struct node *top_tnode
	and before free(temp)
	use top_tnode = temp->tnode;
	and return top_tnode
	this is just a pointer to 
	a bst node anyhow.. just an address
	value.. we are not 'freeing'
	the tree node's memory anywhere*/
}

int is_empty(struct snode *top) {
	if (top == NULL) {
		return 1;
	}
	return 0;
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
	if(root == NULL) {
		return;
	}
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

void inorder_iterative(struct node *root) {
	struct node *current = NULL;
	struct snode *top = NULL;
	int done;

	done = 0;
	current = root;
	while (!done) {
		if(current != NULL) {
			push(current, &top);
			current = current->left;
		}
		else {
			if (!is_empty(top)) {
				current = pop(&top);
				printf("%d ", current->data);
				current = current->right;
			}
			else {
				done = 1;
				/*done when the stack is empty and
				all the roots are processed
				*/
			}
		}
	}
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
	inorder_iterative(root);
	destroy_tree(root);

	root = NULL;
	return 0;
}