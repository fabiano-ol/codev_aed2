#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int MaxSubsum(int * A, int n){
	// codev
	int sMax = A[1]; //Maior soma de elementos contíguos considerando somente os primeiros i-1 elementos de A
	int sMaxT = A[1];   //Maior soma de elementos contíguos que terminam em i
	
	for (int i = 2; i <= n; i++){
		sMaxT = max(sMaxT + A[i], A[i]);
		sMax = max(sMax, sMaxT);
	}
	
	return sMax;
	// codev
}

int main() {
	int n; 
	int * A; 
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;
		if (testeDeCarga) {
			n = 1000000;
		}
		A = (int *) malloc(sizeof(int) * n);
		for(int i = 1; i <= n; i++){
			if (testeDeCarga) {
				A[i] = i % 5 == 0 ? 5 : -1;
			} else {
				scanf("%d", &A[i]);
			}
		} 
		printf("%d\n", MaxSubsum(A, n));
		free(A);
	}
	return 0;
}