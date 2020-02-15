
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

#define DIFF(A, B) (A > B ? A-B : B-A)

void merge(int *P, int *A, int arr2Start, int arrLen) {
    int *tmpP = malloc(arrLen * sizeof(int));
    int *tmpA = malloc(arrLen * sizeof(int));

    int arr1Pos = 0;
    int arr2Pos = arr2Start;
    int i = 0;
    while (arr1Pos < arr2Start && arr2Pos < arrLen) {
        if (P[arr1Pos] < P[arr2Pos]) {
            tmpA[i] = A[arr1Pos];
            tmpP[i++] = P[arr1Pos++];
        } else {
            tmpA[i] = A[arr2Pos];
            tmpP[i++] = P[arr2Pos++];
        }
    }
    while (arr1Pos < arr2Start) {
        tmpA[i] = A[arr1Pos];
        tmpP[i++] = P[arr1Pos++];
    }
    while (arr2Pos < arrLen) {
        tmpA[i] = A[arr2Pos];
        tmpP[i++] = P[arr2Pos++];
    }

    memcpy(P, tmpP, arrLen * sizeof(int));
    memcpy(A, tmpA, arrLen * sizeof(int));
    free(tmpP);
    free(tmpA);
}

void mergeSort(int *P, int *A, int arrLen) {
    if (arrLen < 2) return;

    mergeSort(P, A, arrLen/2);
    mergeSort(P + arrLen/2, A + arrLen/2, arrLen/2 + arrLen%2);
    merge(P, A, arrLen/2, arrLen);
}

int canObserveInTime(int K, int time, int colour, int pos,
        int N, int A[MAX_N], int P[MAX_N], char observed[MAX_N]) {
    if (time < 0) return 0;
    if (K < 1) return 1;

    for (int i = 0; i < N; i++) {
        if (!observed[i]) {
            observed[i] = 1;

            int remTime = time;
            if (colour == A[i]) remTime -= DIFF(pos, P[i]);
            else                remTime -= pos + P[i];

            if (canObserveInTime(K-1, remTime, A[i], P[i], N, A, P, observed)) return 1;

            observed[i] = 0;
        }
    }

    return 0;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, K; scanf("%d %d", &N, &K);
        int A[MAX_N];
        int P[MAX_N];
        int lower = 0;
        int upper = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &P[i]);
            upper += 2*P[i];
        }
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        mergeSort(P, A, N);

        while (lower < upper) {
            int middle = (lower + upper) / 2;
            char observed[MAX_N] = {0};
            if (canObserveInTime(K, middle, 1, 0, N, A, P, observed)) {
                upper = middle;
            } else {
                lower = middle+1;
            }
        }

        printf("Case #%d: %d\n", t, upper);
    }

    return 0;
}
