#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int SCM(int * S, int n) {
	int * Mem = (int *) malloc(sizeof(int) * (n));

	for (int i = 0; i < n; i++) {
		Mem[i] = 1;
	}

	int tamanhoMaximo = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (S[i] > S[j]) {
				Mem[i] = max(Mem[i], Mem[j] + 1);
			}
		}
		tamanhoMaximo = max(tamanhoMaximo, Mem[i]);
	} 

	return tamanhoMaximo;
}

int main() {
	int n;
	int * S = NULL;
	
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;

		if (testeDeCarga) {
			n = 1000;
		}

		S = (int *) malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++) {
			if (testeDeCarga) {
				S[i] = i;
			} else {
				scanf("%d", &S[i]);
			}
		}
		
		printf("%d\n", SCM(S, n));
		free(S);
	}
	
	return 0;
}
