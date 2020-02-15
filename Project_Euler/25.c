// Problem 25: 1000-digit Fibonacci number
//
// Find the index of the first term in the Fibonacci sequence with 1000 digits

#include <stdio.h>
#include <stdlib.h>

#define NUMLEN 1000

void copy(char *dest, char * src, int length);

int main(void) {
    char num[NUMLEN+5] = {0};
    char num1[NUMLEN+5] = {0};
    char num2[NUMLEN+5] = {0};
    int length = 1;
    int index = 1;
    
    num1[0] = 1;
    num2[0] = 0;
    
    while (length < 1000) {
        copy(num, num1, length);
        for (int i = 0; i < length; i++)
            num[i] += num2[i];
        for (int i = 0; i < length; i++) {
            while (num[i] > 9) {
                if (i+1 >= length)
                    length++;
                num[i] -= 10;
                num[i+1] += 1;
            }
        }
        index++;
        copy(num2, num1, length);
        copy(num1, num, length);
    }
    
    printf("Problem 25 result: %d\n", index);
    
    return 0;
}

void copy(char *dest, char * src, int length) {
    for (int i = 0; i < length; i++)
        dest[i] = src[i];
}
