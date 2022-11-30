#include <stdio.h>
#include <stdlib.h>


/* 
    determina a existencia de um quadrado magico nxn que possiu prefixo P[1..d]
*/
int coord(int n, int i, int j){
    return ((i-1) * n) + j-1;
}
// 3 4 2      3*3 + 2

void Cubo(int n, int P[], int d, int U[]){
    if(d==n*n){
        int somaq = 0;
        int soma;
        bool flag = true;

        for(int i = 1; i<n+1;i++){
            soma = 0;
            for(int j = 1; j<n+1;j++){
                // printf("%d \n", P[coord(n, i, j)]);
                
                soma = soma + P[coord(n, i, j)];
            }
            if(somaq==0){
                somaq = soma;
            }
            else if(soma != somaq){
                flag = false;
            }
        }
        for(int j = 1; j<n+1;j++){
            soma = 0;
            for(int i = 1; i<n+1;i++){
                soma = soma + P[coord(n, i, j)];
            }
            if(somaq==0){
                somaq = soma;
            }

            else if(soma != somaq){
                flag = false;
            }
        }

        soma = 0;
        for(int i = 1; i<n+1;i++){
            soma = soma + P[coord(n,i,i)];
        }
        if(soma != somaq){
            flag = false;
        }

        soma = 0;
        for(int i = 1; i<n+1;i++){
            soma = soma + P[coord(n,i,n-i+1)];
        }
        if(soma != somaq){
            flag = false;
        }
        if(flag == true){
            for(int i = 1; i<n+1;i++){
                for(int j = 1; j<n+1;j++){
                    printf("%d", P[coord(n,i,j)]);
                    if (j != n){
                        printf(" | ");
                    }
                    else{
                        printf("\n");
                    }
                }
            }
            printf("\n");
        }
    }else{
        for(int i = 1; i < n*n+1; i++){
            if(U[i] == false){
                P[d] = i;
                U[i] = true;
                Cubo(n, P, d+1, U);
                U[i] = false;
            }
        }
    }
}

int main() {
    int n, d;
    scanf("%d", &n);
    int P[n*n+1];
    int U[n*n+1];
    for(int i = 0; i<n*n+1;i++){
        P[i] = 0;
        U[i] = false;
    }
    d = 0;
    Cubo(n, P, d, U);
	printf("Done");
}
