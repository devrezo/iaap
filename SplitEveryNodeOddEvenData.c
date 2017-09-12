#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
        int data;
        struct node *next;
};
struct node *createNode (int value) {
        struct node *newNode = (struct node *) malloc (sizeof (struct node));
        newNode -> data = value;
        newNode -> next = NULL;
        return newNode;
}
void insertNode (struct node **head_ref, struct node **tail_ref, int value) {
        struct node *newNode = createNode (value);
        if (*head_ref == NULL) {
                *head_ref = newNode;
                *tail_ref = newNode;
}
        else {
                (*tail_ref) -> next = newNode;
                *tail_ref = newNode;
}
}
void  printList (struct node *head) {
        while (head != NULL) {
                printf ("%d -> ", head->data);
                head = head->next;
}
        printf ("NULL\n");
}
void destroyList (struct node *head) {
        struct node *nextNode = head;
        while (head != NULL) {
                nextNode = head -> next;
                free (head);
                head = nextNode;
}
        printf("Destroyed it\n" );
}
void splitEveryNodeOnOddEvenData (struct node **head_ref) {
        struct node *currentNode = NULL;
        struct node *nextNode = NULL;
        struct node *newNode = NULL;
        int element;
        currentNode = (*head_ref);
        if (currentNode == NULL) {
                return;
}
        while (currentNode != NULL) {
                nextNode = currentNode->next;
                element = currentNode->data;
                if (element % 2 == 0) {
                        newNode = createNode (element/2);
                        currentNode->data /= 2;
}
                else {
                        newNode = createNode (element - element/2);
                        currentNode->data /= 2;
}
        currentNode->next = newNode;
        newNode->next = nextNode;
        currentNode = nextNode;
}
}
int main (int argc, char *argv[]) {
        int value;
        struct node *head = NULL;
        struct node *tail = NULL;
        char buffer[2048];
        char *p = NULL;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL > | \n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head, &tail, value);
                p = strtok (NULL, "NULL null | > \n");
}
        printList (head);
        splitEveryNodeOnOddEvenData (&head);
        printList (head);
        destroyList (head);
        head = NULL;
        tail = NULL;
        return 0;
}
