
#include <stdio.h>

#define NUM_LEN 101

int main(void) {
    int T;
    scanf("%d", &T); getchar();
    for (int t = 1; t <= T; t++) {
        char N[NUM_LEN+1] = {0};

        fgets(N, NUM_LEN+1, stdin);

        printf("Case #%d: ", t);

        int loStarted = 0;
        for (int i = 0; N[i] >= '0' && N[i] <= '9'; i++) {
            if (N[i] == '4') {
                N[i] -= 1;
                
                putchar('1');
                loStarted = 1;
            } else if (loStarted == 1) {
                putchar('0');
            }
        }
        printf(" %s", N);
    }
    
    return 0;
}
