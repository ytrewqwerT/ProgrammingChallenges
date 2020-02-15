
#include <stdio.h>
#include <stdlib.h>

typedef struct cashier {
	int numBits;
	int maxBits;
	int scanRate;
	int packRate;
} Cashier;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int R, B, C;
		scanf("%d %d %d", &R, &B, &C);
		if (C > 5) return EXIT_FAILURE;

		Cashier cashiers[5];
		for (int i = 0; i < C; i++) {
			cashiers[i].numBits = 0;
			scanf("%d %d %d", &cashiers[i].maxBits, &cashiers[i].scanRate, &cashiers[i].packRate);
		}

		printf("Test Case #%d: ", test);
	}
	return EXIT_SUCCESS;
}

/*

time = numBits * scanRate + packRate


----- Brute force:



*/