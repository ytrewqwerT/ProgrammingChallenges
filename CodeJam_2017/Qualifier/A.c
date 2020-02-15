// Time taken:  15 minutes
// Attempts:    1

#include <stdio.h>
#include <stdlib.h>

void flip(char cakes[1001], int pos, int amount);

int main(void)
{
    int T, S, K;
    char cakes[1001];

    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++) {
        int flips = 0;
        S = -1;
        while ((cakes[++S] = getchar()) != ' ') {}
        scanf("%d", &K);
        
        int i;
        for (i = 0; i <= S-K; i++) {
            if (cakes[i] == '-') {
                flip(cakes, i, K);
                flips++;
            }
        }
        
        printf("Case #%d: ", testCase);
        while (i < S) {
            if (cakes[i] == '-') {
                printf("IMPOSSIBLE\n");
                break;
            }
            if (i == S - 1 && cakes[i] == '+') {
                printf("%d\n", flips);
            }
            i++;
        }
    }

    return EXIT_SUCCESS;
}

void flip(char cakes[1001], int pos, int amount)
{
    for (int i = pos; i < pos + amount; i++) {
        cakes[i] = cakes[i] == '+' ? '-' : '+';
    }
}