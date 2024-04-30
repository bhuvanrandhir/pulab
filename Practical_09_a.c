
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1; // Element found
        }
    }
    return 0; // Element not found
}

int main() {
    // Given list of elements
    int arr[] = {65, 20, 10, 55, 32, 12, 50, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Search element
    int searchElement = 12;

    // Perform linear search
    int result = linearSearch(arr, size, searchElement);

    // Display the result
    if (result) {
        printf("Element %d found in the list.\n", searchElement);
    } else {
        printf("Element %d not found in the list.\n", searchElement);
    }

    return 0;
}
