
#include <stdio.h>

#define MAX(A,B) (A > B ? A : B)

void updateEnergy(int N, int *E, int *L, int time) {
    for (int i = 0; i < N; i++) {
        E[i] = MAX(0, E[i] - time*L[i]);
    }
}

int energyLoss(int E, int L, int time) {
    if (E > time*L) return time*L;
    return E;
}

/*
Want to minimise lost energy. Assume S[i] = S[j] for all i, j (TS1)

If they all take same time to eat, then eat the ones that lose value quickest first.
*/
int nextStone(int N, int *S, int *E, int *L) {
    int best;
    int i = 0;

    while (i < N && E[i] == 0) i++;
    if (i == N) return -1;

    best = i;
    while (i < N) {
        if (E[i] > 0) {
            // Take the one that loses the most energy.
            if (energyLoss(E[i], L[i], S[i]) > energyLoss(E[best], L[best], S[best])) {
                best = i;
            }
        }
        i++;
    }
    return best;
}

int maxEnergy(int N, int *S, int *E, int *L) {
    int best = nextStone(N, S, E, L);
    if (best == -1) return 0;

    // Eat maxLi and update other values
    int energyGain = E[best];
    E[best] = 0;
    updateEnergy(N, E, L, S[best]);
    return energyGain + maxEnergy(N, S, E, L);
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        int S[100];
        int E[100];
        int L[100];
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &(S[i]), &(E[i]), &(L[i]));
        }

        printf("Case #%d: %d", t, maxEnergy(N, S, E, L));
    }
    return 0;
}
