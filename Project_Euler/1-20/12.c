// Problem 12: Highly divisible triangular number
//
// Find the first triangle number to have over five hundred divisors

#include <stdio.h>

#define BOUND 500

int divisors(int n);

int main(void) {
    int num = 0;
    
    for (int i = 1; 1; i++) {
        num += i;
        if (divisors(num) > BOUND) {
            printf("Problem 12 result: %d\n", num);
            return 0;
        }
    }
}

int divisors(int n) {
    int factors = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors++;
        }
    }
    return factors;
}
