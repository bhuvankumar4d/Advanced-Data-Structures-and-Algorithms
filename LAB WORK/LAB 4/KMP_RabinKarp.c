#include <stdio.h>
#include <string.h>
#define d 256
#define q 101

void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char* pat, char* txt) {
    int M = strlen(pat), N = strlen(txt);
    int lps[M], i = 0, j = 0;
    computeLPSArray(pat, M, lps);
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("KMP Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

void RabinKarp(char* pat, char* txt) {
    int M = strlen(pat), N = strlen(txt);
    int i, j, p = 0, t = 0, h = 1;
    for (i = 0; i < M - 1; i++) h = (h * d) % q;
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) if (txt[i + j] != pat[j]) break;
            if (j == M) printf("Rabin-Karp Pattern found at index %d\n", i);
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    gets(txt);
    printf("Enter pattern: ");
    gets(pat);
    KMP(pat, txt);
    RabinKarp(pat, txt);
    return 0;
}
