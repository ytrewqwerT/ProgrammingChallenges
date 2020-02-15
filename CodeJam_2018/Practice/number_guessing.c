
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void error(const char *msg);

int main(void)
{
    char buf[256] = {0};
    int T, A, B, N, Q;
    fprintf(stderr, "Program Start:\n");
    if (fgets(buf, 255, stdin) == NULL) error("Failed to read line");
    if (sscanf(buf, "%d", &T) != 1) error("Failed to retrieve T");
    fprintf(stderr, "Got T = %d\n", T);
    for (int i = 0; i < T; i++) {
        if (fgets(buf, 255, stdin) == NULL) error("Failed to read line");
        if (sscanf(buf, "%d %d", &A, &B) != 2) error("Failed to retrieve A, B");
        fprintf(stderr, "Got A, B = %d, %d\n", A, B);

        if (fgets(buf, 255, stdin) == NULL) error("Failed to read line");
        if (sscanf(buf, "%d", &N) != 1) error("Failed to retrieve N");
        fprintf(stderr, "Got N = %d\n\n", N);

        for (int j = 0; j < N; j++) {
            Q = A + ceil( (double) (B-A) / 2);
            printf("%d\n", Q);
            fflush(stdout);
            fprintf(stderr, "Sent: Q = %d\n", Q);

            if (fgets(buf, 255, stdin) == NULL) error("Failed to read line");
            if (strncmp(buf, "CORRECT", 7) == 0) {
                fprintf(stderr, "Got Response: CORRECT\n\n");
                break;
            } else if (strncmp(buf, "TOO_SMALL", 9) == 0) {
                fprintf(stderr, "Got Response: TOO_SMALL... ");
                A = Q;
            } else if (strncmp(buf, "TOO_BIG", 7) == 0) {
                fprintf(stderr, "Got Response: TOO_BIG... ");
                B = Q;
            } else if (strncmp(buf, "WRONG_ANSWER", 12) == 0) {
                fprintf(stderr, "Got Response: WRONG_ANSWER\n");
                exit(EXIT_SUCCESS);
            } else {
                error("Unknown response");
            }
        }
    }

    return EXIT_SUCCESS;
}

void error(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}