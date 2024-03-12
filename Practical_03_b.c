/*
Write a c program to store records of n students based on roll_no, name, gender and 5 subject
marks
i) calculate percentage each student using 5 subjects
ii) Display the student list according to their percentages
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

struct Student {
    int roll_no;
    char name[MAX_NAME_LENGTH];
    char gender;
    float marks[5];
    float percentage;
};

void calculatePercentage(struct Student *student) {
    float totalMarks = 0;
    for (int i = 0; i < 5; ++i) {
        totalMarks += student->marks[i];
    }
    student->percentage = totalMarks / 5.0;
}

void sortByPercentage(struct Student *students, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].percentage < students[j + 1].percentage) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Enter details of student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender: ");
        scanf(" %c", &students[i].gender);
        printf("Enter marks of 5 subjects: ");
        for (int j = 0; j < 5; ++j) {
            scanf("%f", &students[i].marks[j]);
        }
        calculatePercentage(&students[i]);
    }

    sortByPercentage(students, n);

    printf("\nStudent list sorted by percentage:\n");
    printf("Roll No\tName\tGender\tPercentage\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%s\t%c\t%.2f%%\n", students[i].roll_no, students[i].name, students[i].gender, students[i].percentage);
    }

    return 0;
}
