#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define a structure for the binary tree node
struct TreeNode {
    int data;
};

// Define the array to store the binary tree
struct TreeNode tree[MAX_SIZE];

// Initialize the tree with NULL values
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i].data = -1; // Assuming -1 represents an empty node
    }
}

// Insert a node into the binary tree
void insertNode(int value, int index) {
    if (index < MAX_SIZE && tree[index].data == -1) {
        tree[index].data = value;
    } else {
        printf("Tree is full or invalid index\n");
    }
}

// Display the elements of the binary tree
void displayTree() {
    printf("Binary Tree (Array Representation):\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i].data != -1) {
            printf("%d ", tree[i].data);
        }
    }
    printf("\n");
}

int main() {
    initializeTree();

    // Insert some nodes into the binary tree
    insertNode(1, 0); // Root
    insertNode(2, 1); // Left child of root
    insertNode(3, 2); // Left child of the left child
    insertNode(4, 3); // Right child of the left child

    // Display the binary tree
    displayTree();

    return 0;
}
