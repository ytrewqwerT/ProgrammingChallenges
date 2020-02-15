// Problem 9: Special Pythagorean triplet
//
// Find the product of the Pythagorean triplet which sums to 1000

#include <stdio.h>

#define SUM 1000

int main(void) {
    int a, b;
    for (a = 1; a < SUM / 2; a++) {
        for (b = a + 1; b < SUM / 2; b++) {
            if (a*a + b*b == (SUM-a-b)*(SUM-a-b)) {
                printf("Problem 9 result: %d\n", a * b * (SUM-a-b));
            }
        }
    }
    
    return 0;
}
