
#include <stdio.h>
#include <stdlib.h>

int case25[2][10] = {{1,2,1,2,1,2,1,2,1,2},
                     {3,1,4,2,5,3,1,4,2,5}};
int case26[2][12] = {{1,2,1,2,1,2,1,2,1,2,1,2},
                     {3,1,4,2,5,3,6,4,1,5,2,6}};
int case27[2][14] = {{1,2,1,2,1,2,1,2,1,2,1,2,1,2},
                     {3,1,4,2,5,3,6,4,7,5,1,6,2,7}};
int case28[2][16] = {{1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2},
                     {3,1,4,2,5,3,1,7,2,6,8,5,7,4,6,8}};
int case29[2][18] = {{1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2},
                     {3,1,4,2,5,3,1,4,6,8,2,7,9,6,8,5,7,9}};

int case34[2][12] = {{2,1,2,3,1,2,3,1,3,1,2,3},
                     {3,1,4,2,3,1,3,2,1,4,2,4}};
int case35[2][15] = {{2,1,2,1,2,1,3,1,3,1,3,2,3,2,3},
                     {3,1,4,2,5,3,2,5,1,4,3,1,4,2,5}};
int case36[2][18] = {{2,1,2,1,2,1,2,3,1,3,1,3,2,3,1,3,2,3},
                     {3,1,4,2,5,3,1,3,4,1,5,4,6,2,6,5,2,6}};
int case37[2][21] = {{2,1,2,1,2,1,2,1,3,1,3,1,3,2,3,2,3,1,3,2,3},
                     {3,1,4,2,5,3,1,4,1,5,2,6,5,7,3,6,4,7,6,2,7}};

typedef struct node Node;
struct node {
    int r, c;
    struct node *next;
};

typedef struct {
    Node *top;
} Stack;

void push(Stack *s, int r, int c) {
    Node *n = malloc(sizeof(*n));
    n->r = r;
    n->c = c;
    n->next = s->top;
    s->top = n;
}

int pop(Stack *s, int *r, int *c) {
    if (s->top == NULL) return 0;

    *r = s->top->r;
    *c = s->top->c;

    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    
    return 1;
}

int processSmall(int map[20][20], int cr, int cc, int R, int C, int depth, Stack *seq) {
    if (depth == R*C) {
        if (cr+1 == R && cc+1 == C) return 1;
        return 0;
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (r == cr || c == cc) continue;
            if (r-c == cr-cc || r+c == cr+cc) continue;
            if (map[r][c] != 0) continue;

            map[r][c] = 1;
            if (processSmall(map, r, c, R, C, depth+1, seq)) {
                push(seq, r, c);
                return 1;
            }
            map[r][c] = 0;
        }
    }
    return 0;
}

void printOffsetCoords(int *coords, int len, int rOff, int cOff, int mirrored) {
    for (int i = 0; i < len; i++) {
        int r = coords[i] + rOff;
        int c = coords[len+i] + cOff;

        if (!mirrored) printf("%d %d\n", r, c);
        else           printf("%d %d\n", c, r);
    }
}

void processEven(int R, int C, int rOff, int mirrored) {
    if (R == 0) return;

    int c = C;
    int cOff = 0;

    while (c > 9) {
        printOffsetCoords((int*) case25, 10, rOff, cOff, mirrored);
        c -= 5;
        cOff += 5;
    }

    int *arr;
    int arrLen;

    switch (c) {
        case 5: arr = (int*) case25; arrLen = 10; break;
        case 6: arr = (int*) case26; arrLen = 12; break;
        case 7: arr = (int*) case27; arrLen = 14; break;
        case 8: arr = (int*) case28; arrLen = 16; break;
        case 9: arr = (int*) case29; arrLen = 18; break;
        default: exit(1);
    }
    printOffsetCoords(arr, arrLen, rOff, cOff, mirrored);

    processEven(R-2, C, rOff+2, mirrored);
}

void processOdd(int R, int C, int rOff, int mirrored) {
    int c = C;
    int cOff = 0;

    while (c > 7) {
        printOffsetCoords((int*) case34, 12, rOff, cOff, mirrored);
        c -= 4;
        cOff += 4;
    }

    int *arr;
    int arrLen;

    switch (c) {
        case 4: arr = (int*) case34; arrLen = 12; break;
        case 5: arr = (int*) case35; arrLen = 15; break;
        case 6: arr = (int*) case36; arrLen = 18; break;
        case 7: arr = (int*) case37; arrLen = 21; break;
        default: exit(1);
    }
    printOffsetCoords(arr, arrLen, rOff, cOff, mirrored);

    processEven(R-3, C, rOff+3, mirrored);
}

void processLarge(int R, int C) {
    int mirrored = 0;
    if (R > C) {
        int temp = R;
        R = C;
        C = temp;
        mirrored = 1;
    }

    if (R % 2) processOdd(R, C, 0, mirrored);
    else       processEven(R, C, 0, mirrored);
}

int main(void) {
    int T;
    scanf("%d", &T); getchar();
    for (int t = 1; t <= T; t++) {
        int R, C;
        scanf("%d %d", &R, &C);

        printf("Case #%d: ", t);
        if (R > 4 || C > 4) {
            printf("POSSIBLE\n");
            processLarge(R, C);
        } else {
            int possible = 0;
            int map[20][20] = {0};
            Stack seq = {0};

            for (int r = 0; !possible && r < R; r++) {
                for (int c = 0; !possible && c < C; c++) {
                    if (processSmall(map, r, c, R, C, 0, &seq)) {
                        possible = 1;
                    }
                }
            }
            
            if (!possible) printf("IM");
            printf("POSSIBLE\n");
            while (pop(&seq, &R, &C)) {
                printf("%d %d\n", R+1, C+1);
            }
        }
    }
    return 0;
}
