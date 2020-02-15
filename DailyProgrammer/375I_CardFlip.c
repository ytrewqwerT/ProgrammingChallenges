
#include <stdio.h>

#define BUF_SIZE 128

int isSolved(char *seq) {
    while (*seq != '\0') {
        if (*seq == '0' || *seq == '1') return 0;
        seq++;
    }
    return 1;
}

void flip(char *seq) {
    int index = 0;
    while (seq[index] != '1' && seq[index] != '\0') index++;
    if (seq[index] == '\0' && !isSolved(seq)) printf("no solution\n");
    

}

int main(void) {
    char buf[BUF_SIZE] = {0};
    while (fgets(buf, BUF_SIZE, stdin) != NULL) {
        // Solve
    }

    return 0;
}
