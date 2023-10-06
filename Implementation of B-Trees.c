#include <stdio.h>
#include <stdlib.h>

// Define the order of the B-tree
#define ORDER 3

// Define the structure of a B-tree node
struct BTreeNode {
    int keys[ORDER - 1];
    struct BTreeNode* children[ORDER];
    int keyCount;
    int isLeaf;
};

// Create a new B-tree node
struct BTreeNode* createNode() {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->keyCount = 0;
    newNode->isLeaf = 1;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Insert a key into the B-tree
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root == NULL) {
        struct BTreeNode* newNode = createNode();
        newNode->keys[0] = key;
        newNode->keyCount = 1;
        return newNode;
    }

    if (root->keyCount < ORDER - 1) {
        // If the current node is not full, insert the key into it
        int i = root->keyCount - 1;
        while (i >= 0 && key < root->keys[i]) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = key;
        root->keyCount++;
    } else {
        // If the current node is full, split it
        // (This is a simplified example and does not handle splitting properly)
        root->children[root->keyCount] = insert(root->children[root->keyCount], key);
    }

    return root;
}

// Print the keys of the B-tree in-order
void inorderTraversal(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->keyCount; i++) {
            inorderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorderTraversal(root->children[i]);
    }
}

int main() {
    struct BTreeNode* root = NULL;

    int keys[] = {3, 7, 1, 8, 2, 6, 5, 4};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    printf("In-order traversal of the B-tree: ");
    inorderTraversal(root);
    printf("\n");

    // Clean up the B-tree (not implemented in this example)
    // You would typically need to free the allocated memory.

    return 0;
}
