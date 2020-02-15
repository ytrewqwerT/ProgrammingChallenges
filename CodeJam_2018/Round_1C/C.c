
#include <stdio.h>
#include <stdlib.h>

typedef struct ant *Ant;

struct ant {
	int W;
	int amount;
	Ant next;
};

Ant newAnt();
Ant addAnt(Ant first);
void freeAnts(Ant first);
int stack(Ant first, int M, int W);

#define MIN(x, y) ( x < y ? x : y )

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int N; scanf("%d", &N);
		Ant first = NULL;
		for (int i = 0; i < N; i++) {
			first = addAnt(first);
		}

		fprintf(stderr, "The order of the ants:");
		for (Ant curr = first; curr != NULL; curr = curr->next) {
			for (int i = 0; i < curr->amount; i++)
				fprintf(stderr, " %d", curr->W);
		}
		putchar('\n');
		int lo = 0;
		int hi = N+1;
		while (lo +1 < hi) {
			if (stack(first, (lo+hi)/2, -1)) {
				fprintf(stderr, "Found a stack of size %d\n", (lo+hi)/2);
				lo = (lo+hi)/2;
			} else {
				fprintf(stderr, "There's no stack of size %d\n", (lo+hi)/2);
				hi = (lo+hi)/2 - 1;
			}
		}

		printf("Case #%d: %d\n", testCase, lo);
		freeAnts(first);
	}

	return EXIT_SUCCESS;
}

Ant addAnt(Ant first) {
	int W; scanf("%d", &W);
	if (first != NULL && W == first->W) {
		first->amount++;
	} else {
		Ant new = malloc(sizeof(struct ant));
		new->W = W;
		new->next = first;
		first = new;
	}
	return first;
}

void freeAnts(Ant first) {
	if (first == NULL) return;
	freeAnts(first->next);
	free(first);
}

// Checks if it is possible to create a stack of M ants with a maximum weight W using the given list of ants.
// Returns 1 if possible and 0 otherwise.
int stack(Ant first, int M, int W) {
	fprintf(stderr, "...Trying to find a stack of size %d with max weight %d\n", M, W);
	if (M == 0) return 1;
	if (first == NULL) return 0;

	if (first->amount > 1) {
		int W1 = W - first->W;
		int W2 = 6 * first->W;
		if (W < 0) W1 = W2;
		if (W1 >= 0) {
			first->amount--;
			int possible = stack(first, M-1, MIN(W1, W2));
			first->amount++;
			if (possible == 1) return 1;
		}
	}

	for (Ant curr = first; curr != NULL; curr = curr->next) {
		int W1 = W - curr->W;
		int W2 = 6 * curr->W;
		if (W < 0) W1 = W2;
		if (W1 < 0) continue;

		if (stack(curr->next, M - 1, MIN(W1, W2)))
			return 1;
	}
	return 0;
}