#include <stdio.h>
#include <stdlib.h>


int DiferencaMinimaBiparticoes(int n, int* S) {
	// codev
	int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        total_sum += S[i];
    }

    // Definindo o tamanho de j (pode ir de -total_sum até total_sum)
    int offset = total_sum; // necessário para manipular índices negativos
    int max_j = 2 * total_sum + 1;

	bool ** Mem = (bool **) malloc(sizeof(bool *) * (n+1));
	for (int i = 0; i <= n; i++) {
		Mem[i] = (bool *) malloc(sizeof(bool) * (max_j));
	}
	for (int j = 0; j < max_j; j++) {
        Mem[0][j] = false; 		// Com 0 elementos, não é possível obter uma soma positiva
    }
	Mem[0][offset] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < max_j; j++) {
			bool primParc = j-S[i] < 0 ? false : Mem[i-1][j-S[i]];
			bool segParc = j+S[i] > (total_sum * 2) ? false : Mem[i-1][j+S[i]];

			Mem[i][j] = primParc || segParc;
        }
    }

	int min_diff = total_sum;
    for (int j = 0; j <= total_sum; j++) {
        if (Mem[n][offset + j] || Mem[n][offset - j] ) {
            min_diff = j;
            break;
        }
    }

    for (int i = 0; i <= n; i++) {
        free(Mem[i]);
    }
    free(Mem);

    return min_diff;
	// codev
}

int main() {
	int n;
	int * S;
	
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;

		if (testeDeCarga) {
			n = 1001;
		}

		S = (int *) malloc(sizeof(int) * (n+1));

		for(int i = 1; i <= n; i++) {
			if (testeDeCarga) {
				S[i] = 1;
			} else {
				scanf("%d", &S[i]);
			}
		}
		
		printf("%d\n", DiferencaMinimaBiparticoes(n, S));
		free(S);
	}
	
	return 0;
}
