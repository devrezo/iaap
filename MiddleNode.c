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
        printf("Killed off all her feelings\n" );
}
struct node *middleNode (struct node *head) {
        struct node *slowPtr = NULL;
        struct node *fastPtr = NULL;
        slowPtr = head;
        fastPtr = head;
        if (head == NULL || head->next == NULL) {
                return head;
        }
        while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL) {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
        }
        return slowPtr;
}
int main (int argc, char *argv[]) {
        int value;
        struct node *head = NULL;
        struct node *tail = NULL;
        struct node *midNode = NULL;
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
        midNode = middleNode (head);
        if (midNode == NULL) {
                printf ("NULL\n");
        }
        else {
                printf ("%d\n", midNode->data);
        }
        destroyList (head);
        head = NULL;
        tail = NULL;
        return 0;
}
