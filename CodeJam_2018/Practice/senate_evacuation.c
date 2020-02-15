
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T, N, total;
    int *P;

    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        P = malloc(N*sizeof(int));
        total = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &P[j]);
            total += P[j];
        }
        printf("Case #%d:", i+1);
        
        while (total > 0) {
            // Remove from party with most members
            int most = 0;
            for (int j = 1; j < N; j++) {
                if (P[j] > P[most]) {
                    most = j;
                }
            }
            printf(" %c", 'A' + most);
            P[most]--;
            total--;
            // If conflict is caused, remove from party causing conflict
            for (int j = 0; j < N; j++) {
                if (P[j] > total/2) {
                    printf("%c", 'A' + j);
                    P[j]--;
                    total--;
                    break;
                }
            }
        }
        free(P);
        putchar('\n');
    }

    return EXIT_SUCCESS;
}