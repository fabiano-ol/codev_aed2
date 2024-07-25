#include <stdio.h>
#include <stdlib.h>
#include <cstring>  
#include <algorithm>

#define MAX_SIZE_CHAR 100000

using namespace std;

//Solução utilizando recursão (ineficiente)
long long int DistanciaEdicao(char *A, int n, char *B, int m) {
	if(n == 0 || m == 0){
		return n > m ? n : m;
	} else {
		if(A[n-1] == B[m-1]){
			return DistanciaEdicao(A, n-1, B, m-1);
		} else {
			long long int valorSubstituicao = DistanciaEdicao(A, n-1, B, m-1) + 1;
			long long int valorDelecao = DistanciaEdicao(A, n-1, B, m) + 1;
			long long int valorInsercao = DistanciaEdicao(A, n, B, m-1) + 1;
			
			//Retorna o menor dos 3 valores
			return min(min(valorSubstituicao, valorDelecao), valorInsercao);
		}
	}
}

//Solução utilizando programação dinâmica
long long int DistanciaEdicaoPD(char *A, int n, char *B, int m) {
	long long int ** Mem = (long long int **) malloc(sizeof(long long int *) * (n + 1));
	for(int i = 0; i <= n; i++) {
		Mem[i] = (long long int *) malloc(sizeof(long long int) * (m + 1));
	}
	
	for(int i = 0; i <= m; i++) {
		Mem[0][i] = i;
	}
	
	for(int i = 0; i <= n; i++) {
		Mem[i][0] = i;
	}
	
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(A[i-1] == B[j-1]){
				Mem[i][j] = Mem[i-1][j-1];
			} else {
				long long int valorSubstituicao = Mem[i-1][j-1] + 1;
				long long int valorDelecao = Mem[i-1][j] + 1;
				long long int valorInsercao = Mem[i][j-1] + 1;
				
				//Retorna o menor dos 3 valores
				Mem[i][j] = min(min(valorSubstituicao, valorDelecao), valorInsercao);
			}
		}
	}
	
	long long int r = Mem[n][m];
	
	for(int i = 0; i <= n; i++) {
		free(Mem[i]);
	}
	free(Mem);
	
	return r;
}

int main() {
	int n = 0;
	int m = 0;
	char * A = (char *) malloc(sizeof(char) * MAX_SIZE_CHAR);
	char * B = (char *) malloc(sizeof(char) * MAX_SIZE_CHAR);
	
	while (scanf("%s", A)>0) {
		scanf("%s", B);
		
		if(A[0] == '-') A[0] = '\0';
		if(B[0] == '-') B[0] = '\0';
		
		n = (int) strlen(A);
		m = (int) strlen(B);
		
		printf("%lld\n", DistanciaEdicaoPD(A, n, B, m));
	}
	
	free(A);
	free(B);
}