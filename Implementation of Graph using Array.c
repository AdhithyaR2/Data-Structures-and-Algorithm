#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define a structure for the graph
struct Graph {
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize a graph with 'n' vertices
void initializeGraph(struct Graph* graph, int n) {
    graph->vertices = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->matrix[i][j] = 0; // Initialize all cells to 0 (no edges)
        }
    }
}

// Function to add an edge between vertices 'u' and 'v'
void addEdge(struct Graph* graph, int u, int v) {
    if (u >= 0 && u < graph->vertices && v >= 0 && v < graph->vertices) {
        graph->matrix[u][v] = 1;
        graph->matrix[v][u] = 1; // For undirected graphs
    } else {
        printf("Invalid vertices\n");
    }
}

// Function to display the adjacency matrix of the graph
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    int n = 5; // Number of vertices

    initializeGraph(&graph, n);

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);

    // Display the adjacency matrix
    displayGraph(&graph);

    return 0;
}
