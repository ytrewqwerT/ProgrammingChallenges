
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000000

#define DESTROY(L, R) (L < R ? -1 : 1)
#define DIV_2_CEIL(NUM) (NUM/2 + NUM%2)

int main(void) {
    int T; scanf("%d", &T);

    int *cumulativeScore = malloc(MAX_N * sizeof(int));
    for (int t = 1; t <= T; t++) {
        int N; scanf("%d", &N); getchar(); // '\n'

        cumulativeScore[0] = getchar() - '0';
        for (int i = 1; i < N; i++) {
            cumulativeScore[i] = cumulativeScore[i-1] + getchar() - '0';
        }

        int maxBeauty = cumulativeScore[DIV_2_CEIL(N)-1];
        for (int i = 1; i <= N - DIV_2_CEIL(N); i++) {
            int seqBeauty = cumulativeScore[DIV_2_CEIL(N)+i-1] - cumulativeScore[i-1];
            if (seqBeauty > maxBeauty) maxBeauty = seqBeauty;
        }

        printf("Case #%d: %d\n", t, maxBeauty);
    }

    free(cumulativeScore);
    
    return 0;
}
