 #include <stdio.h>
#include <stdlib.h>

long long int SelAtividades(int * A, int n){
	int sMax = A[0]; //Maior soma de elementos contíguos considerando somente os primeiros i-1 elementos de A
	int sI = A[0];   //Maior soma de elementos contíguos que terminam em i
	
	for (int i = 1; i < n; i++){
		sI = sI + A[i] > A[i] ? sI + A[i] : A[i];
		sMax = sMax > sI ? sMax : sI;
	}
	
	return sMax;
}


int main() {
	int n; int ** A; 
	while (scanf("%d", &n)>0) {
		if (n>=0) { 
			A = (int *) malloc(sizeof(int) * n);
			for(int i = 0; i < n; i++){
				scanf("%d", &A[i]);
			} 
			printf("%d\n", SelAtividades(A, n));
			free(A);
		}
	}
	return 0;
}
