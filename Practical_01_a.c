#include <stdio.h>
#include <stdlib.h>

// Function to resize the array
int *reSize(int *arr, int currentSize, int newSize)
{
    // Reallocate memory using realloc
    int *newArr =(int*) realloc(arr, newSize * sizeof(int));

    if (newArr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // If the new size is larger than the current size, initialize the new elements
    if (newSize > currentSize)
    {
        printf("\n You are trying to increase the size of an array : ");
        printf("\nEnter the new array elements : ");
        for (int i = currentSize; i < newSize; i++)
        {
            scanf("%d",&newArr[i]);
        }
    }

    return newArr;
}

int main()
{
    int *arr;
    int size;
    printf("Enter the size of an array : ");
    scanf("%d",&size);
    

    // Create an array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Initialize the original array
    printf("Enter an array elements : ");
    for (int i = 0; i < size; i++)
    {

        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("\n Array elements are : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    // New size of the array
    printf("Enter the new size of the array");
    int newSize;
    scanf("%d", &newSize);
    newSize+=size;
    // Resize the array
    arr = reSize(arr, size, newSize);

    // Print the resized array
    printf("\n Elements of the resized array are : ");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d\n", arr[i]);
    }

    // Free the allocated memory
    free(arr);
    arr = NULL;

    return 0;
}


 