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
struct node *reverseByKNodes (struct node *head, int k) {
        struct node *currentNode = NULL;
        struct node *kthNode = NULL;
        int i;
        i = 1;
        currentNode = head;
        if (currentNode == NULL || currentNode->next == NULL) {
                return head;
        }
        for (; currentNode != NULL && i < k; i++) {
                currentNode = currentNode->next;
        }
        if (currentNode == NULL) {
                return head;
        }
        kthNode = currentNode;
        while (currentNode->next != NULL) {
                currentNode = currentNode->next;
        }
        currentNode->next = head;
        head = kthNode->next;
        kthNode->next = NULL;
        return head;
}
int main (int argc, char *argv[]) {
        struct node *head = NULL;
        struct node *tail = NULL;
        char buffer[2048];
        char *p = NULL;
        int k;
        int value;

        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "abcdefghijklmnopqrstuvwxyz=\nABCDEFGIJKLMNOPQRSTUVWXYZ");
        sscanf (p, "%d", &k);
        fgets (buffer, 2048, stdin);
        p = strtok (buffer, "NULL > | \n");
        while (p != NULL) {
                sscanf (p, "%d", &value);
                insertNode (&head, &tail, value);
                p = strtok (NULL, "NULL null | > \n");
}
        printList (head);
        head = reverseByKNodes (head, k);
        printList (head);
        destroyList (head);
        head = NULL;
        tail = NULL;
        return 0;
}
