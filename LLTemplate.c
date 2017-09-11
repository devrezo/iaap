#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node *next;
};
struct node *createNode(int value) {
        struct node *newNode = (struct node *) malloc (sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
}
struct node *createLL (int size) {
        int value;
        struct node *endNode = NULL, *head = NULL, *currentNode = NULL;
        if (size == 0) return NULL;
        if (size>=1) {
                size--;
                scanf ("%d",&value);
                head = createNode(value);
                if (size == 0) return head;
                currentNode = head;
                while(size!=0) {
                        scanf ("%d", &value);
                        endNode = createNode(value);
                        currentNode->next = endNode;
                        currentNode = currentNode->next;
                        size--;
                }
        }
        return head;
}
void printList (struct node *head) {
        while (head != NULL) {
                printf ("%d -> ", head->data);
                head = head->next;
        }
        printf ("NULL\n");
}

void removeLL (struct node *head) {
        struct node *current = head, *trackNext;
        while (current != NULL) {
                trackNext = current -> next;
                free (current);
                current = trackNext;
        }
}
int main (void) {
        int size;
        struct node *head = NULL;
        scanf ("%d", &size);
        head = createLL(size);
        printList(head);
        removeLL (head);
        head = NULL;
        return 0;
}
