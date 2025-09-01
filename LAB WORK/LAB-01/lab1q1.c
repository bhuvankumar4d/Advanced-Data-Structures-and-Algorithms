#include <stdio.h>
#include <math.h>
#include <limits.h>

#define NUM_FUNCS 12

typedef double (*GrowthFunc)(double);

double f1(double n){  return n * log(n);          }
double f2(double n){  return 12 * sqrt(n);        }
double f3(double n){  return 1.0 / n;             }
double f4(double n){  return pow(n, log2(n));     }
double f5(double n){  return 100 * n * n + 6 * n; }
double f6(double n){  return pow(n, 0.51);        }
double f7(double n){  return n * n - 324;         }
double f8(double n){  return 50 * pow(n, 0.5);    }
double f9(double n){  return 2 * pow(n, 3);       }
double f10(double n){ return pow(3, n);           }
double f11(double n){ return pow(2, 32) * n;      }
double f12(double n){ return log2(n);             }

int main(){

    const char* names[NUM_FUNCS] = 
    {
        "n log n", "12 sqrt(n)", "1/n", "n^(log2 n)",
        "100n^2 + 6n", "n^0.51", "n^2 - 324", "50 sqrt(n)",
        "2n^3", "3^n", "2^32 n", "log2 n"
    };

    GrowthFunc funcs[NUM_FUNCS]={f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12};

    double n=100000;
    int idx[NUM_FUNCS];
    for (int i = 0; i < NUM_FUNCS; i++) idx[i] = i;

    // Sort at n
    for (int i = 0; i < NUM_FUNCS - 1; i++) {
        for (int j = 0; j < NUM_FUNCS - 1 - i; j++) {
            if (funcs[idx[j]](n) > funcs[idx[j+1]](n)) {
                int tmp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = tmp;
            }
        }
    }

    printf("Functions in increasing order of growth (for n = %.0f):\n", n);
    for (int i = 0; i < NUM_FUNCS; i++) { 
        printf("%2d. %-12s %.2e\n", i+1, names[idx[i]], funcs[idx[i]](n));
    }

    // Check Θ-equivalent pairs using ratio at two different n values
    printf("\nTheta-equivalent pairs(approx. check):\n");
    double n1 = 10000, n2 = 1000000;  // two test points

    for (int i = 0; i < NUM_FUNCS; i++) {
        for (int j = i + 1; j < NUM_FUNCS; j++) {
            double v1i = funcs[idx[i]](n1);
            double v1j = funcs[idx[j]](n1);
            double v2i = funcs[idx[i]](n2);
            double v2j = funcs[idx[j]](n2);

            if (v1j != 0 && v2j != 0) {
                double r1 = v1i / v1j;
                double r2 = v2i / v2j;

                if (r1 > 0 && isfinite(r1) && r2 > 0 && isfinite(r2)) {
                    double ratio = (r1 > r2) ? r1 / r2 : r2 / r1;
                    if (ratio < 2.0) {
                        printf("%s and %s are Theta of each other (ratios %f , %f)\n",names[idx[i]], names[idx[j]], r1, r2);
                    }
                }
            }
        }
    }

    return 0;
}
