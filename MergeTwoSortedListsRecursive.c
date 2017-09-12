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
struct node *mergeTwoSortedRecursive (struct node *head1, struct node *head2) {
        if (head1 == NULL) {
                return head2;
        }
        if (head2 == NULL) {
                return head1;
        }
        if (head1->data < head2->data) {
                head1->next = mergeTwoSortedRecursive (head1->next, head2);
                return head1;
        }
        else {
                head2->next = mergeTwoSortedRecursive (head1, head2->next);
                return head2;
        }
}
int main (int argc, char *argv[]) {
        int value;
        struct node *head1 = NULL;
        struct node *tail1 = NULL;
        struct node *head2 = NULL;
        struct node *tail2 = NULL;
        struct node *resultHead = NULL;
        char buffer[2048];
        char *p = NULL;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL > | \n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head1, &tail1, value);
                p = strtok (NULL, "NULL null | > \n");
}
        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL > | \n");
        while (p != NULL) {
        sscanf (p, "%d", &value);
        insertNode (&head2, &tail2, value);
        p = strtok (NULL, "NULL null | > \n");
}
        printList (head1);
        printList (head2);
        resultHead = mergeTwoSortedRecursive (head1, head2);
        printList (resultHead);
        destroyList (resultHead);
        head1 = NULL;
        tail1 = NULL;
        head2 = NULL;
        tail2 = NULL;
        return 0;
}
