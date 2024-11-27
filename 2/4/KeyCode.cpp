#include <stdio.h>
#include <stdlib.h>

// codevremove
// Validar se este número preenchido na d-ésima posição torna o QuadradoMagico válido
bool ehValido(int n, int P[], int d) {
    if (d == 1) {
        return true;
    }

    int somaq = n * n * n;
    int soma;
    bool flag = true;
    
    // Inicializar somaq quando houver uma linha preenchida
    if (d >= n) {
        somaq = 0;
        for (int i = 1; i <= n; i++) {
            somaq += P[i];
        }
    }

    // Verificar linha entre as posições (d - (d % n) + 1) e d
    int inicioLinha = d - (((d-1) % n)+1) + 1;
    soma = 0;
    for (int i = inicioLinha; i <= d; i++) {
        soma += P[i];
    }
    if (d % n == 0) { // d é o fim da linha
        if (soma != somaq) {
            return false;
        }
    } else {
        if (soma > somaq) {
            return false;
        }
    }

    // Verificar coluna entre as posições ((d-1) % n) + 1 e d
    int inicioColuna = ((d-1) % n) + 1;
    soma = 0;
    for (int i = inicioColuna; i <= d; i += n) {
        soma += P[i];
    }
    if (d > (n * n) - n) { // d é o fim da linha
        if (soma != somaq) {
            return false;
        }
    } else {
        if (soma > somaq) {
            return false;
        }
    }

    // Verificar diagonal principal
    if (((d-1) % n) + 1 == ((d-1) / n) + 1) {  // Se a linha é igual a coluna
        soma = 0;
        for (int i = 1; i <= d; i += n+1) {
            soma += P[i];
        }
        if (d > (n * n) - n) { // d é o fim da linha
            if (soma != somaq) {
                return false;
            }
        } else {
            if (soma > somaq) {
                return false;
            }
        }
    }
    
    // Verificar diagonal secundária
    if ((((d-1) % n) + 1) + (((d-1) / n) + 1) == n + 1) {  // Se a soma da linha com a coluna é igual a n + 1
        soma = 0;
        for (int i = n; i <= d; i += n-1) {
            soma += P[i];
        }
        if (d > (n * n) - n) { // d é o fim da linha
            if (soma != somaq) {
                return false;
            }
        } else {
            if (soma > somaq) {
                return false;
            }
        }
    }

    return true;
}

void QuadradoMagicoBK(int n, int P[], bool U[], int d, bool &achou){
    if (d == n*n) {
        for(int i = 1; i<= (n*n); i++){
            if(i % n == 1 || n == 1) {
                printf("(");
            }
            printf("%d", P[i]);
            if (i % n != 0){
                printf(",");
            } else {
                printf(")");
            }
        }
        achou = true;
    } else {
        for(int i = 1; i <= (n*n); i++){
            if(U[i] == false){
                P[d+1] = i;
                U[i] = true;
                if (ehValido(n, P, d+1)) {
                    QuadradoMagicoBK(n, P, U, d+1, achou);
                    if (achou) {
                        break;
                    }
                }
                U[i] = false;
            }
        }
    }
}
// codevremove

void QuadradoMagico(int n){
    // codev
    bool achou = false;
    int* P = (int *) malloc(sizeof(int) * (n*n+1));
    bool* U = (bool *) malloc(sizeof(bool) * (n*n+1));
    for(int i = 1; i <= (n*n); i++){
        P[i] = 0;
        U[i] = false;
    }

    QuadradoMagicoBK(n, P, U, 0, achou);

    if (!achou) {
        printf("-");
    }

    printf("\n");
    free(P);
    free(U);
    // codev
}

int main() {
    int n;
	while (scanf("%d", &n)>0) {
        QuadradoMagico(n);
	}
}
