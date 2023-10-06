#include <stdio.h>
#include <stdlib.h>

// Define a structure
struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    // Declare a pointer to a structure
    struct Student *studentPtr;

    // Allocate memory for a structure using malloc
    studentPtr = (struct Student *)malloc(sizeof(struct Student));

    // Check if memory allocation was successful
    if (studentPtr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize structure members using pointer
    studentPtr->id = 1;
    strcpy(studentPtr->name, "Adhithya");
    studentPtr->gpa = 8.07;

    // Access and print structure members
    printf("Student ID: %d\n", studentPtr->id);
    printf("Name: %s\n", studentPtr->name);
    printf("GPA: %.2f\n", studentPtr->gpa);

    // Free allocated memory
    free(studentPtr);

    return 0;
}
