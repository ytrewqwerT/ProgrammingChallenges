
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int N;
		int *V;
		scanf("%d", &N);
		V = malloc(N*sizeof(int));
		for (int i = 0; i < N; i++) scanf("%d", &V[i]);

		int done = 0;
		while (!done) {
			done = 1;
			for (int i = 0; i < N-2; i++) {
				if (V[i] > V[i+2]) {
					done = 0;
					int temp = V[i];
					V[i] = V[i+2];
					V[i+2] = temp;
				}
			}
		}

		printf("Case #%d: ", test);
		for (int i = 0; i < N-1; i++) {
			if (V[i] > V[i+1]) {
				printf("%d\n", i);
				break;
			}
			if (i == N-2) {
				printf("OK\n");
			}
		}
	}

	return EXIT_SUCCESS;
}
