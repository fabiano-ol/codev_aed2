#include <stdio.h>
#include <stdlib.h>

int TrocoMin(int t, int M[]){
	// codev
	int qtdMoedas = 0;
	for (int i = 5; i >=0; i--) {
		while (M[i] <= t) {
			qtdMoedas++;
			t = t - M[i];
		}
	}
	return qtdMoedas;
	// codev
}


int main() {
	int M[6] = {1,5,10,25,50,100};
	int t;
	while (scanf("%d", &t)>0) {
		printf("%d\n", TrocoMin(t, M));
	}
	return 0;
}
