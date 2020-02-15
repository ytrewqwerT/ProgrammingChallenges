
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED(X) ( D / ( ((double) (D-K[X])) / S[X] ) )

int main(void)
{
    int T, D, N;
    int *K, *S;
    double speed;

    scanf("%d", &T);

    for (int testCase = 1; testCase < T+1; testCase++) {
        scanf("%d %d", &D, &N);
        S = malloc(N*sizeof(int));
        K = malloc(N*sizeof(int));
        for (int i = 0; i < N; i++) scanf("%d %d", &K[i], &S[i]);

        // iterate through horses and take the their slowest speed
        speed = MAX_SPEED(0);
        for (int i = 1; i < N; i++) {
            if (speed > MAX_SPEED(i)) speed = MAX_SPEED(i);
        }

        printf("Case #%d: %lf\n", testCase, speed);

        free(S);
        free(K);
    }

    return EXIT_SUCCESS;
}