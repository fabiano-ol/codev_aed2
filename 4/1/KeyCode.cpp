#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

using namespace std;

long long int SelAtividades(long long int * A, int n){
	long long int sMax = A[0]; //Maior soma de elementos contíguos considerando somente os primeiros i-1 elementos de A
	long long int sI = A[0];   //Maior soma de elementos contíguos que terminam em i
	
	for (int i = 1; i < n; i++){
		sI = max(sI + A[i],A[i]);
		sMax = max(sMax, sI);
	}
	
	return sMax;
}


int main() {
	int n; 
	long long int * A; 
	while (scanf("%d", &n)>0) {
		if (n>=0) { 
			A = (long long int *) malloc(sizeof(long long int) * n);
			for(int i = 0; i < n; i++){
				scanf("%d", &A[i]);
			} 
			printf("%d\n", SelAtividades(A, n));
		}
	}
	free(A);
}
