#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* create_vector(int size) {
    return (double*)calloc(size, sizeof(double));
}

double** create_matrix(int rows, int cols) {
    double **mat = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++)
        mat[i] = (double*)calloc(cols, sizeof(double));
    return mat;
}

int solve_system(int n, double **M, double *v, double *sol) {
    double **A = create_matrix(n, n);
    double *b = create_vector(n);
    
    for(int i=0; i<n; i++) {
        b[i] = v[i];
        for(int j=0; j<n; j++) A[i][j] = M[i][j];
    }

    for (int k = 0; k < n; k++) {
        int pivot = k;
        double max_val = fabs(A[k][k]);
        
        for (int i = k + 1; i < n; i++) {
            if (fabs(A[i][k]) > max_val) {
                max_val = fabs(A[i][k]);
                pivot = i;
            }
        }

        if (max_val < 1e-12) return 0;

        if (pivot != k) {
            double *tPtr = A[k]; A[k] = A[pivot]; A[pivot] = tPtr;
            double tVal = b[k]; b[k] = b[pivot]; b[pivot] = tVal;
        }

        for (int i = k + 1; i < n; i++) {
            double f = A[i][k] / A[k][k];
            b[i] -= f * b[k];
            for (int j = k; j < n; j++) {
                A[i][j] -= f * A[k][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * sol[j];
        }
        sol[i] = (b[i] - sum) / A[i][i];
    }

    for(int i=0; i<n; i++) free(A[i]);
    free(A);
    free(b);
    return 1;
}

int main() {
    int m, n;
    
    printf("Enter number of Variables (n): ");
    scanf("%d", &n);
    printf("Enter number of Constraints (m): ");
    scanf("%d", &m);

    double *c = create_vector(n);
    double *b = create_vector(m);
    double **A = create_matrix(m, n);

    printf("Enter Cost Vector c (%d values): ", n);
    for(int i=0; i<n; i++) scanf("%lf", &c[i]);

    printf("Enter Constraint Matrix A (%d x %d):\n", m, n);
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter RHS Vector b (%d values): ", m);
    for(int i=0; i<m; i++) scanf("%lf", &b[i]);

    double *x = create_vector(n);
    double *s = create_vector(n); 
    double *y = create_vector(m);

    for(int i=0; i<n; i++) { x[i] = 1.0; s[i] = 1.0; }
    
    int iter = 0;
    while (iter < 20) {
        double *rb = create_vector(m);
        double *rc = create_vector(n);
        double gap = 0.0;

        for(int i=0; i<m; i++) {
            double val = 0.0;
            for(int j=0; j<n; j++) val += A[i][j] * x[j];
            rb[i] = b[i] - val;
        }

        for(int j=0; j<n; j++) {
            double val = 0.0;
            for(int i=0; i<m; i++) val += A[i][j] * y[i];
            rc[j] = c[j] - val - s[j];
        }

        for(int j=0; j<n; j++) gap += x[j] * s[j];
        double mu = gap / n;

        if (gap < 1e-6) break;

        double **M = create_matrix(m, m);
        double *rhs_y = create_vector(m);
        double *d2 = create_vector(n);
        
        for(int j=0; j<n; j++) d2[j] = x[j] / s[j];

        for(int i=0; i<m; i++) {
            for(int k=0; k<m; k++) {
                double sum = 0.0;
                for(int j=0; j<n; j++) sum += A[i][j] * d2[j] * A[k][j];
                M[i][k] = sum;
            }
        }

        double sigma = 0.1;
        for(int i=0; i<m; i++) {
            rhs_y[i] = rb[i];
            for(int j=0; j<n; j++) {
                double term = rc[j] + (x[j]*s[j] - sigma*mu)/x[j];
                rhs_y[i] += A[i][j] * d2[j] * term;
            }
        }

        double *dy = create_vector(m);
        solve_system(m, M, rhs_y, dy);

        double *ds = create_vector(n);
        double *dx = create_vector(n);

        for(int j=0; j<n; j++) {
            double val = 0.0;
            for(int i=0; i<m; i++) val += A[i][j] * dy[i];
            ds[j] = rc[j] - val;
        }

        for(int j=0; j<n; j++) {
            dx[j] = ( -x[j]*s[j] + sigma*mu - x[j]*ds[j] ) / s[j];
        }

        double alpha = 1.0;
        for(int j=0; j<n; j++) {
            if (dx[j] < 0) {
                double step_val = -x[j] / dx[j];
                if (step_val < alpha) alpha = step_val;
            }
            if (ds[j] < 0) {
                double step_val = -s[j] / ds[j];
                if (step_val < alpha) alpha = step_val;
            }
        }

        alpha *= 0.95;

        for(int j=0; j<n; j++) x[j] += alpha * dx[j];
        for(int j=0; j<n; j++) s[j] += alpha * ds[j];
        for(int i=0; i<m; i++) y[i] += alpha * dy[i];

        free(rb); free(rc); free(rhs_y); free(dy); free(dx); free(ds); free(d2);
        for(int i=0; i<m; i++) free(M[i]); free(M);
        
        iter++;
    }

    printf("\nResult Vector X:\n");
    for(int i=0; i<n; i++) printf("%.4f ", x[i]);
    
    double obj = 0.0;
    for(int i=0; i<n; i++) obj += c[i] * x[i];
    printf("\nOptimal Objective Value: %.4f\n", obj);

    return 0;
}