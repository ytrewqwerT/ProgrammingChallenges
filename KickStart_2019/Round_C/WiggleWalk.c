
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_R 50000
#define MAX_C 50000

void clearGrid(char **grid) {
    for (int i = 0; i < MAX_R; i++) {
        memset(grid[i], 0, MAX_C/8 * sizeof(char));
    }
}

int gridIsSet(char **grid, int r, int c) {
    char ch = grid[r][c/8];
    ch &= 1u << (c%8);
    return ch != 0;
}

void setGrid(char **grid, int r, int c) {
    grid[r][c/8] |= 1u << (c%8);
}

void processInstruction(char **grid, int *currR, int *currC, char dir) {
    do {
        switch (dir) {
            case 'N': (*currR)--; break;
            case 'S': (*currR)++; break;
            case 'E': (*currC)++; break;
            case 'W': (*currC)--; break;
            default:  exit(3);
        }
    } while (gridIsSet(grid, *currR, *currC));
    setGrid(grid, *currR, *currC);
}

int main(void) {
    int T; scanf("%d", &T);
    
    char **grid = malloc(MAX_R * sizeof(char *));
    if (grid == NULL) return 1;
    for (int i = 0; i < MAX_R; i++) {
        grid[i] = malloc(MAX_C/8 * sizeof(char));
        if (grid[i] == NULL) return 2;
    }

    for (int t = 1; t <= T; t++) {
        int N, R, C, SR, SC;
        scanf("%d %d %d %d %d", &N, &R, &C, &SR, &SC); getchar();

        SR--; SC--;

        clearGrid(grid);
        setGrid(grid, SR, SC);

        for (int i = 0; i < N; i++) {
            processInstruction(grid, &SR, &SC, getchar());
        }

        printf("Case #%d: %d %d\n", t, ++SR, ++SC);
    }

    for (int i = 0; i < MAX_R; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
