
#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n < 1) return 1;
    return n * factorial(n-1);
}

void findPosition(int pos, char result[6], char layout[595+1]) {
    if (result[pos-1] != 0) return;

    int freq[5] = {0};
    for (int i = 0; i < 119; i++) {
        if ((result[0] != 0 && layout[5*i+1] != result[0]) ||
            (result[1] != 0 && layout[5*i+2] != result[1]) ||
            (result[2] != 0 && layout[5*i+3] != result[2]) ||
            (result[3] != 0 && layout[5*i+4] != result[3]) ||
            (result[4] != 0 && layout[5*i+5] != result[4])) continue;

        printf("%d\n", 5*i+pos); fflush(stdout);
        layout[5*i+pos] = getchar();
        freq[layout[5*i+pos] - 'A']++;
        getchar(); // '\n'
    }

    int numKnown = 0;
    for (int i = 0; i < 5; i++) {
        if (result[i] != 0) numKnown++;
    }
    for (int i = 0; i < 5; i++) {
        if (result[0] == i+'A' || 
            result[1] == i+'A' ||
            result[2] == i+'A' ||
            result[3] == i+'A' ||
            result[4] == i+'A') continue;

        if (freq[i] < factorial(4-numKnown)) result[pos-1] = i + 'A';
    }
}

int main(void) {
    int T, F; scanf("%d %d", &T, &F); getchar(); // '\n'
    for (int t = 1; t <= T; t++) {
        char layout[595+1] = {0};
        char result[6] = {0};

        for (int i = 1; i <= 5; i++) {
            findPosition(i, result, layout);
        }

        // Return the result.
        printf("%s\n", result); fflush(stdout);
        if (getchar() == 'N') return 1;
        getchar(); // '\n'
    }
}
