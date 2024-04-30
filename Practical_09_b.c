#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Target not found
}

int main() {
    int array[] = {20, 40, 10, 80, 60, 90, 70, 30, 100, 50};
    int targetElement = 60;
    int n = sizeof(array) / sizeof(array[0]);

    qsort(array, n, sizeof(int), compare);

    int result = binarySearch(array, 0, n - 1, targetElement);

    if (result == -1)
        printf("Element not present in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
