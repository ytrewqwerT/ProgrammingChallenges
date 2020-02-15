
#include <stdio.h>
#include <stdlib.h>

int damage(char P[32]);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int D;
		char P[32] = {0};
		scanf("%d %s", &D, P);

		int swaps = 0;
		
		int i = 29;
		while (damage(P) > D) {
			while (i >= 0 && (P[i] == '\0' || P[i] == '\n')) i--;
			while (i >= 0 && (P[i] == 'C')) i--;
			while (i >= 0 && P[i] == 'S') i--;
			if (i < 0) break;

			char temp = P[i];
			P[i] = P[i+1];
			P[i+1] = temp;
			i += 2;
			swaps++;
		}
		printf("Case #%d: ", test);
		i >= 0 ? printf("%d\n", swaps) : printf("IMPOSSIBLE\n");
	}

	return EXIT_SUCCESS;
}

int damage(char P[32]) {
	int total = 0;
	int power = 1;
	for (int i = 0; P[i] == 'S' || P[i] == 'C'; i++) {
		if (P[i] == 'S')
			total += power;
		else
			power *= 2;
	}
	return total;
}
