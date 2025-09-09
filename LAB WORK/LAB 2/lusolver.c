#include <stdio.h>

#define N 4

void luDecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }
        for (int k = i; k < N; k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }
}

void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }
}

int main() {
    double A[N][N], b[N], L[N][N] = {0}, U[N][N] = {0};
    double y[N], x[N];

    printf("Enter %d x %d matrix A:\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter vector b (%d elements):\n", N);
    for (int i = 0; i < N; i++)
        scanf("%lf", &b[i]);

    luDecomposition(A, L, U);

    printf("\nL matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%8.4lf ", L[i][j]);
        printf("\n");
    }

    printf("\nU matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%8.4lf ", U[i][j]);
        printf("\n");
    }

    forwardSubstitution(L, b, y);
    backwardSubstitution(U, y, x);

    printf("\nSolution vector x:\n");
    for (int i = 0; i < N; i++)
        printf("x[%d] = %lf\n", i, x[i]);

    return 0;
}
