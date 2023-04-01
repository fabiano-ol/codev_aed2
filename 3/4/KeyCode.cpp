#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long int JogoPalito(int n, int j, long long int ** M)  {
	if(M[n][j] == -1) {
		for (int i = 1; i <= min(3, n); i++) {
			long long int jv = JogoPalito(n-i, 3-j, M);
			if (jv == j) {
				M[n][j] = j;
				return M[n][j];
			}
		}
		M[n][j] = 3-j;
	}
	
	return M[n][j];
}

int main() {
	int n; //Número de palitos inicial
	int j; //Número do jogador que vai começar (1 ou 2)
	long long int ** M; //Vetor de memorização
	
	while (scanf("%d", &n)>0) {
		scanf("%d", &j);
		M = (long long int **) malloc(sizeof(long long int *) * (n + 1));
		
		for (int i = 0; i <= n; i++) {
			M[i] = (long long int *) malloc(sizeof(long long int) * 3);
			for(int j = 0; j <= 2; j++) {
				M[i][j] = -1;
			}
		}
		printf("Vencedor: %lld\n", JogoPalito(n, j, M));
	}
	
	free(M);
}