
#include <stdio.h>

#define MAX_N 100
#define MAX_G 100
#define MAX_M 100

typedef struct {
    int time;
    int numGuests;
    int guests[MAX_G];
} Consulate;

void updateConsulate(Consulate *consulate, int time, int guest) {
    if (time != consulate->time) {
        consulate->time = time;
        consulate->numGuests = 0;
    }
    consulate->guests[consulate->numGuests++] = guest;
}

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, G, M; scanf("%d %d %d", &N, &G, &M);
        int pos[MAX_G] = {0};
        char dir[MAX_G] = {0};
        for (int i = 0; i < G; i++) {
            scanf("%d %c", &pos[i], &dir[i]);
            pos[i]--;
        }

        Consulate consulates[MAX_N] = {0};

        for (int m = 0; m <= M; m++) {
            for (int g = 0; g < G; g++) {
                updateConsulate(&consulates[pos[g]], m, g);

                switch (dir[g]) {
                    case 'C':   pos[g]++; break;
                    case 'A':   pos[g]--; break;
                    default:    return 1;
                }
                if (pos[g] >= N) pos[g] -= N;
                if (pos[g] < 0)  pos[g] += N;
            }
        }

        int sum[MAX_G] = {0};
        for (int n = 0; n < N; n++) {
            int *guests = consulates[n].guests;
            int numGuests = consulates[n].numGuests;
            for (int i = 0; i < numGuests; i++) {
                sum[guests[i]]++;
            }
        }

        printf("Case #%d:", t);
        for (int g = 0; g < G; g++) {
            printf(" %d", sum[g]);
        }
        putchar('\n');
    }

    return 0;
}
