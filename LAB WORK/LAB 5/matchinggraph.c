#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100 

int graph[MAX][MAX];
int nU, nV;

int matchR[MAX];
bool seen[MAX];

bool bpm(int u) {
    for (int v = 0; v < nV; v++) {
        if (graph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM() {
    memset(matchR, -1, sizeof(matchR));
    int result = 0;

    for (int u = 0; u < nU; u++) {
        memset(seen, 0, sizeof(seen));

        if (bpm(u))
            result++;
    }
    return result;
}

int main() {
    printf("Enter number of vertices in U and V: ");
    scanf("%d %d", &nU, &nV);

    printf("Enter adjacency matrix (%d x %d):\n", nU, nV);
    for (int i = 0; i < nU; i++)
        for (int j = 0; j < nV; j++)
            scanf("%d", &graph[i][j]);

    int maxMatching = maxBPM();
    printf("Maximum Matching is %d\n", maxMatching);

    printf("Matched pairs (U->V):\n");
    for (int v = 0; v < nV; v++) {
        if (matchR[v] != -1)
            printf("U%d -> V%d\n", matchR[v], v);
    }

    return 0;
}
