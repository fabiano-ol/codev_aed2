#include <stdio.h>
#include <stdlib.h>

#define LINHAS 7
#define COLUNAS 8
#define NUMERO_PECAS 28

// codevremove
bool DominoBK(int **T, int **P, bool **U, int linha, int coluna) {
    if (linha == LINHAS + 1) {
        return true;
    }

    int f1 = T[linha][coluna];
    bool r;

    if ( coluna < COLUNAS && P[linha][coluna+1] == -1) {
        int f2 = T[linha][coluna+1];
        if (!U[f1][f2]) {
            U[f1][f2] = true; U[f2][f1] = true; 
            P[linha][coluna] = f1;
            P[linha][coluna+1] = f2;

            if ( coluna < COLUNAS - 1) {
                r = DominoBK(T,P,U,linha,coluna+2);
            } else {
                r = DominoBK(T,P,U,linha+1,1);
            }

            U[f1][f2] = false; U[f2][f1] = false;
            P[linha][coluna] = -1;
            P[linha][coluna+1] = -1;

            if (r) {
                return true;
            }
        }
    }

    if ( linha < LINHAS ) {
        int f2 = T[linha+1][coluna];
        if (!U[f1][f2]) {
            U[f1][f2] = true; U[f2][f1] = true;
            P[linha][coluna] = f1;
            P[linha+1][coluna] = f2;

            if ( coluna < COLUNAS) {
                r = DominoBK(T,P,U,linha,coluna+1);
            } else {
                r = DominoBK(T,P,U,linha+1,1);
            }

            U[f1][f2] = false; U[f2][f1] = false;
            P[linha][coluna] = -1;
            P[linha][coluna+1] = -1;

            if (r) {
                return true;
            }
        }
    }

    return false;
}
// codevremove

bool Domino(int** T) {
    // codev
    int **P = (int **) malloc(sizeof(int *) * (LINHAS + 1));
    for (int i = 1; i <= LINHAS; i++) {
        P[i] = (int *) malloc(sizeof(int) * (COLUNAS + 1));
    }

    for (int i = 1; i <= LINHAS; i++) {
        for (int j = 1; j <= COLUNAS; j++) {
            P[i][j] = -1; // Inicializa as peças como não usadas
        }
    }

    bool **U = (bool **) malloc(sizeof(bool *) * 7);
    for (int i = 0; i < 7; i++) {
        U[i] = (bool *) malloc(sizeof(bool) * 7);

        for (int j = 0; j < 7; j++) {
            U[i][j] = false;
        }
    }

    bool r = DominoBK(T, P, U, 1, 1);

    for (int i = 1; i <= LINHAS; i++) {
        free(P[i]);
    }
    free(P);

    for (int i = 0; i < 7; i++) {
        free(U[i]);
    }
    free(U);

    return r;

    // codev
}

int main() {
    int n = 28; // Número de peças do dominó
    scanf("%d", &n);
    int **T = (int **) malloc(sizeof(int *) * (LINHAS + 1));

    for (int i = 1; i <= LINHAS; i++) {
        T[i] = (int *) malloc(sizeof(int) * (COLUNAS + 1));
    }

    while (n > 0) {
        for(int i = 1; i <= LINHAS; i++) {
            char C[COLUNAS + 2];
            scanf("%s", C);
            for (int j = 1; j <= COLUNAS; j++) {
                T[i][j] = C[j-1] - '0';
            }
        }
        if (Domino(T)) {
            printf("V\n");
        } else {
            printf("F\n");
        }

        n--;
    }

    for (int i = 1; i <= LINHAS; i++) {
        free(T[i]);
    }
    free(T);

    return 0;
}
