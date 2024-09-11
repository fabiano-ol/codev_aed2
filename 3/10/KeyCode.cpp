#include <stdio.h>
#include <stdlib.h>
#include <cstring>  
#include <algorithm>

#define MAX_SIZE_CHAR 100000

using namespace std;

typedef struct Caixa {
    int largura, profundidade, altura;
} Caixa;

// Função de comparação para ordenar as ca ixas de acordo com a área da base (largura * profundidade)
bool compararBase(const Caixa& a, const Caixa& b) {
    return (a.largura * a.profundidade) > (b.largura * b.profundidade);
}

Caixa* gerarRotacoes(Caixa* caixas, int n) {
    Caixa* rotacoes = (Caixa*)malloc((3 * n) * sizeof(Caixa));

    for (int i = 0; i < n; ++i) {
        int l = caixas[i].largura;
        int p = caixas[i].profundidade;
        int a = caixas[i].altura;

        rotacoes[3 * i] = Caixa{max(l, p), min(l, p), a};
        rotacoes[3 * i + 1] = Caixa{max(l, a), min(l, a), p};
        rotacoes[3 * i + 2] = Caixa{max(p, a), min(p, a), l};
    }

    return rotacoes;
}

int AlturaMaximaPilha(Caixa* caixas, int n) {
    // Cada caixa pode gerar 3 rotações diferentes
    Caixa* todasRotacoes = gerarRotacoes(caixas, n);

    // Ordenar as caixas de acordo com a área da base em ordem decrescente
    sort(todasRotacoes, todasRotacoes + (3 * n), compararBase);

    int* Mem = (int*)malloc((3 * n) * sizeof(int));
    for (int i = 0; i < (3 * n); ++i) {        
        Mem[i] = todasRotacoes[i].altura;
    }

    for (int i = 1; i < (3 * n); ++i) {
        for (int j = 0; j < i; ++j) {
            // Verifica se a caixa j pode ser colocada abaixo da caixa i
            if (todasRotacoes[i].largura < todasRotacoes[j].largura &&
                todasRotacoes[i].profundidade < todasRotacoes[j].profundidade) {
                Mem[i] = max(Mem[i], Mem[j] + todasRotacoes[i].altura);
            }
        }
    }

    int alturaMaxima = 0;
    for (int i = 0; i < (3 * n); ++i) {
        alturaMaxima = max(alturaMaxima, Mem[i]);
    }

    free(todasRotacoes);
    free(Mem);

    return alturaMaxima;
}

int main() {
	int n = 0;
	Caixa* caixas = NULL;

	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;

		if (testeDeCarga) {
			n = 1000;
		}

		caixas = (Caixa*) malloc(n * sizeof(Caixa));
		for(int i = 0; i < n; i++) {
			if (testeDeCarga) {
				caixas[i] = Caixa{i, i+1, i+2};
			} else {
				scanf("%d %d %d", &caixas[i].largura, &caixas[i].profundidade, &caixas[i].altura);
			}
		}
		
		printf("%d\n", AlturaMaximaPilha(caixas, n));
	}

	free(caixas);
}