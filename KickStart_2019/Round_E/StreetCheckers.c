
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABS(X) (X > 0 ? X : -X)

#define MAX_R 1000000001

int main(void) {
    char *interesting;

    interesting = malloc(MAX_R * sizeof(char));
    memset(interesting, 0, MAX_R*sizeof(char));

    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int L, R; scanf("%d %d", &L, &R);

        int solution = 0;
        for (int X = L; X <= R; X++) {
            if (interesting[X] != 0) {
                if (interesting[X] == 1) {
                    solution++;
                }
                continue;
            }

            int difference = 0;
            for (int tile = 1; tile <= X; tile++) {
                if (X % tile == 0) {
                    if (tile % 2 == 1) {
                        difference++;
                    } else {
                        difference--;
                    }
                }
            }
            if (ABS(difference) <= 2) {
                interesting[X] = 1;
                solution++;
            } else {
                interesting[X] = 2;
            }
        }

        printf("Case #%d: %d\n", t, solution);
    }

    return 0;
}
