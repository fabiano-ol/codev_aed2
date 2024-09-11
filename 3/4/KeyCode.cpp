#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int JogoPalito(int n, int ** M)  {
	// codev
	int N = n;
	for (n = 0; n <= N; n++) {
		for (int j = 1; j <= 2; j++) {
			for (int i = 1; i <= min(3, n); i++) {
				int jv = M[n-i][3-j];
				if (jv == -1) {
					M[n][j] = i;
				} 
			}
		}
	}
	return M[N][1];
	// codev
}

int main() {
	int n; //Número de palitos inicial
	int ** M;
	
	while (scanf("%d", &n)>0) {
		M = (int **) malloc(sizeof(int *) * (n + 1));
		
		for (int i = 0; i <= n; i++) {
			M[i] = (int *) malloc(sizeof(int) * 3);
			for(int j = 0; j <= 2; j++) {
				M[i][j] = -1;
			}
		}
		printf("%d\n", JogoPalito(n, M));
	}
	
	free(M);
}