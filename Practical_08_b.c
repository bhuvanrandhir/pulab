#include <stdio.h>

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int m, n, i, j;
    
    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sort each row in ascending order
    printf("Matrix after sorting each row in ascending order and printing in column-major order:\n");
    for (j = 0; j < n; j++) {
        // Extract column j into a temporary array
        int column[m];
        for (i = 0; i < m; i++) {
            column[i] = matrix[i][j];
        }
        
        // Sort the temporary array
        sortArray(column, m);
        
        // Print the sorted column
        for (i = 0; i < m; i++) {
            printf("%d ", column[i]);
        }
        printf("\n");
    }

    return 0;
}
