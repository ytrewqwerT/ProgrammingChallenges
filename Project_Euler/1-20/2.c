// Problem 3: Even Fibonacci numbers
//
// Find the sum of even-valued fibonacci numbers below 4 million

#include <stdio.h>

#define BOUND 4000000

int main(void) {
    int a = 1;
    int b = 2;
    int sum = 2;
    int temp;
    while (b < BOUND) {
        temp = a + b;
        a = b;
        b = temp;
        if (b % 2 == 0) {
            sum += b;
        }
    }
    printf("Problem 2 result: %d\n", sum);
    return 0;
}