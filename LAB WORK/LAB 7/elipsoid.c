#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_ITERS 10000

double dot(int n, const double *a, const double *b) {
    double s = 0.0;
    for (int i = 0; i < n; ++i) s += a[i] * b[i];
    return s;
}

void mat_vec_mul(int n, const double *M, const double *v, double *out) {
    for (int i = 0; i < n; ++i) {
        double s = 0.0;
        for (int j = 0; j < n; ++j) s += M[i*n + j] * v[j];
        out[i] = s;
    }
}

void rank1_update_sub(int n, double *P, const double *w, double alpha) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            P[i*n + j] -= alpha * w[i] * w[j];
}

void vec_copy(int n, const double *src, double *dst) {
    for (int i = 0; i < n; ++i) dst[i] = src[i];
}

void vec_add_scaled(int n, double *dst, const double *src, double s) {
    for (int i = 0; i < n; ++i) dst[i] += s * src[i];
}

int ellipsoid_feasible(const double *A, const double *b, int m, int n,
                       const double *x0, double R, double eps,
                       double *sol, int max_iters) {
    double *x = malloc(sizeof(double) * n);
    double *P = malloc(sizeof(double) * n * n);
    double *a_row = malloc(sizeof(double) * n);
    double *P_u = malloc(sizeof(double) * n);

    vec_copy(n, x0, x);
    for (int i = 0; i < n*n; ++i) P[i] = 0.0;
    for (int i = 0; i < n; ++i) P[i*n + i] = R*R;

    if (max_iters <= 0) max_iters = MAX_ITERS;

    for (int iter = 0; iter < max_iters; ++iter) {
        int violated = -1;
        double max_violation = -1e300;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) a_row[j] = A[i*n + j];
            double val = dot(n, a_row, x) - b[i];
            if (val > max_violation) {
                max_violation = val;
                violated = i;
            }
        }

        if (max_violation <= eps) {
            vec_copy(n, x, sol);
            free(x); free(P); free(a_row); free(P_u);
            return 1;
        }

        for (int j = 0; j < n; ++j) a_row[j] = A[violated*n + j];

        mat_vec_mul(n, P, a_row, P_u);
        double denom_sq = dot(n, a_row, P_u);
        if (denom_sq <= 0.0) {
            free(x); free(P); free(a_row); free(P_u);
            return 0;
        }
        double s = sqrt(denom_sq);
        for (int i = 0; i < n; ++i) P_u[i] /= s;

        double coef = 1.0 / (n + 1.0);
        vec_add_scaled(n, x, P_u, -coef);

        double tau1 = 2.0 / (n + 1.0);
        double mult = ((double)n * (double)n) / ((double)n*(double)n - 1.0);
        rank1_update_sub(n, P, P_u, tau1);
        for (int i = 0; i < n*n; ++i) P[i] *= mult;

        int bad = 0;
        for (int i = 0; i < n*n; ++i) if (!isfinite(P[i])) { bad = 1; break; }
        if (bad) { free(x); free(P); free(a_row); free(P_u); return 0; }
    }

    free(x); free(P); free(a_row); free(P_u);
    return 0;
}

int ellipsoid_maximize(const double *A, const double *b, int m, int n,
                       const double *c, double lb, double ub, double tol,
                       double *xbest, int max_iters) {

    double *A_aug = malloc(sizeof(double) * (m+1) * n);
    double *b_aug = malloc(sizeof(double) * (m+1));
    for (int i = 0; i < m*n; ++i) A_aug[i] = A[i];
    for (int i = 0; i < m; ++i) b_aug[i] = b[i];

    double R = 1e6;
    double *x0 = malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) x0[i] = 0.0;

    double *sol = malloc(sizeof(double) * n);

    double lo = lb, hi = ub;
    int found_any = 0;

    while (hi - lo > tol) {
        double mid = (lo + hi) / 2.0;
        for (int j = 0; j < n; ++j) A_aug[m*n + j] = -c[j];
        b_aug[m] = -mid;

        int feas = ellipsoid_feasible(A_aug, b_aug, m+1, n, x0, R, 1e-7, sol, max_iters);
        if (feas) {
            ellipsoid_feasible(A_aug, b_aug, m+1, n, x0, R, 1e-7, sol, max_iters);
            double val = dot(n, c, sol);
            for (int i = 0; i < n; ++i) xbest[i] = sol[i];
            lo = mid;
            found_any = 1;
            for (int i = 0; i < n; ++i) x0[i] = sol[i];
        } else {
            hi = mid;
        }
    }

    free(A_aug); free(b_aug); free(x0); free(sol);

    return found_any;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    double *A = malloc(sizeof(double) * m * n);
    double *b = malloc(sizeof(double) * m);
    double *c = malloc(sizeof(double) * n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &A[i*n + j]);

    for (int i = 0; i < m; ++i)
        scanf("%lf", &b[i]);

    for (int j = 0; j < n; ++j)
        scanf("%lf", &c[j]);

    double *xbest = malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) xbest[i] = 0.0;

    int ok = ellipsoid_maximize(A, b, m, n, c, -10000, 10000, 1e-6, xbest, 5000);

    if (ok) {
        printf("Optimal value: %.6f\n", dot(n, c, xbest));
        printf("x:");
        for (int i = 0; i < n; ++i) printf(" %.6f", xbest[i]);
        printf("\n");
    } else {
        printf("Infeasible or failed\n");
    }

    return 0;
}
