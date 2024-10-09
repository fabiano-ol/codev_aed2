#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

using namespace std;


int Cobertura(double * A, int n){
	// codev
	int quantidadeIntervalos = 0;
	int i = 1;

	while (i <= n) {
		// Criaremos o intervalo [A[i], A[i]+1] para cobrir o ponto A[i]
		quantidadeIntervalos++;
		double limiteSuperior = A[i] + 1;
		while (i <= n && A[i] <= limiteSuperior) {
			i++;
		}
	}

	return quantidadeIntervalos;
	// codev
}

int main() {
	int n; 
	double * A; 
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;
		if (testeDeCarga) {
			n = 1000000;
		}
		A = (double *) malloc(sizeof(double) * (n+1));
		for(int i = 0; i < n; i++){
			if (testeDeCarga) {
				A[i+1] = i % 2 == 0 ? i : i - 0.5;
			} else {
				scanf("%lf", &A[i]);
			}
		} 
		printf("%d\n", Cobertura(A, n));
		free(A);
	}
	return 0;
}
