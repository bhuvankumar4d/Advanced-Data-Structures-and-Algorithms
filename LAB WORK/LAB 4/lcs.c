#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCSLength(char X[], char Y[], int m, int n) {
    int L[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void printAllCommon(char *X, char *Y, int m, int n, char *res, int index) {
    if (m == 0 || n == 0) {
        if (index > 0) {
            res[index] = '\0';
            printf("%s\n", res);
        }
        return;
    }

    if (X[m - 1] == Y[n - 1]) {
        res[index] = X[m - 1];
        printAllCommon(X, Y, m - 1, n - 1, res, index + 1);
    } else {
        printAllCommon(X, Y, m - 1, n, res, index);
        printAllCommon(X, Y, m, n - 1, res, index);
    }
}

void printLCS(char X[], char Y[], int m, int n) {
    int L[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLongest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX], Y[MAX];
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("\nAll Common Subsequences:\n");
    char res[MAX];
    printAllCommon(X, Y, m, n, res, 0);

    printLCS(X, Y, m, n);
    printf("Length of LCS = %d\n", LCSLength(X, Y, m, n));

    return 0;
}
