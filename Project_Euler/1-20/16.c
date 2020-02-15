// Problem 16: Power digit sum
//
// Find the sum of the digits of 2 ^ 1000

#include <stdio.h>

int main(void) {
    // Approximate the length of 2^1000 using the 2^10 ~= 1000 == 10^3.
    //   2^1000 == 2 ^ 10 ^ 100 ~= 10 ^ 3 ^ 100 == 10 ^ 300
    // As this approximation underestimates the length (since 1000 < 1024), extra length is added.
    char number[310] = {0};
    number[0] = '1';
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; number[j] != '\0'; j++) {
            number[j] = (number[j] - '0') * 2 + '0';
        }
        
        for (int j = 0; number[j] != '\0'; j++) {
            while (number[j] > '9') {
                if (number[j + 1] == '\0') {
                    number[j + 1] = '0';
                }
                number[j] -= 10;
                number[j + 1] += 1;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        sum += number[i] - '0';
    }
    
    printf("Problem 16 result: %d\n", sum);
    
    return 0;
}