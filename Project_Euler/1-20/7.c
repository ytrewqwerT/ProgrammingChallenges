// Problem 7: 10001st prime
//
// Find the 10001st prime number

#include <stdio.h>

#define NTH 10001

int main(void) {
    int primes = 2;
    for (int i = 5; 1; i += 2) {
        for (int j = 3; j < i; j += 2) {
            if (i % j == 0) {
                break;
            }
            if (j == i - 2) {
                primes++;
                if (primes == NTH) {
                    printf("Problem 7 result: %d\n", i);
                    return 0;
                }
            }
        }
    }
}