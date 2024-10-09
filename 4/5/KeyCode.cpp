#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

using namespace std;

int JogoPalito(int n, int j){
	// codev
	if (n % 4 == 0) {
		return 3 - j;
	} else {
		return j;
	}
	// codev
}


int main() {
	int n; // Número de palitos iniciais
	int j; // 1 ou 2 número do jogador
	while (scanf("%d", &n)>0) {
		if (n>=0) { 
			scanf("%d", &j);
			printf("%d\n", JogoPalito(n, j));
		}
	}
	return 0;
}
