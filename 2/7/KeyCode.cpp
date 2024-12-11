#include <stdio.h>
#include <stdlib.h>

// codevremove
void DivisaoJogadoresBK(int n, int d, int grupo1[], int grupo2[], int n1, int n2, bool &achouSolucao) {
    if (d == n) {
        if (n1 > 0 && n2 > 0 && (n1 < n2 || grupo1[0] < grupo2[0])) {
            if (achouSolucao) {
                printf(";");
            }
            achouSolucao = true;
            printf("(");
            for (int j = 0; j < n1; j++) {
                if (j > 0) {
                    printf(",");
                }
                printf("%d", grupo1[j]);
            }
            printf("/");
            for (int j = 0; j < n2; j++) {
                if (j > 0) {
                    printf(",");
                }
                printf("%d", grupo2[j]);
            }
            printf(")");
        }
    } else {
        if (n1 < n/2) {
            grupo1[n1] = d + 1;
            DivisaoJogadoresBK(n, d + 1, grupo1, grupo2, n1 + 1, n2, achouSolucao);
        }

        grupo2[n2] = d + 1;
        DivisaoJogadoresBK(n, d + 1, grupo1, grupo2, n1, n2 + 1, achouSolucao);
    }
}
// codevremove

void DivisaoJogadores(int n) {
    // codev
    int * grupo1 = (int *) malloc(sizeof(int) * (n/2));
    int * grupo2 = (int *) malloc(sizeof(int) * n);
    bool achouSolucao = false;

    DivisaoJogadoresBK(n, 0, grupo1, grupo2, 0, 0, achouSolucao);
    printf("\n");
    // codev
}

int main() {
    int n;
	while (scanf("%d", &n)>0) {
        DivisaoJogadores(n);
	}
}
