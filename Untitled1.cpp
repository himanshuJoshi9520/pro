#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char Product_Id;
    char Product_Name[100];
    int Total_Sale;
    char Product_Grade;
    struct Product* next;
};

void enqueue(struct Product** front, struct Product** rear, char id, char name[], int sale, char grade) {
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    newProduct->Product_Id = id;
    strcpy(newProduct->Product_Name, name);
    newProduct->Total_Sale = sale;
    newProduct->Product_Grade = grade;
    newProduct->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newProduct;
    } else {
        (*rear)->next = newProduct;
        *rear = newProduct;
    }
    printf("Product inserted successfully.\n");
}

void dequeue(struct Product** front, struct Product** rear) {
    if (*front == NULL) {
        printf("Queue is empty. Unable to delete.\n");
        return;
    }
    struct Product* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    printf("Product deleted successfully.\n");
}

void display(struct Product* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Product* temp = front;
    printf("Products in the queue:\n");
    while (temp != NULL) {
        printf("Product Id: %c\n", temp->Product_Id);
        printf("Product Name: %s\n", temp->Product_Name);
        printf("Total Sale: %d\n", temp->Total_Sale);
        printf("Product Grade: %c\n", temp->Product_Grade);
        printf("--------------------\n");
        temp = temp->next;
    }
}

int main() {
    struct Product* front = NULL;
    struct Product* rear = NULL;
    int choice;
    char id, name[100], grade;
    int sale;

    while(1) {
        printf("Menu:\n");
        printf("1. Insert a product\n");
        printf("2. Delete a product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product details:\n");
                printf("Product Id: ");
                scanf(" %c", &id);
                printf("Product Name: ");
                scanf(" %[^\n]s", name);
                printf("Total Sale: ");
                scanf("%d", &sale);
                printf("Product Grade: ");
                scanf(" %c", &grade);
                enqueue(&front, &rear, id, name, sale, grade);
                break;
            case 2: 
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
}
     
 
 
