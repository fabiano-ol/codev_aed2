#include <stdio.h>
#include <stdlib.h>

long long int Fib(int n) {
	long long int M[n];
	for(int i = 0; i <= n; i++){
		M[i] = -1;
		if(i <= 2){
			M[i] = 1;
		} else {
			M[i] = M[i-1] + M[i-2];
		}
	}
	return M[n];
}

int main() {
	int n;
	while (scanf("%d", &n)>0) {
		printf("%lld\n", Fib(n));
	}
}