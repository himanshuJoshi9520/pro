#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
void kthLargestElement(struct Node* root, int k, int* count) {
    if (root == NULL || *count >= k) {
        return;
    }
    kthLargestElement(root->right, k, count);
    (*count)++;
    if (*count == k) {
        printf("%dth Largest Element: %d\n", k, root->key);
        return;
    }
    kthLargestElement(root->left, k, count);
}
   void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a key\n");
	printf("2. Find kth largest element\n"); }
    int main()
    {
    	struct Node* root = NULL;
        int choice, key, result, k, count = 0;
        while(1){
		  
            printMenu();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
              case 1:	
               printf("Enter the key to insert: ");
               scanf("%d", &key);
               root = insert(root, key);
               break;
             case 2: 
			   printf("Enter the value of k: ");
               scanf("%d", &k);
               count = 0;
               kthLargestElement(root, k, &count);
			   break;
			   }
           }
	}
