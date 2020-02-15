// Problem 21: Amicable numbers
//
// Evaluate the sum of all amicable numbers below 10000

#include <stdio.h>
#include <stdlib.h>

int factorSum(int num);

int main(void) {
    int sum = 0;
    
    for (int i = 1; i < 10000; i++) {
        if (factorSum(factorSum(i)) == i && factorSum(i) != i)
            sum += i;
    }
    
    printf("Problem 21 result: %d\n", sum);
    
    return 0;
}

int factorSum(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}
