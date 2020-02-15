
#include <stdio.h>

#define MAX_Q 100000

static void setDest(int coord, int dir, int count[MAX_Q+1], int Q) {
    if (dir == 1) {
        for (int i = coord+1; i <= Q; i++) {
            count[i]++;
        }
    } else {
        for (int i = coord-1; i >= 0; i--) {
            count[i]++;
        }
    }
}

static int getDest(int count[MAX_Q+1], int Q) {
    int best = 0;
    int pos = 0;
    for (int i = 0; i <= MAX_Q; i++) {
        if (count[i] > best) {
            best = count[i];
            pos = i;
        }
    }
    return pos;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int P, Q;
        int countX[MAX_Q+1] = {0};
        int countY[MAX_Q+1] = {0};
        scanf("%d %d", &P, &Q);
        for (int i = 0; i < P; i++) {
            int X, Y;
            char D;
            scanf("%d %d %c", &X, &Y, &D);

            switch (D) {
                case 'N': setDest(Y, 1, countY, Q); break;
                case 'S': setDest(Y, 0, countY, Q); break;
                case 'E': setDest(X, 1, countX, Q); break;
                case 'W': setDest(X, 0, countX, Q); break;
                default:  break;
            }
        }
        printf("Case #%d: %d %d\n", t, getDest(countX, Q), getDest(countY, Q));
    }
    return 0;
}
