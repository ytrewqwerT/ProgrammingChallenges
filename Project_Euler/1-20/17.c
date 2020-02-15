// Problem 17: Number letter counts
//
// Find the letters used to write all numbers from 1 to 1000 (inclusive).

#include <stdio.h>

int main(void) {
    // single digits: 4, 3, 3, 5, 4, 4, 3, 5, 5, 4
    // teens:         3, 6, 6, 8, 8, 7, 7, 9, 8, 8
    // tee-s          -, -, 6, 6, 5, 5, 5, 7, 6, 6
    // hundred    7
    // thousand   8
    
    int digitLen[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    int teensLen[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int teesLen[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    int andLen = 3, hundredLen = 7, thousandLen = 8;
    
    int totalLen = 0;
    
    for (int i = 1; i <= 1000; i++) {
        if (i / 1000 >= 1) {                        // Check for thousands
            totalLen += digitLen[i / 1000];
            totalLen += thousandLen;
        }
        if (i / 100 % 10 >= 1) {                    // Check for hundreds
            totalLen += digitLen[i / 100 % 10];
            totalLen += hundredLen;
        }
        
        if ((i >= 100 && i % 100 > 0) ) {           // Check for 'and'
            totalLen += andLen;
        }
        
        if (i / 10 % 10 == 1) {                     // Check for teens
            totalLen += teensLen[i % 10];
        } else if (i / 10 % 10 >= 2) {              // Check for tens (excl. teens) and digits
            totalLen += teesLen[i / 10 % 10];
            totalLen += digitLen[i % 10];
        } else if (i / 10 % 10 == 0) {
            totalLen += digitLen[i % 10];
        }
    }
    
    printf("Problem 17 result: %d\n", totalLen);
    
    return 0;
}