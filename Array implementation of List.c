#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the list
struct ArrayList {
    int arr[MAX_SIZE];
    int size;
};

// Function to initialize the list
void initialize(struct ArrayList *list) {
    list->size = 0;
}

// Function to add an element to the end of the list
void append(struct ArrayList *list, int value) {
    if (list->size < MAX_SIZE) {
        list->arr[list->size] = value;
        list->size++;
    } else {
        printf("List is full. Cannot append more elements.\n");
    }
}

// Function to get an element at a specific index
int get(struct ArrayList *list, int index) {
    if (index >= 0 && index < list->size) {
        return list->arr[index];
    } else {
        printf("Index out of bounds.\n");
        return -1; // Return a sentinel value to indicate an error
    }
}

// Function to print the elements in the list
void print(struct ArrayList *list) {
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

int main() {
    struct ArrayList myList;
    initialize(&myList);

    // Add elements to the list
    append(&myList, 10);
    append(&myList, 20);
    append(&myList, 30);

    // Print the list
    print(&myList);

    // Access an element by index
    int element = get(&myList, 1);
    printf("Element at index 1: %d\n", element);

    return 0;
}
