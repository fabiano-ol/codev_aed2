#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long int Tmin(int n, int ** t, int ** e)  {
	// codev
	//Tempo mínimo de chegar na linha l e na estação n
	// t[i,j], 1 <= i <= 2; 1 <= j <= n
	// e[i,j], 1 <= i <= 2; 1 <= j <= n
	
	long long int ** M = (long long int **) malloc(sizeof(long long int *) * 2);
	for(int i = 0; i <= 1; i++) {
		M[i] = (long long int *) malloc(sizeof(long long int) * n + 1);
	} 
	
	for(int j = 0; j < n; j++){
		for(int i = 1; i <= 2; i++){
			if(j == 0){
				M[i-1][j] = 0;
			} else {
				int tempoEsteira1 = M[i-1][j-1] + t[i-1][j-1];
				int tempoEsteira2 = M[3-i-1][j-1] + t[3-i-1][j-1] + e[3-i-1][j-1]; //Só funciona para 2 esteiras
				M[i-1][j] = min(tempoEsteira1, tempoEsteira2);
			}	
		}
	}
	
	long long int r = min(M[0][n-1] + t[0][n-1], M[1][n-1] + t[1][n-1]);
	
	for(int i = 0; i <= 1; i++) {
		free(M[i]);
	} 
	free(M);
	
	return r;
	// codev
}

int main() {
	int n; //Número de estações de montagem em 1 linha
	int ** t; //Tempo de processamento de cada máquina das esteiras
	int ** e; //Tempo da troca entre as linhas de montagem (1 -> 2 e 2 -> 1)
	
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;
		if (testeDeCarga) {
			n = 200000;
		}

		t = (int **) malloc(sizeof(int *) * 2);
		e = (int **) malloc(sizeof(int *) * 2);
		for (int i = 0; i < 2; i++){
			t[i] = (int *) malloc(sizeof(int) * n);
			e[i] = (int *) malloc(sizeof(int) * n);
		}
		
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < n; j++){
				if (!testeDeCarga) {
					scanf("%d", &t[i][j]);
				} else {
					if (i == 0) {
						if (j % 2 == 0) {
							t[i][j] = 1;
						} else {
							t[i][j] = 1000;
						}
					} else {
						if (j % 2 == 0) {
							t[i][j] = 1000;
						} else {
							t[i][j] = 1;
						}
					}
				}
			}
		}
		
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < n-1; j++){
				if (!testeDeCarga) {
					scanf("%d", &e[i][j]);
				} else {
					e[i][j] = 1;
				}
			}
		}
		
		printf("%lld\n", Tmin(n, t, e));
	}
	
	free(t);
	free(e);
}