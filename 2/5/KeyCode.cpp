#include <stdio.h>
#include <stdlib.h>

#define TAM 3

// codevremove
int contarJogadas(int **T, int jogador) {
    int cont = 0;
    for (int i = 1; i <= TAM; i++) {
        for (int j = 1; j <= TAM; j++) {
            if (T[i][j] == jogador) {
                cont++;
            }
        }
    }
    return cont;
}

bool verificaVitoria(int **T, int jogador) {
    for (int i = 1; i <= TAM; i++) {
        if (T[i][1] == jogador && T[i][2] == jogador && T[i][3] == jogador)
            return true;
        if (T[1][i] == jogador && T[2][i] == jogador && T[3][i] == jogador)
            return true;
    }

    if (T[1][1] == jogador && T[2][2] == jogador && T[3][3] == jogador)
        return true;
    if (T[1][3] == jogador && T[2][2] == jogador && T[3][1] == jogador)
        return true;

    return false;
}

void JogoDaVelhaBK(int **T, int linha, int coluna, int &vitorias1, int &vitorias2, int &empates) {
    if (linha == 4) {
        int jogadas1 = contarJogadas(T, 1);
        int jogadas2 = contarJogadas(T, 2);
        bool ganhou1 = verificaVitoria(T, 1);
        bool ganhou2 = verificaVitoria(T, 2);
        if (ganhou1 && !ganhou2 && jogadas1 == jogadas2 + 1) {
            vitorias1++;
        } else if (ganhou2 && !ganhou1 && jogadas1 == jogadas2) {
            vitorias2++;
        } else {
            int posicoesLivres = TAM * TAM - jogadas1 - jogadas2;
            if (posicoesLivres == 0 && jogadas1 == jogadas2 + 1) {
                empates++;
            }
        }
    } else {
        if (T[linha][coluna] == 0) {
            for (int i = 0; i <= 2; i++) {
                T[linha][coluna] = i;
                if (coluna == TAM) {
                    JogoDaVelhaBK(T, linha + 1, 1, vitorias1, vitorias2, empates);
                } else {
                    JogoDaVelhaBK(T, linha, coluna + 1, vitorias1, vitorias2, empates);
                }
            }
            T[linha][coluna] = 0;
        } else {
            if (coluna == TAM) {
                JogoDaVelhaBK(T, linha + 1, 1, vitorias1, vitorias2, empates);
            } else {
                JogoDaVelhaBK(T, linha, coluna + 1, vitorias1, vitorias2, empates);
            }
        }
    }
}
// codevremove

void JogoDaVelha(int **T) {
    // codev
    int vitorias1 = 0, vitorias2 = 0, empates = 0;

    JogoDaVelhaBK(T, 1, 1, vitorias1, vitorias2, empates);
    printf("%d %d %d\n", vitorias1, vitorias2, empates);
    // codev
}

int main() {
    int n;
    scanf("%d", &n);
    while (n > 0) {
        int **T = (int **) malloc(sizeof(int *) * (TAM + 1));
        for (int i = 1; i <= TAM; i++) {
            T[i] = (int *) malloc(sizeof(int) * (TAM + 1));
        }
        for (int i = 1; i <= TAM; i++) {
            for (int j = 1; j <= TAM; j++) {
                scanf("%d", &(T[i][j]));
            }
        }

        JogoDaVelha(T);

        for (int i = 1; i <= TAM; i++) {
            free(T[i]);
        }
        free(T);
        n--;
    }
    return 0;
}
