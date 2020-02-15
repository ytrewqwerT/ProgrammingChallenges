
#include <stdio.h>

#define MAX_N 100000

int sum(int *A, int L, int R) {
    int sum = 0;
    for (int i = L; i <= R; i++) {
        sum += A[i];
    }
    return sum;
}

int bitSum(int V) {
    int sum = 0;
    while (V > 0) {
        sum += V & 1u;
        V >>= 1;
    }
    return sum;
}

int findMaxSize(int *A, int N) {
    if (sum(A, 0, N-1) % 2 == 0) {
        return N;
    }

    int left = 0;
    int right = N-1;

    while (A[left] % 2 == 0 && left < N) left++;
    while (A[right] % 2 == 0 && right >= 0) right--;

    left = N - left - 1;
    
    if (left > right) {
        return left;
    } else {
        return right;
    }
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:", t);

        int N, Q; scanf("%d %d", &N, &Q);
        int A[MAX_N] = {0};
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            A[i] = bitSum(A[i]);
        }


        int maxSize = findMaxSize(A, N);
        for (int i = 0; i < Q; i++) {
            int P, V; scanf("%d %d", &P, &V);
            int oldBitSum = A[P];
            A[P] = bitSum(V);

            if (A[P]%2 != oldBitSum%2) {
                maxSize = findMaxSize(A, N);
            }

            printf(" %d", maxSize);
        }
        putchar('\n');
    }

    return 0;
}
