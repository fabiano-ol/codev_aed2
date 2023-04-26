#include <stdio.h>
#include <stdlib.h>


int BuscaBinaria(int * T, int ini, int fim, int x){
	int m = 0;
	if(ini > fim){
		return ini;
	} else {
		m = (ini + fim) / 2;
		if(T[m] < x){
			return BuscaBinaria(T, m + 1, fim, x);
		} else {
			return BuscaBinaria(T, ini, m - 1, x);
		}
	}
}

long long int SCMt(int * S, int n, int * T) {
	//n = 0
	
	int m = 0;
	if(T[n] == -1){
		m = 1;
		for(int i = 0; i < n-1; i++){
			if(S[i] < S[n]){
				printf("S[%d]: %d\n", i, S[i]);
				long long int scmt = SCMt(S, i, T);
				m = m > (scmt + 1) ? m : (scmt + 1);
			}
		}
		T[n] = S[n];
	}
	return T[n];
}

long long int SCM(int * S, int n) {
	int m = 0;
	int T[100000];
	
	for(int i = 0; i < 100000; i++){
		T[i] = -1;
	}
	
	for(int i = 1; i < n; i++){
		long long int scmt = SCM(S, i, T);
		m = m > scmt ? m : scmt;
	}

	
	return m;
}

int main() {
	int n;
	int * S = NULL;
	
	while (scanf("%d", &n)>0) {
		S = (int *) malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &S[i]);
		}
		
		printf("%lld\n", SCM(S, n));
		free(S);
		
	}
	
	return 0;
}
