#include <stdio.h>
#include <stdlib.h>

#define TAM 9

// codevremove
bool ehValido(int** A, int linha, int col, int num) {
    for (int i = 1; i <= TAM; i++) {
        if (A[linha][i] == num || A[i][col] == num) {
            return false;
        }
    }

    int regiao_linha = linha - ((linha-1) % 3); 
    int regiao_coluna = col - ((col-1) % 3); 

    for (int i = regiao_linha; i < regiao_linha + 3; i++) {
        for (int j = regiao_coluna; j < regiao_coluna + 3; j++) {
            if (A[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuBK(int** A, int linha, int col) {
    if (linha == TAM + 1) {
        return true;
    }

    if (A[linha][col] != 0) {
        if (col == TAM) {
            return SudokuBK(A, linha + 1, 1);
        } else {
            return SudokuBK(A, linha, col + 1);
        }
    } else {
        for (int num = 1; num <= 9; num++) {
            if (ehValido(A, linha, col, num)) {
                A[linha][col] = num;
                if (col == TAM) {
                    if (SudokuBK(A, linha + 1, 1)) {
                        return true;
                    }
                } else {
                    if (SudokuBK(A, linha, col + 1)) {
                        return true;
                    }
                }
                A[linha][col] = 0;
            }
        }
        return false;
    }
}
// codevremove

bool Sudoku(int** A) {
    // codev
    return SudokuBK(A, 1, 1);
    // codev
}

int main() {
    int n; //número de tabuleiros
    scanf("%d", &n);
    while (n > 0) {
        int** A = (int**) malloc(sizeof(int*) * (TAM + 1));
        for(int i = 1; i <= TAM; i++) {
            A[i] = (int*) malloc(sizeof(int) * (TAM + 1));
        }
        for (int i = 1; i <= TAM; i++) {
            for (int j = 1; j <= TAM; j++) {
                scanf("%d", &(A[i][j]));
            }
        }
        
        if (Sudoku(A)) {
            printf("S\n");
        } else {
            printf("N\n");
        }

        for(int i = 1; i <= TAM; i++) {
            free(A[i]);
        }
        free(A);
        n--;
    }

    return 0;
}