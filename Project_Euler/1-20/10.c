// Problem 10: Summation of primes
//
// Find the sum of all the primes below two million

#include <stdio.h>

#define BOUND 2000000

int is_prime(int n);

int main(void) {
    unsigned long long sum = 2;
    for (int i = 3; i < BOUND; i += 2) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    printf("Problem 10 result: %llu\n", sum);
    return 0;
}

int is_prime(int n) {
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}