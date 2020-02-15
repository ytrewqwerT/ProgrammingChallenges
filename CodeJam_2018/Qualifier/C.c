
#include <stdio.h>
#include <stdlib.h>

#define REQ_WIDTH(A) (A%3 == 0 ? A/3 : A/3 + 1)

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		int A;
		scanf("%d", &A);
		char orchard[4][100] = {0};
		
		int col = 1;
		for (int turn = 1; turn <= 1000; turn++) {
			int pRow, pCol;

			printf("2 %d\n", col+1);
			fflush(stdout);
			scanf("%d %d", &pRow, &pCol);
			if (pRow == 0) break;
			if (pRow == -1 || turn == 1000) exit(EXIT_FAILURE);
			orchard[pRow][pCol] = 1;

			if (col < REQ_WIDTH(A) - 2) {
				for (int i = 1; i <= 3; i++) {
					if (orchard[i][col] == 0) break;
					if (i == 3) col++;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}
