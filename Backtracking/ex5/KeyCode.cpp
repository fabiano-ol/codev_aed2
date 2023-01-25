#include <stdio.h>
#include <stdlib.h>

/* 
Assume:  n >= k, 0 <= d <= k
Garante: Escrita de todas as permutações de {1,...,n} de tamanho k
         que contenha os d elementos b[0..d-1]
*/
void Arranjo(int n, int k, int b[], int d){
    if (k == d) {
    	printf("(");
        for (int i = 0; i < k; i++){ // escrevendo b[0..k-1]
            printf("%d", b[i]);
            if(i != k-1){
              printf(", ");
            }
        }

        printf(")\n");
    } else {
        for (int i = 1; i <= n; i++){
            bool enc = false;
            for (int j = 0; j < d; j++){ 
                if(b[j] == i){
                    enc = true; break;
                }
            }
            if(! enc){
                b[d] = i;
                Arranjo(n, k, b, d+1);
            }
        } 
    }
}

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k)>0) {
        int b[k];
        int d = 0;
        Arranjo(n, k, b, d);
	}
}
