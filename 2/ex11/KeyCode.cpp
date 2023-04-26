#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

int N;
int group1[MAX_N], group2[MAX_N];
bool used[MAX_N];

void backtrack(int i, int size1, int size2) {
    if (i == N) {
        if (size1 > 0 && size2 > 0) {
            printf("Group 1: ");
            for (int j = 0; j < size1; j++) {
                printf("%d ", group1[j]);
            }
            printf("; Group 2: ");
            for (int j = 0; j < size2; j++) {
                printf("%d ", group2[j]);
            }
            printf("\n");
        }
    } else {
        used[i] = true;
        group1[size1] = i + 1;
        backtrack(i + 1, size1 + 1, size2);
        used[i] = false;
        if (size1 > 0) {
            group2[size2] = i + 1;
            backtrack(i + 1, size1, size2 + 1);
        }
    }
}

int main() {
    printf("Enter the number of players (1 to %d): ", MAX_N);
    scanf("%d", &N);
    backtrack(0, 0, 0);
    return 0;
}
