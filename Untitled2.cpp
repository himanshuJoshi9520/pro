#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* createNewList(struct Node* listA, struct Node* listB) {
    struct Node* newList = NULL;
    struct Node* tempA = listA;
    struct Node* tempB = listB;
    while (tempA != NULL && tempB != NULL) {
        append(&newList, tempA->data);
        append(&newList, tempB->data);
        tempA = tempA->next;
        tempB = tempB->next;
    }
    while (tempA != NULL) {
        append(&newList, tempA->data);
        tempA = tempA->next;
    }
    while (tempB != NULL) {
        append(&newList, tempB->data);
        tempB = tempB->next;
    }
    return newList;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* A = NULL;
    append(&A, 1);
    append(&A, 2);
    append(&A, 3);
    struct Node* B = NULL;
    append(&B, 4);
    append(&B, 5);
    append(&B, 6);
    append(&B, 7);
    append(&B, 8);
    append(&B, 9);
    struct Node* S = createNewList(A, B);
    printf("New Linked List S: ");
    displayList(S);
    return 0;
}
