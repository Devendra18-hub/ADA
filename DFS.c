#include <stdio.h>

int a[20][20], visited[20], n;

void dfs(int s) {
    printf("%d", s + 1); // Print node number (starting from 1 instead of 0)
    visited[s] = 1;

    for (int j = 0; j < n; j++) {
        if (!visited[j] && a[s][j] == 1) {
            printf("-->");
            dfs(j);
        }
    }
}

int isconnected() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0; // If any node is not visited, the graph is not connected
        }
    }
    return 1; // All nodes visited, graph is connected
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal starting from node 1: ");
    dfs(0); // Start DFS from node 0 (which corresponds to node 1 in the prompt)

    if (isconnected()) {
        printf("\nGraph is connected\n");
    } else {
        printf("\nGraph is not connected\n");
    }

    return 0;
}
