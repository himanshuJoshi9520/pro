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

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}


int countNodesFromRight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodesFromRight(root->right) + 1;
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
    printf("2. Search for a key\n");
    printf("3. Delete a node\n");
    printf("4. Find total number of leaf nodes\n");
    printf("5. Find height of the binary search tree\n");
    printf("6. Count total numbers of nodes from right hand side of root node\n");
    printf("7. Find kth largest element\n");
    printf("8. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key, result, k, count = 0;
    do {
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
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = search(root, key) != NULL;
                printf("Key %d %s found in the BST.\n", key, result ? "is" : "is not");
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 4:
                printf("Total number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 5:
                printf("Height of the binary search tree: %d\n", findHeight(root));
                break;
            case 6:
                printf("Total numbers of nodes from right hand side of root node: %d\n", countNodesFromRight(root));
                break;
            case 7:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                count = 0;
                kthLargestElement(root, k, &count);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);
    free(root);

    return 0;
}
