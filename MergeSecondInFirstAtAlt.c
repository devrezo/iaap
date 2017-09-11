/* last written on 12/09/2017 00:19:32
owner ise2017001 rajaneesh
@devrezo on twitter
@devrezo on github
editor : atom
*/
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
void mergeSecondInFirstAtAlt (struct node *head1, struct node **head2_ref) {
        struct node *current1 = NULL;
        struct node *current2 = NULL;
        struct node *next1 = NULL;
        struct node *next2 = NULL;
        current1 = head1;
        current2 = (*head2_ref);
        while (current1 != NULL && current2 != NULL) {
                next1 = current1->next;
                next2 = current2->next;
                current1->next = current2;
                current2->next = next1;
                current1 = next1;
                current2 = next2;
}
        *head2_ref = current2;
}
int main (int argc, char *argv[]) {
        int value;
        struct node *head1 = NULL;
        struct node *tail1 = NULL;
        struct node *head2 = NULL;
        struct node *tail2 = NULL;
        char buffer[2048];
        char *p = NULL;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL >|\n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head1, &tail1, value);
                p = strtok (NULL, "> | NULL \n");
        }

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL >|\n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head2, &tail2, value);
                p = strtok (NULL, "> | NULL \n");
        }
        printList (head1);
        printList (head2);
        mergeSecondInFirstAtAlt (head1, &head2);
        printList (head1);
        printList (head2);
        destroyList (head1);
        head1 = NULL;
        tail1 = NULL;
        head2 = NULL;
        tail2 = NULL;
        return 0;
}
