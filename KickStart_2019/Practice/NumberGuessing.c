
#include <stdio.h>
#include <string.h>

#define CEIL_MEAN(A,B) ((A+B)/2 + (A+B)%2)

int main(int argc, char **argv) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int A, B, N;
        char buf[16];
        
        scanf("%d %d %d", &A, &B, &N);
        
        for (int i = 0; i < N; i++) {
            printf("%d\n", CEIL_MEAN(A,B));
            fflush(stdout);
            
            while (strncmp(fgets(buf, 16, stdin), "\n", 1) == 0) {}
            if (strncmp(buf, "CORRECT", 7) == 0) {
                break;
            } else if (strncmp(buf, "TOO_SMALL", 9) == 0) {
                A = CEIL_MEAN(A,B);
            } else if (strncmp(buf, "TOO_BIG", 7) == 0) {
                B = CEIL_MEAN(A,B);
            } else if (strncmp(buf, "WRONG_ANSWER", 9) == 0) {
                return 1;
            }
        }
    }
    
    return 0;
}
