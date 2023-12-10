#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next; };
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return; }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;    }
    current->next = newNode; } 
void splitList(struct Node* original, struct Node** positive, struct Node** negative) {
    struct Node* current = original;
    while (current != NULL) {
        if (current->data >= 0) {
            insertAtEnd(positive, current->data);
        } else {
            insertAtEnd(negative, current->data);     }
        current = current->next;     }
} void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;     }
    printf("NULL\n"); }
int main() {
    struct Node* original = NULL;
    struct Node* positive = NULL;
    struct Node* negative = NULL;
    int n, value;
    printf("Enter the number of elements in the linkedlist:");
    scanf("%d", &n);
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        insertAtEnd(&original, value);     }
    splitList(original, &positive, &negative);
    printf("Original linked list:\n");
    displayList(original);
    printf("Positive linked list:\n");
    displayList(positive);
    printf("Negative linked list:\n");
    displayList(negative);
    return 0; }
