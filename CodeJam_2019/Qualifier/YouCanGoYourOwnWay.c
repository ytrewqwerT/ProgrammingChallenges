

#include <stdio.h>

int main(void) {
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d\n", &N);
        
        printf("Case #%d: ", t);
        
        for (int i = 0; i < 2*N-2; i++) {
            if (getchar() == 'S') {
                putchar('E');
            } else {
                putchar('S');
            }
        }
        getchar();
        putchar('\n');
    }
    
    return 0;
}
