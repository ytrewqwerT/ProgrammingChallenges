// Problem 3: Largest prime factor
//
// Find the largest prime factor of 600851475143

#include <stdio.h>

#define NUMBER 600851475143

int main(void) {
    unsigned long long num = NUMBER;
    unsigned long long factor;
    for (unsigned long long i = 2; i <= num; i++) {
        if (num % i == 0) {
            factor = i;
            num /= i;
            i--;
        }
    }
    printf("Problem 3 result: %llu\n", factor);
    return 0;
}