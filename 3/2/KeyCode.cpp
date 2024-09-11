#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long int Trocos(int T, int * M, int N) {
	//T é o troco necessário total que retorne
	//M[1..N] são as moedas diferentes. e.G: [1,5,10,25,50,100]
	//retorna o número de possíveis trocos de valor T com tais moedas
	
	long long int ** Mem = (long long int **) malloc(sizeof(long long int *) * (T + 1));
	for(int i = 0; i <= T; i++) {
		Mem[i] = (long long int *) malloc(sizeof(long long int) * (N + 1));
	}
	
	for(int n = 0; n <= N; n++){
		Mem[0][n] = 1;
	}
	
	for(int t = 1; t <= T; t++){
		Mem[t][0] = 0;
	}
	
	for (int t = 1; t <= T; t++){
		for(int n = 1; n <= N; n++){
			int restoDoTroco = t - M[n-1];
			if (restoDoTroco < 0) {
				Mem[t][n] = Mem[t][n-1];
			} else {
				Mem[t][n] = Mem[t][n-1] + Mem[restoDoTroco][n];
			}
		}
	}
	
	long long int r = Mem[T][N];
	
	for(int i = 0; i <= T; i++) {
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
		bool testeDeCarga = T == -1;
		if (testeDeCarga) {
			T = 1000;
			N = 1000;
			M = (int *) malloc(sizeof(int) * N);
			M[0] = 1;
			for(int i = 1; i < N; i++) {
				M[i] = 999;
			}
		} else {
			scanf("%d", &N);
			M = (int *) malloc(sizeof(int) * N);
			for(int i = 0; i < N; i++) {
				scanf("%d", &M[i]);
			}
		}
		
		printf("%lld\n", Trocos(T, M, N));
		free(M);
	}
}
