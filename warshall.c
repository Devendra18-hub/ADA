#include <stdio.h>

#define MAX_VERTICES 100

// Function to implement Warshall's Algorithm
void warshall(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    // k is the intermediate vertex
    for (int k = 0; k < n; k++) {
        // i is the starting vertex
        for (int i = 0; i < n; i++) {
            // j is the destination vertex
            for (int j = 0; j < n; j++) {
                // If there's a path from i to k and from k to j, then there is a path from i to j
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }
}

// Function to print the adjacency matrix (Transitive Closure)
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n; // number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Read the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix (graph representation)
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Warshall's Algorithm to compute the transitive closure
    warshall(graph, n);

    // Output the transitive closure matrix
    printf("\nThe transitive closure matrix is:\n");
    printGraph(graph, n);

    return 0;
}
