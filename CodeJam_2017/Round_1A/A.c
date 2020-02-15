
#include <stdio.h>
#include <assert.h>

void fill(char cake[27][27], int sRow, int sCol, int eRow, int eCol);

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int R, C;
		char cake[27][27] = {0};
		scanf("%d %d\n", &R, &C);
		for (int i = 0; i < R; i++) {fgets(cake[i], 27, stdin);}

		fill(cake, 0, 0, R-1, C-1);

		printf("Case #%d:\n", testCase);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				putchar(cake[i][j]);
			}
			putchar('\n');
		}
	}

	return 0;
}

void fill(char cake[27][27], int sRow, int sCol, int eRow, int eCol)
{
	int letter = 0;
	int letRow, letCol;
	for (int row = sRow; row <= eRow; row++) {
		for (int col = sCol; col <= eCol; col++) {
			if (cake[row][col] != '?') {
				if (letter == 0) {
					letRow = row;
					letCol = col;
					letter = cake[row][col];
				} else {
					if (row == letRow) {
						fill(cake, sRow, sCol, eRow, col-1);
						fill(cake, sRow, col, eRow, eCol);
					} else {
						fill(cake, sRow, sCol, row-1, eCol);
						fill(cake, row, sCol, eRow, eCol);
					}
					return;
				}
			}
		}
	}

	for (int row = sRow; row <= eRow; row++) {
		for (int col = sCol; col <= eCol; col++) {
			cake[row][col] = letter;
		}
	}
}