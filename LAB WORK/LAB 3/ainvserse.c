#include <stdio.h>

#define N 3

void printMatrix(float A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.3f ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float A[N][N], I[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &A[i][j]);
            I[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    for (int i = 0; i < N; i++) {
        float diag = A[i][i];
        if (diag == 0.0) {
            printf("Matrix is singular\n");
            return 0;
        }
        for (int j = 0; j < N; j++) {
            A[i][j] /= diag;
            I[i][j] /= diag;
        }
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = A[k][i];
                for (int j = 0; j < N; j++) {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }
    printMatrix(I);
    return 0;
}