#include <stdio.h>
#include <stdlib.h>

long long int Trocos(int T, int * M, int N) {
	//T é o troco necessário total que retorne
	//M[1..N] são as moedas diferentes. e.G: [1,5,10,25,50,100]
	//retorna o número de trocos de valor T com tais moedas
	
	long long int ** Mem = (long long int **) malloc(sizeof(long long int *) * (T + 3));
	for(int i = 0; i <= (T + 2); i++) {
		Mem[i] = (long long int *) malloc(sizeof(long long int) * (N + 2));
	}
	
	for(int n = 0; n <= N; n++){
		Mem[0][n] = 0;
		Mem[1][n] = 1;
	}
	
	for(int t = 1; t <= T; t++){
		Mem[t+1][0] = 0;
	}
	
	for (int t = 1; t <= T; t++){
		for(int n = 1; n <= N; n++){
			int maiorValor = t - M[n-1] >= 0 ? t - M[n-1] : -1;
			Mem[t+1][n] = Mem[t+1][n-1] + Mem[maiorValor+1][n];
		}
	}
	
	long long int r = Mem[T+1][N];
	
	for(int i = 0; i <= (T + 2); i++) {
		free(Mem[i]);
	}
	free(Mem);
	
	return r;
}

int main() {
	int T;
	int N;
	int * M = NULL;
	
	while (scanf("%d", &T)>0) {
		scanf("%d", &N);
		M = (int *) malloc(sizeof(int) * N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &M[i]);
		}
		
		printf("%lld\n", Trocos(T, M, N));
		free(M);
	}
}
