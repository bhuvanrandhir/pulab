#include <stdio.h>
//Function For Taking Elements From User
void inputarr(int arr[], int size);
//Function to print array
void printarr(int arr[], int size);
//Function For Bubble Sort
void bubbleSort(int arr[], int size);
//Function For Swapping
void swap(int *a, int *b);
//Main Function
int main(){
    int n;
    printf("Enter the Size Of Array : ");
    scanf("%d",&n);
    int arr[n];
    inputarr(arr,n);
    printf("\n");
    // int arr[] = {5, 2, 9, 4, 1, 3, 8, 7, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Elements : ");
    printarr(arr,n);
    
    printf("Sorted Elements : ");
    bubbleSort(arr,n);
    printarr(arr,n);
    
    printf("products of every two odd position elements : ");
    printf("{ ");
    for(int i=0;i<n-2;i++){
        if(i%2==0){
            printf("%d ",arr[i]*arr[i+2]);
        }
    }
    printf(" }");
    
    printf("\n");
    printf("sum of every two even position elements Explanation : ");
    printf("{ ");
    for(int i=1;i<n-2;i++){
        if(i%2==1){
            printf("%d ",arr[i]+arr[i+2]);
        }
    }
    printf(" }");
    
return 0;
}


void inputarr(int arr[], int size){
    printf("Enter Elements Of Array : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

void printarr(int arr[], int size){
    printf("{");
    
    for(int i=0;i<size;i++){
        printf(" %d", arr[i]);
    }
    printf(" }");
    printf("\n");
}

void bubbleSort(int arr[], int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
