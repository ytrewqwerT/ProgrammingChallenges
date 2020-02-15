
#include <stdio.h>

#define MAX_R 300
#define MAX_C 300

#define DIFF(A, B) (A > B ? A-B : B-A)

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int R, C, K; scanf("%d %d %d", &R, &C, &K);

        int V[MAX_R][MAX_C] = {0};
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf("%d", &V[r][c]);
            }
        }

        int max = 1;

        // Create a new grid of processed data such that data[r][c] stores a value d such that a 1xd rectangle is 'good' but a 1x(d+1) isn't.
        int runs[MAX_R][MAX_C] = {0};
        for (int r = 0; r < R; r++) {
            for (int left = 0; left < C; left++) {
                int right = left+1;
                while (right < C && DIFF(V[r][left], V[r][right]) <= K) { right++; }
                runs[r][left] = right-left;
            }
        }

        // Iterate over all possible top-right corners (r,c) and find the largest rectangle for every possible height.
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                // Check rectangle height = 1
                int maxWidth = runs[r][c];
                if (maxWidth*1 > max) max = maxWidth*1;
                
                // Check rectangle height > 1
                for (int height = 2; r+height-1 < R; height++) {
                    if (runs[r+height-1][c] < maxWidth) {
                        maxWidth = runs[r+height-1][c];
                    }
                    if (maxWidth*height > max) max = maxWidth*height;
                }
            }
        }

        printf("Case #%d: %d\n", t, max);
    }

    return 0;
}
