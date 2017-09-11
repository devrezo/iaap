/* last written on 12/09/2017 00:19:32
owner ise2017001 rajaneesh
@devrezo on twitter
@devrezo on github
editor : atom
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
int maxElementInList (struct node *head) {
        int max = INT_MIN;
        while (head != NULL) {
                if (head->data > max) {
                        max = head->data;
}
                head = head->next;
}
        return max;
}
int main (int argc, char *argv[]) {
        int value;
        int max;
        struct node *head = NULL;
        struct node *tail = NULL;
        char buffer[2048];
        char *p = NULL;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL >|\n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head, &tail, value);
                p = strtok (NULL, "> | NULL \n");
        }

        printList (head);
        max = maxElementInList (head);
        printf ("%d", max);
        destroyList (head);
        head = NULL;
        tail = NULL;
        return 0;
}
