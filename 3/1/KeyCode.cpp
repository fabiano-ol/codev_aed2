#include <stdio.h>
#include <stdlib.h>

long long int Fib(int n) {
	long long int * M = (long long int *) malloc(sizeof(long long int) * (n + 1));
	
	for(int i = 0; i <= n; i++){
		M[i] = -1;
		if(i <= 2){
			M[i] = 1;
		} else {
			M[i] = M[i-1] + M[i-2];
		}
	}
	
	long long int r = M[n];
	free(M);
	
	return r;
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", Fib(n));
	}
}