#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// codevremove
void TrocoMinBK(int t, int M[], int n, int P[], int d, int &dMin, int somaAtual) {
    // t = Troco a ser dado
    // M[1..n] = moedas disponíveis (ordenadas)
    // P[i] = valor da i-ésima moeda escolhida para o troco
    // d = número de moedas escolhidas para o troco
    // P = [25, 10, 1, 1], d = 4
    
    if (somaAtual == t) {
        if (dMin > d) {
            dMin = d;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (somaAtual + M[i] <= t && (d == 0 || M[i] >= P[d])) {
                P[d+1] = M[i];
                TrocoMinBK(t, M, n, P, d+1, dMin, somaAtual + M[i]);
            }
        }
    }
}
// codevremove

void TrocoMin(int t, int M[], int n) {
    // codev
    int * P;
    int dMin = t;

    P = (int *) malloc(sizeof(int) * (t + 1));

    TrocoMinBK(t, M, n, P, 0, dMin, 0);
    printf("%d\n", dMin);

    free(P);
    // codev
}

int main() {
    int n;
	int t;
	int * M;
	
	while (scanf("%d", &t)>0) {
        scanf("%d", &n);
		
		M = (int *) malloc(sizeof(int) * (n + 1));

		for (int i = 1; i <= n; i++) {
            scanf("%d", &M[i]);
		}

		TrocoMin(t, M, n);
		free(M);
	}
}
