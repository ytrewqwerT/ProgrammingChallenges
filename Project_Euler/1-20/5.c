// Problem 5: Smallest multiple
//
// Find the smallest positive number evenly divisble by all numbers from 1 to 20

#include <stdio.h>

#define BOUND 20

int main(void) {
    for (int i = BOUND; 1; i += BOUND) {
        for (int j = 1; j <= BOUND; j++) {
            if (i % j != 0) {
                break;
            }
            if (j == BOUND) {
                printf("Problem 5 result: %d\n", i);
                return 0;
            }
        }
    }
}