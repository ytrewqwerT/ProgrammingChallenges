// Problem 15: Lattice paths
//
// Find the number of possible routes to traverse a 20 x 20 grid (see page for more details)
// Doesn't work due to integer overflow.

// Analysis of posible paths starting from a 1 x 1 grid and expanding results in Pascal's triangle:
//    1 - 1 - 1 - 1 - 1 
//    |   |   |   |   | 
//    1 - 2 - 3 - 4 - 5 
//    |   |   |   |   | 
//    1 - 3 - 6 - 10- 15
//    |   |   |   |   | 
//    1 - 4 - 10- 20- 35
//    |   |   |   |   | 
//    1 - 5 - 15- 35- 70
// The number of possible paths for an n x n grid corresponds to 2n choose n.

#include <stdio.h>

#define SIZE 20

long long unsigned factorial(int n);

int main(void) {
    printf("Problem 15 result: %llu\n", factorial(2 * SIZE) / factorial(SIZE) / factorial(SIZE));
    return 0;
}

long long unsigned factorial(int n) {
    printf(".");
    if (n == 1) {
        return (long long unsigned) 1;
    } else {
        return n * factorial(n - 1);
    }
}