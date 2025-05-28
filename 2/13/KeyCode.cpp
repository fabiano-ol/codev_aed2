#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// codevremove
int UltimoPalitoBK(int n, int j, int P[], int d) {
    // n = Número de Palitos
    // j = Número do próximo jogador (1 ou 2)
    // P[i] = i-ésima jogada (número entre 1 e 3)
    // d = jogadas já feitas
    // retornar o vencedor (X = jogador X pode forçar a vitória)

    int removidos = 0;
    int jogadorVencedor;

    for (int i = 1; i <= d; i++) {
        removidos = removidos + P[i];
    }

    int restou = n - removidos;

    if (restou == 0) {
        return 3 - j;
    } else {
        for (int i = 1; i <= min(3, restou); i++) {
            P[d+1] = i;
            jogadorVencedor = UltimoPalitoBK(n, 3-j, P, d+1);
            if(j == jogadorVencedor) {
                return j;
            }
        }
        return 3 - j;
    }
}
// codevremove

void UltimoPalito(int n, int j) {
    // codev
    int * P = (int *) malloc(sizeof(int) * (n + 1));
    printf("%d\n", UltimoPalitoBK(n, j, P, 0));
    free(P);
    // codev
}

int main() {
    int n;
    int j;
	
	while (scanf("%d", &n)>0) {
        scanf("%d", &j);
		UltimoPalito(n, j);
	}

    return 0;
}
