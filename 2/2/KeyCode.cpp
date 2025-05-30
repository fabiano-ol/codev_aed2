#include <stdio.h>
#include <stdlib.h>


/* 
Assume:  n >= k, 0 <= d <= k
Garante: Escrita de todas as permutações de {1,...,n} que contenha os d elementos b[0..d-1]
*/
void Perm(int n, int b[], int d){
    // codev
    if (n == d) {
        printf("(");
        for (int i = 1; i <= n; i++){
            printf("%d", b[i]);
            if(i != n){
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
            if (!enc){
                b[d+1] = i;
                Perm(n, b, d+1);
            }
        } 
    }
    // codev
}

int main() {
	int n, k;
	while (scanf("%d", &n)>0) {
        int* b = (int *) malloc(sizeof(int) * (n+1));
        Perm(n, b, 0);
        printf("\n");
        free(b);
	}
}
