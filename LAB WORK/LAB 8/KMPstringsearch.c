#include <stdio.h>
#include <string.h>

void computeLPS(char *pat, int m, int *lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
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

void KMPSearch(char *pat, char *txt) {
    int m = strlen(pat);
    int n = strlen(txt);
    int lps[m];
    computeLPS(pat, m, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    char txt[1000], pat[1000];
    scanf("%s", txt);
    scanf("%s", pat);
    KMPSearch(pat, txt);
    return 0;
}
