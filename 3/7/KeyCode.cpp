#include <stdio.h>
#include <stdlib.h>

bool SomaSubconjunto(int A, int n, int * S) {
	// codev

	// Mem[i][j] = true se existe um subconjunto de S[1..i] com soma igual a j
	// Queremos saber o valor do Mem[n][A]
	// Mem[n][A] = Mem[n-1][A], caso o elemento S[n] não for tomado
	// Mem[n][A] = Mem[n-1][A-S[n]], caso o elemento S[n] seja tomado
	// Mem[n][A] = Mem[n-1][A] || Mem[n-1][A-S[n]]
	// Caso A-S[n] seja negativo, a segunda parcela é falsa

	bool** Mem = (bool**) malloc(sizeof(bool*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		Mem[i] = (bool *) malloc(sizeof(bool) * (A + 1));
	}

	 for (int i = 0; i <= n; i++) {
        Mem[i][0] = true;
    }
    for (int j = 1; j <= A; j++) {
        Mem[0][j] = false;
    }
	
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= A; j++) {
            if (j < S[i]) {
                Mem[i][j] = Mem[i-1][j];
            } else {
                Mem[i][j] = Mem[i-1][j] || Mem[i-1][j-S[i]];
            }
        }
	}

	bool retorno = Mem[n][A];

    for (int i = 0; i <= n; i++) {
        free(Mem[i]);
    }
    free(Mem);

    return retorno;
	// codev
}

int main() {
	int n;
	int * S = NULL;
	int A;
	
	while (scanf("%d", &A)>0) {
		bool testeDeCarga = A == -1;

		if (testeDeCarga) {
			A = 1000 * 1001 / 2;
			n = 1000;
		} else {
			scanf("%d", &n);
		}
		
		S = (int *) malloc(sizeof(int) * (n+1));
		for(int i = 1; i <= n; i++) {
			if (testeDeCarga) {
				S[i] = i;
			} else {
				scanf("%d", &S[i]);
			}
		}
		
		printf("%d\n", SomaSubconjunto(A, n, S) ? 1 : 0);
		free(S);
	}
	
	return 0;
}
