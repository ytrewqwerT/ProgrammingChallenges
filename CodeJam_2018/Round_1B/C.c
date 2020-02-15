
#include <stdio.h>
#include <stdlib.h>

typedef struct recipe {
	int G;
	int R1;
	int R2;
} R;

int makeMetal(R *recipies, int metal, int *producing, int numProducing);

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int M; scanf("%d", &M);
		R *recipies = malloc((M+1) * sizeof(R));
		for (int i = 1; i <= M; i++)
			scanf("%d %d", &recipies[i].R1, &recipies[i].R2);
		for (int i = 1; i <= M; i++)
			scanf("%d", &recipies[i].G);

		int *producing = malloc(M * sizeof(int));
		
		while (makeMetal(recipies, 1, producing, 0)) {}

		printf("Case #%d: %d\n", testCase, recipies[1].G);

		free(recipies);
		free(producing);
	}

	return EXIT_SUCCESS;
}

int makeMetal(R *recipies, int metal,  int *producing, int numProducing) {
	int R1 = recipies[metal].R1;
	int R2 = recipies[metal].R2;

	if (R1 == 1 || R2 == 1)
		return 0;
	
	// Prevent circular recipies.
	for (int i = 0; i < numProducing; i++)
		if (metal == producing[i])
			return 0;

	// Try to produce the current metal.
	producing[numProducing++] = metal;

	if (recipies[R1].G == 0)
		makeMetal(recipies, R1, producing, numProducing);
	if (recipies[R2].G == 0)
		makeMetal(recipies, R2, producing, numProducing);

	numProducing--;

	if (recipies[R1].G > 0 && recipies[R2].G > 0) {
		recipies[R1].G--;
		recipies[R2].G--;
		recipies[metal].G++;
		return 1;
	}
	return 0;
}
