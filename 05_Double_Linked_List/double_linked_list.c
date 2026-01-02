#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
 
struct node* addBegin(struct node* head, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;

    head = temp;
    return head;
}
 
struct node* addEnd(struct node* head, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        return temp;
    }

    struct node* iter = head;
    while (iter->next != NULL)
        iter = iter->next;

    iter->next = temp;
    temp->prev = iter;

    return head;
}
 
void printList(struct node* head) {
    struct node* iter = head;
    printf("Liste: ");
    while (iter != NULL) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}
 
struct node* deleteNode(struct node* head, int key) {
    struct node* iter = head;

    while (iter != NULL && iter->data != key)
        iter = iter->next;

    if (iter == NULL)
        return head;

    if (iter->prev != NULL)
        iter->prev->next = iter->next;
    else
        head = iter->next;

    if (iter->next != NULL)
        iter->next->prev = iter->prev;

    free(iter);
    return head;
}

int main() {
    struct node* head = NULL;

    head = addBegin(head, 10);
    head = addBegin(head, 5);
    head = addEnd(head, 20);
    head = addEnd(head, 30);

    printList(head);

    head = deleteNode(head, 20);
    printList(head);

    return 0;
}
