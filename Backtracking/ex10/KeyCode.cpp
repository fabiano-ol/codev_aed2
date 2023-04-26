#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

int is_valid(int row, int col, int num) {
    // Check row for duplicate numbers
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column for duplicate numbers
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 square for duplicate numbers
    int square_row = row - (row % 3);
    int square_col = col - (col % 3);
    for (int i = square_row; i < square_row + 3; i++) {
        for (int j = square_col; j < square_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve(int row, int col) {
    // If we've reached the end of the board, we're done
    if (row == SIZE) {
        return 1;
    }

    // If the current cell is not empty, move to the next cell
    if (board[row][col] != 0) {
        if (col == SIZE - 1) {
            return solve(row + 1, 0);
        } else {
            return solve(row, col + 1);
        }
    }

    // Try all possible numbers in the current cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (col == SIZE - 1) {
                if (solve(row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solve(row, col + 1)) {
                    return 1;
                }
            }
            board[row][col] = 0;
        }
    }

    // If no valid numbers work in this cell, backtrack
    return 0;
}

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Read the board from standard input
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            char c;
            scanf(" %c", &c);
            if (c == ' ') {
                board[i][j] = 0;
            } else {
                board[i][j] = c - '0';
            }
        }
    }

    // Solve the board
    if (solve(0, 0)) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}