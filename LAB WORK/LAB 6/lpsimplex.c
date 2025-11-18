#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void input();
void simplex();
int findPivotColumn();
int findPivotRow(int pivotCol);
void performPivot(int pivotRow, int pivotCol);
void printTable();

int m, n;
float a[MAX][MAX];
float z[MAX];
int basic[MAX];
float ratio[MAX];

int main() {
    input();
    simplex();
    return 0;
}

void input() {
    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter number of constraints: ");
    scanf("%d", &m);

    printf("Enter coefficients of objective function (Z = c1*x1 + c2*x2 + ...):\n");
    for (int j = 0; j < n; j++) scanf("%f", &z[j]);

    printf("Enter coefficients of constraints (<= type):\n");
    for (int i = 0; i < m; i++) {
        printf("Constraint %d:\n", i + 1);
        for (int j = 0; j < n; j++) scanf("%f", &a[i][j]);
        for (int j = n; j < n + m; j++)
            a[i][j] = (j - n == i) ? 1 : 0;
        printf("Enter RHS value: ");
        scanf("%f", &a[i][n + m]);
        basic[i] = n + i;
    }

    for (int j = 0; j < n + m; j++) a[m][j] = -z[j];
    a[m][n + m] = 0;
    n += m;
    printTable();
}

void simplex() {
    int pivotCol, pivotRow;
    while (1) {
        pivotCol = findPivotColumn();
        if (pivotCol == -1) break;
        pivotRow = findPivotRow(pivotCol);
        if (pivotRow == -1) {
            printf("Unbounded solution.\n");
            return;
        }
        performPivot(pivotRow, pivotCol);
        printTable();
    }

    printf("\nOptimal solution found:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (basic[j] == i) {
                printf("x%d = %.2f\n", i + 1, a[j][n]);
                found = 1;
                break;
            }
        }
        if (!found) printf("x%d = 0.00\n", i + 1);
    }
    printf("Maximum Z = %.2f\n", a[m][n]);
}

int findPivotColumn() {
    int pivotCol = -1;
    float min = 0;
    for (int j = 0; j < n; j++) {
        if (a[m][j] < min) {
            min = a[m][j];
            pivotCol = j;
        }
    }
    return pivotCol;
}

int findPivotRow(int pivotCol) {
    int pivotRow = -1;
    float minRatio = 1e9;
    for (int i = 0; i < m; i++) {
        if (a[i][pivotCol] > 0) {
            float val = a[i][n] / a[i][pivotCol];
            if (val < minRatio) {
                minRatio = val;
                pivotRow = i;
            }
        }
    }
    return pivotRow;
}

void performPivot(int pivotRow, int pivotCol) {
    float pivotVal = a[pivotRow][pivotCol];
    for (int j = 0; j <= n; j++) a[pivotRow][j] /= pivotVal;
    for (int i = 0; i <= m; i++) {
        if (i != pivotRow) {
            float factor = a[i][pivotCol];
            for (int j = 0; j <= n; j++) a[i][j] -= factor * a[pivotRow][j];
        }
    }
    basic[pivotRow] = pivotCol;
}

void printTable() {
    printf("\nCurrent Simplex Table:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) printf("%8.2f ", a[i][j]);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}
