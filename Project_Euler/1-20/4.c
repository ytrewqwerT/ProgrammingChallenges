// Problem 4: Largest palindrome product
//
// Find the largest palindrome made from the product of two 3-digit numbers

#include <stdio.h>

#define DIGITS 3

int is_palindrome(int n);

int main(void) {
    int lowerBound = 1;
    int upperBound = 10;
    for (int i = 1; i < DIGITS; i++) {
        lowerBound *= 10;
        upperBound *= 10;
    }
    lowerBound -= 1;
    upperBound -= 1;
    int largest;
    for (int i = upperBound; i > lowerBound; i--) {
        for (int j = i; j > lowerBound; j--) {
            if (i * j > largest && is_palindrome(i * j)) {
                largest = i * j;
            }
        }
    }
    printf("Problem 4 result: %d\n", largest);
    return 0;
}

int is_palindrome(int n) {
    int length = 1;
    int lower, upper;
    int temp = n / 10;
    while (temp > 0) {
        temp /= 10;
        length++;
    }
    
    for (int i = 0; i < length / 2; i++) {
        upper = n;
        for (int j = 0; j < length - i - 1; j++) {
            upper /= 10;
        }
        upper %= 10;
        
        temp = 1;
        for (int j = 0; j < i; j++) {
            temp *= 10;
        }
        lower = (n / temp) % 10;
        
        if (lower != upper) {
            return 0;
        }
    }
    return 1;
}
