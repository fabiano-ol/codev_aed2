#include <stdio.h>
#include <stdlib.h>

// codevremove
void SomaBK(int n, int P[], int k, int soma) {
    if (soma == n) {
        printf("[");
        for (int i = 1; i <= k; i++) {
            if (i > 1) {
                printf("+");
            }
            printf("%d", P[i]);
        }
        printf("]");
    } else {
        for (int i = (k > 0 ? P[k] : 0) + 1; i <= n - soma; i++ ){
            P[k+1] = i;
            SomaBK(n, P, k + 1, soma + i);
        }
    }
}
// codevremove

void Soma(int n) {
    // codev
    int *P = (int *) malloc(sizeof(int) * (n + 1));
    SomaBK(n, P, 0, 0);
    printf("\n");
    free(P);
    // codev
}

int main() {
    int n;
    while (scanf("%d", &n)>0) {
        Soma(n);
    }
    return 0;
}
