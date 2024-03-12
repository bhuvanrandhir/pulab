#include <stdio.h>
#include <stdlib.h>

int **resize(int **arr, int numRows, int numCols, int newNumRows, int newNumCols)
{
    // Reallocate memory for the new 2D array
    arr = (int*)realloc(arr, newNumRows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    // Allocate memory for each new row and initialize new elements
    for (int i = numRows; i < newNumRows; i++)
    {
        arr[i] = malloc(newNumCols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed for row %d.\n", i);
        }
        // Initialize new elements
        for (int j = 0; j < newNumCols; j++)
        {
            printf("Enter value for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Reallocate memory for existing rows
    for (int i = 0; i < numRows; i++)
    {
        arr[i] = realloc(arr[i], newNumCols * sizeof(int));

        if (arr[i] == NULL)
        {
            printf("Memory reallocation failed for row %d.\n", i);
            // Free the memory allocated for rows after the failed reallocation
            for (int j = numRows; j < newNumRows; j++)
            {
                free(arr[j]);
            }
            free(arr);
            arr=NULL;
        }
    }

    return arr;
}

//by using this function  you can print the 2d array 
void printArray(int **arr, int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("%d \t\t", arr[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{

    int numRows;
    int numCols;
    printf("\n Enter the number of rows : ");
    scanf("%d", &numRows);
    printf("\n Enter the number of columns : ");
    scanf("%d", &numCols);
    // Dynamically allocate memory for the initial 2D array
    int **arr;
    //we are allocating memory for the rows here
    arr = (int *)malloc(numRows * sizeof(int *));
    
    //checking for the memory allocated sucessfully or not for rows
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
    }

    //we are allocating memory for the rows elements means columns
    for (int i = 0; i < numRows; i++)
    {
        arr[i] = (int *) malloc(numCols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed.\n");
        }
    }

    // Initialize the array with some values
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("Enter value for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Original 2D array:\n");
    //calling the function
    printArray(arr, numRows, numCols);
    printf("\n");

    // Resize the array
    
    int newNumRows;
    int newNumCols;
    printf("\nEnter the number of rows to resize subArrays : ");
    scanf("%d", &newNumRows);
    printf("\n Enter the number of columns to resize the elements of arrays  : ");
    scanf("%d", &newNumCols);
    //calling the function to resize the 2d array
    arr = resize(arr, numRows, numCols, newNumRows, newNumCols);

    printf("2D array after resizing:\n");
    printArray(arr, newNumRows, newNumCols);
    printf("\n");

    // Free the memory when done
    for (int i = 0; i < newNumRows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}


