
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int testCase = 1; testCase < T; testCase++) {
        int N, M;
        scanf("%d %d", &N, &M);
        char **array = malloc(N*sizeof(char*));
        for (int i = 0; i < N; i++) {
            array[i] = malloc(N*sizeof(char));
            memset(array[i], '.', N*sizeof(char));
        }
        for (int i = 0; i < M; i++) {
            char z;
            int x, y;
            scanf("%c %d %d", &z, &y, &x);
            assert(z == 'o' || z == '+' || z == 'x');
            array[y][x] = z;
        }

        
    }

    return EXIT_SUCCESS;
}