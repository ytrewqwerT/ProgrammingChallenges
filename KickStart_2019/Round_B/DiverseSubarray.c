
#include <stdio.h>

typedef struct {
    int N;
    int S;
    int A[10000];
    int nextLow[10000];
    int nextHigh[10000];
    int limLow[10000];
    int limHigh[10000];
} Data;

int numInterval(int S, int *A, int len) {
    int num = 0;
    int count[100000] = {0};
    for (int i = 0; i < len; i++) {
        count[A[i]]++;
    }
    for (int i = 0; i < 100000; i++) {
        if (count[i] <= S) num += count[i];
    }
    return num;
}

/*

N entries
For each entry: nextLower, nextHigher, lowerLimit, higherlimit


best = 0
Push [0 .. N-1]
While i = Pop:
    If i is better, best = numInterval(i)

    For each overloaded number n, in i:
        Adjust the i such that the lowest instance of n is removed and push the new interval.
        Adjust the i such that the highest instance of n is removed and push the new interval.

*/

int maxTrinkets(Data *d, int best, int lower, int higher) {
    int temp;

    temp = numInterval(d->S, &(d->A[lower]), higher-lower+1);
    if (temp > best) best = temp;

    

    return best;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        Data data = {0};
        scanf("%d %d", &(data.N), &(data.S));
        for (int i = 0; i < data.N; i++) {
            scanf("%d", &(data.A[i]));
        }
        printf("Case #%d: %d\n", t, maxTrinkets(&data, 1, 0, data.N-1));
    }

    return 0;
}
