
#include <stdio.h>
#include <string.h>

#define MAX_R 17
#define MAX_C 17

#define HORIZONTAL 'H'
#define VERTICAL 'V'

#define MAX(A,B) (A > B ? A : B)

typedef struct {
    int R, C;
    char state[MAX_R][MAX_C];
} Board;

// Undos the board modifications made by spreadBoard(b,r,c,type).
// Returns 0 if the parameters are misinformed.
// Returns 1 if successful.
static int unspreadBoard(Board *b, int r, int c, int type) {
    if (b->state[r][c] != type) return 0;

    if (type == HORIZONTAL) {
        int i = c;
        while (i >= 0 && b->state[r][i] == type) {
            b->state[r][i] = '.';
            i--;
        }
        i = c+1;
        while (i < b->C && b->state[r][i] == type) {
            b->state[r][i] = '.';
            i++;
        }
    } else if (type == VERTICAL) {
        int i = r;
        while (i >= 0 && b->state[i][c] == type) {
            b->state[i][c] = '.';
            i--;
        }
        i = r+1;
        while (i < b->C && b->state[i][c] == type) {
            b->state[i][c] = '.';
            i++;
        }
    } else {
        return 0;
    }
    return 1;
}

// Places a bacteria of the given type on the specified position and spreads it out.
// Returns 0 if the position is already occupied.
// Returns 1 if successful.
// Returns -1 if the placement results in a direct loss.
static int spreadBoard(Board *b, int r, int c, int type) {
    if (b->state[r][c] != '.') return 0;

    if (type == HORIZONTAL) {
        int i = c;
        while (i >= 0 && b->state[r][i] == '.') {
            b->state[r][i] = type;
            i--;
        }
        if (i >= 0 && b->state[r][i] == '#') {
            unspreadBoard(b, r, c, type);
            return -1;
        }

        i = c+1;
        while (i < b->C && b->state[r][i] == type) {
            b->state[r][i] = '.';
            i++;
        }
    } else if (type == VERTICAL) {
        int i = r;
        while (i >= 0 && b->state[i][c] == type) {
            b->state[i][c] = '.';
            i--;
        }
        i = r+1;
        while (i < b->C && b->state[i][c] == type) {
            b->state[i][c] = '.';
            i++;
        }
    }

    return 1;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        Board start;
        scanf("%d %d", &(start.R), &(start.C)); getchar();
        for (int r = 0; r < start.R; r++) {
            fgets(start.state[r], MAX_C, stdin);
        }

        Board searched;


        int wins = 0;

        // Search vertical wins
        // Make a copy of the board and spread into 

        // Search horizontal wins
        
        printf("Case #%d: %d\n", t, wins);
    }
    return 0;
}

/*

For any given incomplete board state:
    Initialise V and H matrix to 0.

    For each cell:
        Attempt to place a V bacterium and recursively count how many possible wins come from this action.
        Multiply this number by the number of cells vertically that the bacterium would spread into.
        Tag these cells with 1 in the V matrix.

        Repeat with H instead of V.

        Add the two results together to get total ways of winning

*/
