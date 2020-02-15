
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

void merge(int *arr, int arr2Start, int arrLen) {
    int *tmpArr = malloc(arrLen * sizeof(int));

    int arr1Pos = 0;
    int arr2Pos = arr2Start;
    int i = 0;
    while (arr1Pos < arr2Start && arr2Pos < arrLen) {
        if (arr[arr1Pos] < arr[arr2Pos]) {
            tmpArr[i++] = arr[arr1Pos++];
        } else {
            tmpArr[i++] = arr[arr2Pos++];
        }
    }
    while (arr1Pos < arr2Start) {
        tmpArr[i++] = arr[arr1Pos++];
    }
    while (arr2Pos < arrLen) {
        tmpArr[i++] = arr[arr2Pos++];
    }

    memcpy(arr, tmpArr, arrLen * sizeof(int));
    free(tmpArr);
}

void mergeSort(int *arr, int arrLen) {
    if (arrLen < 2) return;

    mergeSort(arr, arrLen/2);
    mergeSort(arr + arrLen/2, arrLen/2 + arrLen%2);
    merge(arr, arrLen/2, arrLen);
}

int getHours(int *last, int P) {
    int hours = 0;
    int top = *last;
    while (--P > 0) {
        last--;
        hours += top - *last;
    }
    return hours;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, P; scanf("%d %d", &N, &P);
        int S[MAX_N] = {0};
        for (int i = 0; i < N; i++)
            scanf("%d", &S[i]);
        mergeSort(S, N);

        int best = -1;
        for (int i = N-1; i >= P-1; i--) {
            int curr = getHours(&S[i], P);
            if (curr < best || best == -1) {
                best = curr;
            }
        }
        printf("Case #%d: %d\n", t, best);
    }

    return 0;
}
