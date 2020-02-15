// Problem 20: Factorial digit sum
//
// Find the sum of the digits in 100!

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int sum = 0;
    int num[500] = {0};
    int numlen = 1;
    num[0] = 1;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < numlen; j++) {
            num[j] *= i;
        }
        for (int j = 0; j < numlen; j++) {
            while (num[j] > 9) {
                if (num[j+1] == 0 && j+1 == numlen)
                    numlen++;
                num[j] -= 10;
                num[j+1] += 1;
            }
        }
        
        printf("%d! = ", i);
        for (int j = numlen - 1; j >= 0; j--)
            putchar(num[j] + '0');
        putchar('\n');
    }
    
    for (int i = 0; i < numlen; i++) {
        sum += num[i];
    }
    
    printf("Problem 20 result: %lu\n", sum);
    
    return 0;
}
