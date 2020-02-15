
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++) {
        int N, *R, *C;
        scanf("%d", &N);
        R = malloc(N*sizeof(int));
        C = malloc(N*sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &R[i], &C[i]);
        }

        int tr, tc, min, max, time;
        
        min = max = R[0];
        for (int i = 1; i < N; i++) {
            if (R[i] < min) min = R[i];
            if (R[i] > max) max = R[i];
        }
        tr = (max+min)/2 + (max+min)%2;

        min = max = C[0];
        for (int i = 1; i < N; i++) {
            if (C[i] < min) min = C[i];
            if (C[i] > max) max = C[i];
        }
        tc = (max+min)/2 + (max+min)%2;

        time = 0;
        for (int i = 0; i < N; i++) {
            if (abs(R[i]-tr) > time) time = abs(R[i]-tr);
            if (abs(C[i]-tr) > time) time = abs(C[i]-tr);
        }

        printf("Case #%d: %d\n", testCase, time);

        free(R);
        free(C);
    }
}
