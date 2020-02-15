
#include <stdio.h>

#define MAX_N 1024

int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, B, F; scanf("%d %d %d", &N, &B, &F); getchar();
        
        short results[MAX_N] = {0};

        for (int f = 0; f < F; f++) {
            for (int i = 0; i < N; i++) {
                putchar( ((i % 32) & (1u << f)) == 0 ? '0' : '1' );
            }
            putchar('\n');
            fflush(stdout);
            
            for (int i = 0; i < N-B; i++) {
                int c = getchar();
                if (c == '-') return 1;
                if (c == '1') results[i] |= 1u << f;
            }
            getchar();  // Catch '\n'
        }

        int found = 0;
        for (int i = 0; found < B; i++) {
            if (results[i-found] != i % 32) {
                printf("%d ", i);
                found++;
            }
        }
        putchar('\n');
        fflush(stdout);
        if (getchar() == '-') return 2;
        getchar();  // Catch '\n' from "1\n"
    }


    return 0;
}
