
#include <stdio.h>
#include <stdlib.h>

#define ABS(A) (A > 0 ? A : -(A))

#define MAX_N 100000

int intCompare(const void *A, const void *B) {
    int a = *((int *) A);
    int b = *((int *) B);
    return a-b;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int K, N; scanf("%d %d", &K, &N);
        int X[MAX_N] = {0};
        for (int i = 0; i < N; i++) scanf("%d", &X[i]);
        int C[MAX_N] = {0};
        for (int i = 0; i < N; i++) scanf("%d", &C[i]);

        int minCost = -1;
        for (int warehouse = 0; warehouse < N; warehouse++) {
            int stallCost[MAX_N] = {0};
            for (int i = 0; i < N; i++) {
                if (i == warehouse) {
                    stallCost[i] = -1;
                } else {
                    stallCost[i] = C[i] + ABS(X[i]-X[warehouse]);
                }
            }
            qsort(stallCost, N, sizeof(stallCost[0]), &intCompare);

            int currCost = C[warehouse];
            for (int i = 1; i <= K; i++) {
                currCost += stallCost[i];
            }

            if (currCost < minCost || minCost == -1) {
                minCost = currCost;
            }
        }

        printf("Case #%d: %d\n", t, minCost);
    }

    return 0;
}
