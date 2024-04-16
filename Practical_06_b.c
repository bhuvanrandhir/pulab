#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[] = {9, 1, 9, 8, 3, 5, 4, 7, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using selection sort (or any other sorting algorithm)
    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int product_odd = 1;  // Initialize product of odd elements to 1
    int sum_even = 0;     // Initialize sum of even elements to 0

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  // If even position (0-based indexing)
            sum_even += arr[i];
        } else {  // If odd position
            product_odd *= arr[i];
        }
    }

    printf("Product of every two odd position elements: %d\n", product_odd);
    printf("Sum of every two even position elements: %d\n", sum_even);

    return 0;
}
