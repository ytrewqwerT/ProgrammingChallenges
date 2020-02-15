
#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (X > Y ? X : Y)
#define MIN(X, Y) (X < Y ? X : Y)
#define INCREMENT(X, Y) (X < Y ? X++ : Y++)

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int R, B; scanf("%d %d", &R, &B);
		printf("Case #%d: %d\n", testCase, getCount(MAX(R, B), MIN(R, B)));
	}

	return EXIT_SUCCESS;
}

int getCount(int hi, int lo) {
	int A = 1;
	int B = 0;

	while (hi >= A && lo >= B) {
		INCREMENT(A, B);
	}
}
