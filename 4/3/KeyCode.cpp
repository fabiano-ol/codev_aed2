#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

using namespace std;

typedef struct Tarefa {
    int T;  // Prazo limite para a tarefa ser iniciada
    int R;  // Recompensa pela tarefa
} Tarefa;

// codevremove
bool ordenarRecompensaDesc(Tarefa a, Tarefa b) {
    return a.R > b.R || (a.R == b.R && a.T > b.R);
}
// codevremove

int SelecaoTarefasRecompensa(Tarefa[] tarefas, int n){
	// codev
    sort(tarefas + 1, tarefas + n + 1, ordenarRecompensaDesc);

    bool* horasOcupadas = (bool*) malloc(sizeof(bool) * (n + 1));
    for (int i = 1; i <= n; i++) {
        horasOcupadas[i] = false; // Inicialmente, todas as horas estão livres
    }

    int receitaMaxima = 0;
    for (int i = 1; i <= n; i++) {
        // Tente executar a tarefa na última hora possível, antes ou até o tempo limite Ti
        for (int j = tarefas[i].T - 1; j >= 0; j--)  {
            if (!horasOcupadas[j]) {
                horasOcupadas[j] = true;
                receitaMaxima += tarefas[i].R;
                break;
            }
        }
    }

    free(horasOcupadas);
    return receitaMaxima;
	// codev
}

int main() {
	int n = 0; 
	Tarefa * tarefas = NULL;

	while (scanf("%d", &n)>0) {
		bool testeDeCarga = n == -1;
		
		if (testeDeCarga) {
			n = 1000;
		}

		tarefas = (Tarefa *) malloc(sizeof(Tarefa) * (n+1));
		for(int i = 1; i <= n; i++){
			if (testeDeCarga) {
				tarefas[i] = Tarefa{i, i};
			} else {
				scanf("%d %d", &tarefas[i].T, &tarefas[i].R);
			}
		} 

		printf("%d\n", SelecaoTarefasRecompensa(tarefas, n));
	}

	free(tarefas);
	return 0;
}
