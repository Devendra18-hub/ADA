#include <stdio.h>

int a[20][20], visited[20], n;

void bfs(int s) {
    int queue[20];
    int f = -1, r = -1;
    queue[++r] = s;
    visited[s] = 1;

    while (f != r) {
        int curr = queue[++f];
        printf("%d", curr);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && a[curr][i] == 1) {
                queue[++r] = i;
                visited[i] = 1;
            }
        }

        if (f != r)
            printf("-->");
    }
    printf("\n");
}

int main() {
    int s;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &s);

    printf("BFS traversal starting from vertex %d: ", s);
    bfs(s);

    return 0;
}
