// Problem 1: Multiples of 3 and 5.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <stdio.h>

#define BOUND 1000

int main(void) {
    int sum = 0;
    for (int i = 1; i < BOUND; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("Problem 1 result: %d\n", sum);
    return 0;
}
