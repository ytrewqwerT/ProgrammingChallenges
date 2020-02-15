// Problem 14: Longest Collatz sequence
//
// FInd the starting number under one million that produces the longest chain in the Collatz sequence

#include <stdio.h>

#define BOUND 1000000

int main(void) {
    long long unsigned longest = 1;
    int chainLength = 0;
    long long unsigned n;
    int nLength;
    for (int i = 1; i < BOUND; i++) {
        n = i;
        nLength = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            nLength++;
        }
        if (chainLength < nLength) {
            chainLength = nLength;
            longest = i;
        }
    }
    
    printf("Problem 14 result: %llu\n", longest);
    return 0;
}