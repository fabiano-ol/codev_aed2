#include <stdio.h>
#include <stdlib.h>

// codevremove
void RotaCidadesBK(int **D, int *P, int n, int k, int dP, int &mindP, int *minP, bool *U) {
    if (k == n) {
        if (D[P[n]][1] != -1) {
            dP += D[P[n]][1];
            if (dP < mindP) {
                mindP = dP;
                for (int i = 1; i <= n; i++) {
                    minP[i] = P[i];
                }
            }
        }
        return;
    }

    for( int i = 2; i <= n; i++) {
        if (D[P[k]][i] != -1 && !U[i]) {
            U[i] = true;
            P[k+1] = i;
            RotaCidadesBK(D, P, n, k + 1, dP + D[P[k]][i], mindP, minP, U);
            U[i] = false;
        }
    }
}
// codevremove

int RotaCidades(int** D, int* minP, int n) {
    // codev
    int mindP = 1000000;
    int *P = (int *) malloc(sizeof(int) * (n+1));
    bool *U = (bool *) malloc(sizeof(bool) * (n+1));
    P[1] = 1;
    for (int i = 1; i <= n; i++) {
        U[i] = false;
    }
    U[1] = true;
    RotaCidadesBK(D, P, n, 1, 0, mindP, minP, U);
    free(P);
    free(U);
    return mindP;
    // codev
}

int main() {
    int n; // Cidades
    while (scanf("%d", &n)>0) {
        int *minP = (int *) malloc(sizeof(int) * (n+1));
        minP[1] = 1;

        int **D = (int **) malloc(sizeof(int *) * (n+1));
        for (int i = 1; i <= n; i++) {
            D[i] = (int *) malloc(sizeof(int) * (n+1));
        }
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                D[i][j] = -1;
            }
        }

        int e;
        scanf("%d", &e); // Número de estradas

        int x, y, z;
        for(int i = 1; i <= e; i++) {
            scanf("%d %d %d", &x, &y, &z); // Distancia entre x e y = z
            D[x][y] = z; D[y][x] = z;
        }

        int d = RotaCidades(D, minP, n);
        printf("Distancia = %d, Rota =", d);
        for (int i = 1; i <= n; i++) {
            printf(" %d", minP[i]);
        }
        printf("\n");

        for (int i = 1; i <= n; i++) {
            free(D[i]);
        }
        free(D);
        free(minP);
    }

    return 0;
}
