#include <stdio.h>
#define MAX 64

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            C[cRow+i][cCol+j] = A[aRow+i][aCol+j] + B[bRow+i][bCol+j];
}

void sub(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            C[cRow+i][cCol+j] = A[aRow+i][aCol+j] - B[bRow+i][bCol+j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],int aRow, int aCol, int bRow, int bCol, int cRow, int cCol, int n) {
    if (n == 1) {
        C[cRow][cCol] = A[aRow][aCol] * B[bRow][bCol];
        return;
    }

    int k = n/2;
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];

    for (int i=0;i<MAX;i++)
        for (int j=0;j<MAX;j++)
            M1[i][j]=M2[i][j]=M3[i][j]=M4[i][j]=M5[i][j]=M6[i][j]=M7[i][j]=T1[i][j]=T2[i][j]=0;

    add(A,A,T1, aRow, aCol, aRow+k, aCol+k, 0,0,k);
    add(B,B,T2, bRow, bCol, bRow+k, bCol+k, 0,0,k);
    strassen(T1,T2,M1,0,0,0,0,0,0,k);

    add(A,A,T1, aRow+k,aCol, aRow+k,aCol+k, 0,0,k);
    strassen(T1,B,M2,0,0, bRow,bCol,0,0,k);

    sub(B,B,T2, bRow,bCol+k, bRow+k,bCol+k, 0,0,k);
    strassen(A,T2,M3, aRow,aCol,0,0,0,0,k);

    sub(B,B,T2, bRow+k,bCol, bRow,bCol, 0,0,k);
    strassen(A,T2,M4, aRow+k,aCol+k,0,0,0,0,k);

    add(A,A,T1, aRow,aCol, aRow,aCol+k, 0,0,k);
    strassen(T1,B,M5,0,0, bRow+k,bCol+k,0,0,k);

    sub(A,A,T1, aRow+k,aCol, aRow,aCol, 0,0,k);
    add(B,B,T2, bRow,bCol, bRow,bCol+k, 0,0,k);
    strassen(T1,T2,M6,0,0,0,0,0,0,k);

    sub(A,A,T1, aRow,aCol+k, aRow+k,aCol+k, 0,0,k);
    add(B,B,T2, bRow+k,bCol, bRow+k,bCol+k, 0,0,k);
    strassen(T1,T2,M7,0,0,0,0,0,0,k);

    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            C[cRow+i][cCol+j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            C[cRow+i][cCol+j+k] = M3[i][j] + M5[i][j];

    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            C[cRow+i+k][cCol+j] = M2[i][j] + M4[i][j];

    for (int i=0;i<k;i++)
        for (int j=0;j<k;j++)
            C[cRow+i+k][cCol+j+k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
}

void printMatrix(int A[MAX][MAX], int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 2;
    int A[MAX][MAX] = {{1,2},{3,4}};
    int B[MAX][MAX] = {{5,6},{7,8}};
    int C[MAX][MAX] = {0};

    strassen(A,B,C,0,0,0,0,0,0,n);
    printMatrix(C,n);
    return 0;
}