/* last written on 13/08/2017 13:32:14
owner ise2017001
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
        char *data;
        struct node *next;
};
struct node *createNode (char *str) {
        struct node *newNode = (struct node *) malloc (sizeof (struct node));
        newNode -> data = str;
        newNode -> next = NULL;
        return newNode;
}
void insertNode (struct node **head_ref, struct node **tail_ref, char *str) {
        struct node *newNode = createNode (str);
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
                printf ("%s -> ", head->data);
                head = head->next;
}
        printf (" NULL\n");
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
int main (int argc, char *argv[]) {
        char *buffer = (char *) malloc (2048);
        char *str = NULL;
        struct node *head = NULL;
        struct node *tail = NULL;

        fgets (buffer, 2048, stdin);
        str = strtok (buffer, " ");
        while (str != NULL) {
                insertNode (&head, &tail, str);
                str = strtok (NULL, " \n");
        }
        printList (head);
        destroyList (head);
        return 0;
}
