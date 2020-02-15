
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MOD_SIZE 1000000007

int pow(int base, int exp) {
    if (exp == 0) return 1;
    return base * pow(base, exp-1);
}

unsigned long long subArrExpPower(int *arr, int arrLen, int i) {
    unsigned long long sum = 0;
    for (int j = 1; j <= arrLen; j++) {
        sum += arr[j-1] * pow(j, i);
        sum %= MOD_SIZE;
    }
    return sum;
}

int main(void) {
    int T; scanf("%d", &T);

    int *A = malloc(MAX_N * sizeof(int));

    for (int t = 1; t <= T; t++) {
        int N, K; scanf("%d %d", &N, &K);

        // Get A[i] for all i
        {
            int xi, yi, C, D, E1, E2, F;
            scanf("%d %d %d %d %d %d %d",
                  &xi, &yi, &C, &D, &E1, &E2, &F);
            
            for (int i = 0; i < N; i++) {
                A[i] = (xi + yi) % F;

                int xi1 = (C*xi + D*yi + E1) % F;
                int yi1 = (D*xi + C*yi + E2) % F;

                xi = xi1;
                yi = yi1;
            }
        }

        unsigned long long sum = 0;
        for (int i = 1; i <= K; i++) {
            for (int size = 1; size <= N; size++) {
                for (int left = 0; left < N-size+1; left++) {
                    sum += subArrExpPower(&A[left], size, i);
                }
            }
        }

        printf("Case #%d: %llu\n", t, sum % MOD_SIZE);
    }

    free(A);

    return 0;
}
