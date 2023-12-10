
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

struct Node* subtractLinkedLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current = NULL;
    int borrow = 0;

    while (list1 != NULL || list2 != NULL) {
        int x = (list1 != NULL) ? list1->data : 0;
        int y = (list2 != NULL) ? list2->data : 0;

        int diff = x - y - borrow;
        borrow = 0;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }

 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = diff;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }

        if (list1 != NULL) list1 = list1->next;
        if (list2 != NULL) list2 = list2->next;
    }

    while (result != NULL && result->data == 0) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    insertAtEnd(&list1, 8);
    insertAtEnd(&list1, 9);
    insertAtEnd(&list1, 7);
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);

    struct Node* result = subtractLinkedLists(list1, list2);

    printf("List1: ");
    displayList(list1);

    printf("List2: ");
    displayList(list2);

    printf("Output: ");
    displayList(result);

    return 0;
}
