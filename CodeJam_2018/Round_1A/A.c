
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);
		int R, C, H, V;
		scanf("%d %d %d %d\n", &R, &C, &H, &V);

		char waffle[100][100] = {0};
		int nChoc = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				waffle[i][j] = getchar() == '@';
				if (waffle[i][j] == 1) nChoc++;
			}
			getchar();
		}

		// Solution starts here
		if (nChoc % ((V+1)*(H+1)) != 0) goto impossible;
		
		int choc = nChoc / ((V+1)*(H+1));

		for (int row = 0; row < R-1; row++) {
			for (int col = 0; col < C-1; col++) {
				int sum;
				
				// Top left quadrant
				sum = 0;
				for (int i = 0; i <= row; i++) {
					for (int j = 0; j <= col; j++) {
						sum += waffle[i][j];
					}
				}
				if (sum != choc) continue;

				// Top right quadrant
				sum = 0;
				for (int i = 0; i <= row; i++) {
					for (int j = col+1; j < C; j++) {
						sum += waffle[i][j];
					}
				}
				if (sum != choc) continue;

				// Bottom right quadrant
				sum = 0;
				for (int i = row+1; i < R; i++) {
					for (int j = col+1; j < C; j++) {
						sum += waffle[i][j];
					}
				}
				if (sum != choc) continue;

				// Bottom left quadrant
				sum = 0;
				for (int i = row+1; i < R; i++) {
					for (int j = 0; j <= col; j++) {
						sum += waffle[i][j];
					}
				}
				if (sum == choc) goto possible;
			}
		}
impossible:
		printf("IM");
possible:
		printf("POSSIBLE\n");
	}
	return EXIT_SUCCESS;
}

