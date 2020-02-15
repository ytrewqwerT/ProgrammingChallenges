// Problem 24: Lexicographic permutations
//
// Find the millionth lexicographic permutation of the ten digits

#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int factorial(int n);
char getdigit(char digits[], int n);

int main(void) {
    char digits[] = "0123456789";
    char nthPerm[11] = {0};
    int currPerm = 0;
    
    for (int i = 9; i >= 0; i--) {
        int j = i;
        while (currPerm + j * factorial(i) >= N)
            j--;
        nthPerm[9-i] = getdigit(digits, j);
        currPerm += j * factorial(i);
    }
    
    printf("Problem 24 result: %s\n", nthPerm);
    
    return 0;
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

char getdigit(char digits[], int n) {
    char c = digits[n];
    for (int i = n; i < 11; i++) {
        digits[i] = digits[i+1];
    }
    return c;
}
