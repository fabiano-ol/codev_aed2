#include <stdio.h>
#include <stdlib.h>

/* 
Assume:  n >= k, 0 <= d <= k
Garante: Escrita de todas as permutações de {1,...,n} de tamanho k
         que contenha os d elementos b[0..d-1]
*/
void Arranjo(int n, int k, int b[], int d){
    // codev
    if (k == d) {
    	printf("(");
        for (int i = 1; i <= k; i++){
            printf("%d", b[i]);
            if(i != k){
              printf(",");
            }
        }

        printf(")");
    } else {
        for (int i = 1; i <= n; i++){
            bool enc = false;
            for (int j = 1; j <= d; j++){ 
                if(b[j] == i){
                    enc = true; 
                    break;
                }
            }
            if(!enc){
                b[d+1] = i;
                Arranjo(n, k, b, d+1);
            }
        } 
    }
    // codev
}

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k)>0) {
        int* b = (int *) malloc(sizeof(int) * (k+1));
        Arranjo(n, k, b, 0);
        printf("\n");
	}
}
