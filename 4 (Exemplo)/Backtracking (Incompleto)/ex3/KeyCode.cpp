#include <stdio.h>
#include <stdlib.h>


/* 
Assume:  n >= k, 0 <= d <= k
Garante: Escrita de todas as permutações de {1,...,n} que contenha os d elementos b[0..d-1]
*/
void Perm(int n, int b[], int d){
    if (n == d) {
        printf("(");
        for (int i = 0; i < n; i++){ // escrevendo b[0..k-1]
            printf("%d", b[i]);
            if(i != (n-1)){
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
                Perm(n, b, d+1);
            }
        } 
    }
}

int main() {
	int n, k;
	while (scanf("%d", &n)>0) {
        int b[n];
        int d = 0;
        Perm(n, b, d);
	}
}
