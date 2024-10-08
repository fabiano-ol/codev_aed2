#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits>

using namespace std;

// t = troco a ser dado
// M[0..n] são as moedas disponíveis (ordenadas)
// retorna o menor número de moedas para dar troco T
long long int TrocoMin(int T, int* M, int n)  {
	// codev
	long long int ** Mem = (long long int **) malloc(sizeof(long long int*) * (T+1));
	for (int i = 0; i <= T; i++) {
		Mem[i] = (long long int*) malloc(sizeof(long long int) * (n+1));
		for (int j = 0; j <= n; j++) {
			Mem[i][j] = -1;
		}
	}
	
	for (int t = 0; t <= T; t++) {
		for (int j = 0; j <= n; j++) {
			// Determinar o valor TrocoMin(t, M, j), ou seja, o valor Mem[t][j]
			if(t == 0) {
				Mem[t][j] = 0;
			} else {
				float dMin = numeric_limits<float>::infinity();
				for (int i = j; i > 0; i--) {
					if (M[i] <= t) {
						long long int d = 1 + Mem[t-M[i]][i];
						if(dMin > d) {
							dMin = d;
						}
					}
				}
				Mem[t][j] = dMin;
			}
		}
	}
	
	return Mem[T][n];
	// codev
}

int main() {
	int n;
	int t;
	int * M;
	
	while (scanf("%d", &t)>0) {
		bool testeDeCarga = t == -1;

		if (testeDeCarga) {
			t = 2500;
			n = 500;
		} else {
			scanf("%d", &n);
		}
		
		M = (int *) malloc(sizeof(int) * (n + 1));

		for (int i = 1; i <= n; i++) {
			if(testeDeCarga) {
				M[i] = i;
			} else {
				scanf("%d", &M[i]);
			}
		}

		printf("%lld\n", TrocoMin(t, M, n));
		free(M);
	}
	
}