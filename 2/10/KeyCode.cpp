#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// codevremove
void PermutDistBK(int n, int B[], int P[], int d, int Pids[]) {
    // n = Número de elementos
    // B[i] = i-ésimo elemento (1 a n)
    // P[i] = i-ésimo elemento da permutação (1 a n)
    // d = número de elementos já escolhidos para permutação
    // Pids[i] = posição de B correspondendo ao i-ésimo elemento da permutação (1 a n)
    // Serão consideradas como válidas as permutações nas quais as posições dos elementos repetidos ocorrem em ordem crescente

    if (d == n) {
        printf("[");
        for (int i = 1; i <= n; i++) {
            if(i > 1) {
                printf(",");
            }
            printf("%d", P[i]);
        }
        printf("]");
    } else {
        for (int i = 1; i <= n; i++) {
            bool pular = false;
            for (int j = 1; j <= d; j++) {
                if (B[i] == P[j] && i <= Pids[j]) {
                    pular = true;
                    break;
                }
            }
            if (!pular) {
                P[d+1] = B[i];
                Pids[d+1] = i;
                PermutDistBK(n, B, P, d + 1, Pids);
            }
        }
    }
}
// codevremove

void PermutDist(int n, int B[]) {
    // codev
    int * P = (int *) malloc(sizeof(int) * (n + 1));
    int * Pids = (int *) malloc(sizeof(int) * (n + 1));

    PermutDistBK(n, B, P, 0, Pids);
    printf("\n");
    free(P);
    free(Pids);
    // codev
}

int main() {
    int n;
	int * B;
	
	while (scanf("%d", &n)>0) {
		B = (int *) malloc(sizeof(int) * (n + 1));

        for (int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
        }

		PermutDist(n, B);
		free(B);
	}

    return 0;
}
