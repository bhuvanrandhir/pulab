#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct
{
    int EMP_ID;
    char EMP_NAME[50];
    int EMP_DEPTID;
    long EMP_PHNO;
    float EMP_SALARY;
} Employee;

/* If the first string (emp1->EMP_NAME) is lexicographically less than the second string (emp2->EMP_NAME), strcmp returns a negative value.
If the first string is lexicographically greater than the second string, strcmp returns a positive value.
If the two strings are equal, strcmp returns 0.*/

int compareEmployeeNames(const void *a, const void *b)
{
    Employee *emp1 = (Employee *)a;
    Employee *emp2 = (Employee *)b;
    return strcmp(emp1->EMP_NAME, emp2->EMP_NAME);
}

int main()
{
    Employee employees[MAX_EMPLOYEES];
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("EMP_ID: ");
        scanf("%d", &employees[i].EMP_ID);

        printf("EMP_NAME: ");
        scanf("%s", employees[i].EMP_NAME);

        printf("EMP_DEPTID: ");
        scanf("%d", &employees[i].EMP_DEPTID);

        printf("EMP_PHNO: ");
        scanf("%ld", &employees[i].EMP_PHNO);

        printf("EMP_SALARY: ");
        scanf("%f", &employees[i].EMP_SALARY);
    }
    /*
    The qsort function in C is a part of the standard library (stdlib.h) and is used for sorting elements in an array. It implements the quicksort algorithm, which is an efficient sorting algorithm with an average time complexity of O(n log n).
    */

    qsort(employees, numEmployees, sizeof(Employee), compareEmployeeNames);
    
    /*
    void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

    base: A pointer to the base address of the array to be sorted.
    nmemb: The number of elements in the array.
    size: The size (in bytes) of each element in the array.
    compar: A pointer to a user-defined comparison function that compares two elements and returns an integer value based on their relative order.
    */

    printf("\nEmployee details (sorted by EMP_NAME):\n");
    for (int i = 0; i < numEmployees; i++)
    {
        printf("EMP_ID: %d\n", employees[i].EMP_ID);
        printf("EMP_NAME: %s\n", employees[i].EMP_NAME);
        printf("EMP_DEPTID: %d\n", employees[i].EMP_DEPTID);
        printf("EMP_PHNO: %ld\n", employees[i].EMP_PHNO);
        printf("EMP_SALARY: %.2f\n\n", employees[i].EMP_SALARY);
    }

    return 0;
}
