
#include <stdio.h>

#define ABS(A) (A > 0 ? A : -A)

#define MAX_N 100000

/*

Given an index i to take as maximum, what is the largest L<i and R>i that doesn't change the maximum.

*/

static int process(int N, int K, int *C, int *D) {
    int count = 0;
    for (int L = 0; L < N; L++) {
        for (int R = L; R < N; R++) {
            int bestC = C[L];
            int bestD = D[L];

            for (int i = L+1; i <= R; i++) {
                if (C[i] > bestC) bestC = C[i];
                if (D[i] > bestD) bestD = D[i];
            }
            if (ABS((bestC-bestD)) <= K) count++;
        }
    }
    return count;
}

static int process(int N, int K, int *C, int *D) {
    int count = 0;

    return count;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, K;
        int C[MAX_N], D[MAX_N];
        scanf("%d %d", &N, &K);
        if (N > MAX_N) return 1;
        for (int i = 0; i < N; i++) scanf("%d", &C[i]);
        for (int i = 0; i < N; i++) scanf("%d", &D[i]);

        printf("Case #%d: %d\n", t, process(N, K, C, D));
    }

    return 0;
}
