// Problem 6: Sum square difference
//
// Find the difference between the sum of the squares and the square of the sum of the first hundred naturals.

#include <stdio.h>

#define BOUND 100

int main(void) {
    int squareSum = 0;
    int sumSquare = 0;
    for (int i = 1; i <= BOUND; i++) {
        squareSum += i;
        sumSquare += i * i;
    }
    squareSum *= squareSum;
    printf("Problem 6 result: %d\n", (squareSum < sumSquare) * (sumSquare - squareSum)
                                     + (squareSum > sumSquare) * (squareSum - sumSquare));
    return 0;
}