
#include <stdio.h>
#include <stdlib.h>

#define MAX_S 100000

typedef struct {
    int C;
    int E;
} Slot;

// Sort by ascending order of coding/eating ratio.
int slotCompare(const void *A, const void *B) {
    Slot a = *((Slot *) A);
    Slot b = *((Slot *) B);

    double aRatio = ((double) a.C)/a.E;
    double bRatio = ((double) b.C)/b.E;
    
    if (aRatio > bRatio) {
        return 1;
    } else {
        return -1;
    }
}

int convertPartial(int codeSlack, int eatRemains, int C, int E) {
    double codeFraction = ((double) codeSlack)/C;
    double eatFraction = ((double) eatRemains)/E;

    return eatFraction <= codeFraction;
}


int main(void) {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int D, S; scanf("%d %d", &D, &S);
        Slot slots[MAX_S] = {0};
        for (int s = 0; s < S; s++) {
            scanf("%d %d", &(slots[s].C), &(slots[s].E));
        }
        
        // Sort timeslots and calculate maximum code possible.
        qsort(slots, S, sizeof(Slot), &slotCompare);
        int maxCoding = 0;
        for (int s = 0; s <= S; s++) {
            maxCoding += slots[s].C;
        }

        for (int d = 0; d < D; d++) {
            int minCode, minEat; scanf("%d %d", &minCode, &minEat);

            if (maxCoding < minCode) {
                putchar('N');
                continue;
            }
            
            // Start from maximum code and greedily increase eating.
            int coding = maxCoding;
            int eating = 0;
            int solved = 0;
            for (int s = 0; s < S; s++) {
                if (coding - slots[s].C >= minCode) {
                    coding -= slots[s].C;
                    eating += slots[s].E;
                    if (eating >= minEat) {
                        putchar('Y');
                        solved = 1;
                    }
                } else {
                    int codeSlack = coding - minCode;
                    int eatRemains = minEat - eating;

                    if (convertPartial(codeSlack, eatRemains, slots[s].C, slots[s].E)) {
                        putchar('Y');
                    } else {
                        putchar('N');
                    }
                    solved = 1;
                }

                if (solved) {
                    break;
                }
            }
        }
        putchar('\n');
    }

    return 0;
}
