
#include <stdio.h>

#define BUF_SIZE 100001

int canMakePalindrome(char *str, int len) {
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[str[i]-'A']++;
    }
    int hasOdd = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            if (hasOdd) return 0;
            hasOdd++;
        }
    }
    return 1;
}

int main(void) {
    int T;
    scanf("%d", &T); getchar();
    for (int t = 1; t <= T; t++) {
        int N, Q;
        char str[BUF_SIZE] = {0};
        scanf("%d %d", &N, &Q); getchar();
        fgets(str, N+1, stdin);

        int numYes = 0;
        for (int i = 0; i < Q; i++) {
            int L, R;
            scanf("%d %d", &L, &R); getchar();

            numYes += canMakePalindrome(&(str[L-1]), R-L+1);
        }

        printf("Case #%d: %d\n", t, numYes);
    }

    return 0;
}
