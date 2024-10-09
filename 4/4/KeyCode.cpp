#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

using namespace std;

typedef struct Atividade {
    int inicio, fim;
} Atividade;

// codevremove
bool ComparadorAtividadeFim(Atividade A1, Atividade A2) {
    return A1.fim <= A2.fim;
}

bool EhConflitante(Atividade A1, Atividade A2) {
	// A1 = {l1, r1}; A2 = {l2, r2}
	// l2 >= r1 || l1 >= r2 -> não é conflitante
	return A2.inicio < A1.fim && A1.inicio < A2.fim;
}
// codevremove

// Solução com BackTracking
/*int SelAtividadesBK(int ** A, int n, bool * P, int d){
	// P[i] = 1, se A[j] pertence às atividades selecionadas que não são conflitantes entre si, para todo i = 1..d
	// P tem tamanho de n + 1

	int maxQtd;
	if (d == n) {
		printf("1\n");
		// Esta premissa considera que todas as atividades não são conflitantes
		int qtd = 0;
		for (int i = 0; i <= n; i++) {
			if (P[i]){
				printf("2\n");
				qtd++;
			}
		}
		maxQtd = max(maxQtd, qtd);
	} else {
		bool ops[2] = {false, true};
		for (bool op : ops) {
			if (op) {
				printf("true\n");
				// Verificar se A[d+1] não conflita com as já escolhidas
				bool conflitante = false;
				for (int i = 0; i <= d; i++) {
					printf("loop %d", i);
					if (P[i] && EhConflitante(A[d+1], A[i])) {
						printf("conflitante\n");
						conflitante = true;
						break;
					}
				}
				if(!conflitante) {
					P[d+1] = true;
					SelAtividadesBK(A, n, P, d+1);
				}
			} else {
				printf("false\n");
				P[d+1] = false;
				SelAtividadesBK(A, n, P, d+1);
			}
		}
	}
	
	return maxQtd;
}*/

int SelecaoAtividades(Atividade * A, int n) {
	// A regra do Guloso sempre tem que ser possível selecionar alguém
	// ela sempre tem que haver um intervalo com aquela característica
	
	// codev
	sort(A + 1, A + n + 1, ComparadorAtividadeFim);
	
	int qtd = 1;
	int u = 1;
	
	for (int i = 2; i <= n; i++) {
		if (!EhConflitante(A[i], A[u])){
			qtd++;
			u = i;
		}
	}
	
	return qtd;

	// codev
}

int main() {
	int n; 
	//bool * P; //Backtracking
	Atividade * A; 
	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;
		if (testeDeCarga) {
			n = 100000;
		}
		if (n>=0) { 
			A = (Atividade *) malloc(sizeof(Atividade) * (n+1));
			//P = (bool *) malloc(sizeof(bool) * (n+1)); //Backtracking
			for (int i = 1; i <= n; i++) {
				if (testeDeCarga) {
					A[i+1].inicio = i % 2 == 0 ? (2 * i) : (2 * i - 1);
					A[i+1].fim = i % 2 == 0 ? (2 * i + 2) : (2 * i + 1);
				} else {
					scanf("%d %d", &A[i].inicio, &A[i].fim);
				}
			} 
			//printf("%d\n", SelAtividadesBK(A, n, P, 0)); //Backtracking
			printf("%d\n", SelecaoAtividades(A, n));
		}
	}
	//free(P); //Backtracking
	free(A);
}
