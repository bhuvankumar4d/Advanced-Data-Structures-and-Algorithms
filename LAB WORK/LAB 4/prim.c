#include <stdio.h>
#include <limits.h>
#define MAX 100

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0}, edges = 0, minCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    visited[0] = 1;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        int min = INT_MAX, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            printf("%d -> %d  cost: %d\n", u + 1, v + 1, cost[u][v]);
            minCost += cost[u][v];
            visited[v] = 1;
            edges++;
        }
    }
    printf("\nMinimum cost of spanning tree = %d\n", minCost);
    return 0;
}
