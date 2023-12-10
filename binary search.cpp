#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if key is present at the middle
        if (arr[mid] == key) {
            return mid; // Element found, return index
        }

        // If key is greater, ignore the left half
        if (arr[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1; // Element not found, return -1
}

int main() {
    int n, key;

    // Input the size of the array
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Input the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Check if the element was found
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

