#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void partitionLinkedList(struct Node** head, int v) {
    struct Node* lessThanV = NULL;
    struct Node* greaterThanOrEqualV = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data < v) {
            insertAtEnd(&lessThanV, current->data);
        } else {
            insertAtEnd(&greaterThanOrEqualV, current->data);
        }
        current = current->next;
    }
    if (lessThanV != NULL) {
        *head = lessThanV;
        while (lessThanV->next != NULL) {
            lessThanV = lessThanV->next;
        }
        lessThanV->next = greaterThanOrEqualV;
    } else {
        *head = greaterThanOrEqualV;
    }
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, v;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    printf("Enter the value V for partitioning: ");
    scanf("%d", &v);
    partitionLinkedList(&head, v);
    printf("Linked list after partitioning:\n");
    displayList(head);
    return 0;
}
