#include <stdio.h>
#include <stdlib.h>

long long int Trocos(int T, int * M, int N) {
	//T é o troco necessário total que retorne
	//M[1..N] são as moedas diferentes. e.G: [1,5,10,25,50,100]
	//retorna o número de trocos de valor T com tais moedas
	
	int Mem[T+2][N+1];
	
	for(int n = 0; n <= N; n++){
		Mem[0][n] = 0;
		Mem[1][n] = 1;
	}
	
	for(int t = 1; t <= T+1; t++){
		Mem[t+1][0] = 0;
	}
	
	for (int t = 1; t <= T+1; t++){
		for(int n = 1; n <= N; n++){
			printf("Moeda sendo usada: %d\n", M[n-1]);
			int maiorValor = t - M[n] >= 0 ? t - M[n] : 0;
			Mem[t+1][n] = Mem[t+1][n-1] + Mem[maiorValor][n];
			
			printf("Mem[%d][%d]: %d\n", t+1, n, Mem[t+1][n]);
		}
	}
	
	return Mem[T+1][N];
	
	//Solução sem programação dinâmica
	/*if(T < 0 || N == 0){
		return 0;
	} 
	
	if(T == 0){
		return 1;
	}
	
	return Trocos(T, M, N-1) + Trocos(T-M[N-1], M, N);*/
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
