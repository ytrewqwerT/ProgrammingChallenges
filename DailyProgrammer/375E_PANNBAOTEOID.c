
#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {
        int mag = 1;
        while (n/mag > 0) {
            mag *= 10;
        }
        mag /= 10;
        while (mag > 0) {
            printf("%d", n/mag + 1);
            n %= mag;
            mag /= 10;
        }
        putchar('\n');
    }

    return 0;
}
