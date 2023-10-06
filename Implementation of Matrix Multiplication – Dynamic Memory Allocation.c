#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to perform matrix multiplication
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = allocateMatrix(rowsA, colsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Get matrix dimensions from the user
    printf("Enter the dimensions of matrix A (rows cols): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the dimensions of matrix B (rows cols): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if matrix multiplication is possible
    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    // Allocate memory for matrices A, B, and the result
    int** A = allocateMatrix(rowsA, colsA);
    int** B = allocateMatrix(rowsB, colsB);

    // Input matrices A and B
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform matrix multiplication
    int** result = multiplyMatrices(A, B, rowsA, colsA, colsB);

    // Print the result
    printf("Result of matrix multiplication:\n");
    printMatrix(result, rowsA, colsB);

    // Deallocate memory
    deallocateMatrix(A, rowsA);
    deallocateMatrix(B, rowsB);
    deallocateMatrix(result, rowsA);

    return 0;
}
