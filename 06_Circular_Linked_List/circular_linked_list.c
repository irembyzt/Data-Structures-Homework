#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
struct node* addBegin(struct node* head, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    struct node* iter = head;
    while (iter->next != head)
        iter = iter->next;

    iter->next = temp;
    temp->next = head;
    head = temp;

    return head;
}
 
struct node* addEnd(struct node* head, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    if (head == NULL) {
        temp->next = temp;
        return temp;
    }

    struct node* iter = head;
    while (iter->next != head)
        iter = iter->next;

    iter->next = temp;
    temp->next = head;

    return head;
}
 
void printList(struct node* head) {
    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }

    struct node* iter = head;
    printf("Liste: ");
    do {
        printf("%d ", iter->data);
        iter = iter->next;
    } while (iter != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;

    head = addBegin(head, 10);
    head = addBegin(head, 5);
    head = addEnd(head, 20);
    head = addEnd(head, 30);

    printList(head);

    return 0;
}
