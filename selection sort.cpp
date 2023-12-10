#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}



int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Perform selection sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
     for (int i = 0; i <n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

