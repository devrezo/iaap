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
        if (!newnode) {
                return NULL;
        }
        return newnode;
}

void insert(int input, struct node **root_ref) {
        struct node *child = NULL;
        struct node *parent = NULL;
        struct node *newnode = NULL;
        
        child = *root_ref;
        newnode = create_node(input);
        if (*root_ref == NULL) {
                *root_ref = newnode;
                return;
        }
        while (child != NULL) {
                parent = child;
                if (input <= child->data) {
                        child = child->left;
                }
                else if (input > child->data){
                        child = child->right;
                }
        }
        if (input <= parent->data) {
                parent->left = newnode;
        }
        else if (input > parent->data) {
                parent->right = newnode;
        }
}

void print_leaves(struct node *root) {
        if (root == NULL) {
                return;
        }
        print_leaves(root->left);
        if (root->left == NULL && root->right == NULL) {
                printf("%d ", root->data);
        }
        print_leaves(root->right);
}

void destroy_tree(struct node *root) {
        if (root == NULL) {
                return;
        }
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
}

int main(int argc, char *argv[]) {
        int n;
        int input;
        struct node *root = NULL;
        
        scanf("%d", &n);
        while (n--) {
                scanf("%d", &input);
                insert(input, &root);
        }
        print_leaves(root);
        destroy_tree(root);

        return 0; 
}
