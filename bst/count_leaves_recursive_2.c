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

struct node* insert_recursive(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

//method to iteratively insert a node in bst
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

//method to delete the tree recursively
void destroy_tree(struct node *root) {
	if(!root) {
		return;
	}
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

//method to return the number of leaves in the tree
int count_leaves(struct node *root) {
	if (!root) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}

	return count_leaves(root->left) + count_leaves(root->right);
}

//method to return the height of the tree
int maxDepth(struct node* node) 
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);
 
       /* use the larger one */
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}

//inorder traversal of the tree
void inorder (struct node* node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

//driver function to use the methods above
int main(int argc, char *argv[]) {
	int n;
	int input;
	struct node *root = NULL;
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
