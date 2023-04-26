#include <stdio.h>
#include <stdlib.h>

#define N 9

// Verifica se o número já está presente na linha "row"
int isInRow(int grid[9][9], int row, int num) {
  for (int col = 0; col < 9; col++) {
    if (grid[row][col] == num) {
      return 1;
    }
  }
  return 0;
}


// Verifica se o número já está presente na coluna "col"
int isInCol(int grid[9][9], int col, int num) {
  for (int row = 0; row < 9; row++) {
    if (grid[row][col] == num) {
      return 1;
    }
  }
  return 0;
}
// Verifica se o número já está presente no quadrado 3x3 da célula (row, col)
int isInBox(int grid[9][9], int startRow, int startCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (grid[row + startRow][col + startCol] == num) {
        return 1;
      }
    }
  }
  return 0;
}
// Diz se é possivel botar um numero na celula desejada
int canPlaceNum(int grid[9][9], int row, int col, int num) {
  int result = 1;

  if (isInRow(grid, row, num) == 1) {
    result = 0;
  } else if (isInCol(grid, col, num) == 1) {
    result = 0;
  } else if (isInBox(grid, row - row % 3, col - col % 3, num) == 1) {
    result = 0;
  }

  return result;
}
// Encontra a primeira célula vazia (onde ainda não foi escolhido nenhum número)
int findUnassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == 0)
                return 1;
    return 0;
}

// Solve sudoku
int solveSudoku(int grid[N][N]) {
    int row, col;
    if (findUnassignedLocation(grid, &row, &col) == 0)
        return 1;
    for (int num = 1; num <= 9; num++) {
        if (canPlaceNum(grid, row, col, num) == 1) {
            grid[row][col] = num;
            if (solveSudoku(grid) == 1)
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}
// Printa a Matriz resolvida ao usuario
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main() {
    int grid[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
        scanf("%d", &grid[i][j]);
        }
    }
    solveSudoku(grid);
    printGrid(grid);
	printf("Done");
}