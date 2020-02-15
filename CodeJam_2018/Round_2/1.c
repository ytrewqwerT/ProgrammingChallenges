
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct row {
	char *layout;
	struct row *next;
} *Row;

typedef struct grid {
	int width;
	int nRows;
	Row rows;
} *Grid;

Grid process(int C, int *B);
void connect(Grid g, int src, int dest);
void addSlope(Grid g, int row, int col, char slope);
void addRow(Grid g);
Grid newGrid(int C);
void freeGrid(Grid g);

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int C; scanf("%d", &C);
		int *B = malloc(C * sizeof(int));
		for (int i = 0; i < C; i++) scanf("%d", &B[i]);

		Grid result = process(C, B);

		printf("Case #%d: ", testCase);
		if (result == NULL) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", result->nRows);
			for (Row r = result->rows; r != NULL; r = r->next) {
				for (int i = 0; i < C; i++) putchar(r->layout[i]);
				putchar('\n');
			}
			freeGrid(result);
		}

		free(B);
	}

	return EXIT_SUCCESS;
}

// Processes the data to create a possible layout if possible.
Grid process(int C, int *B) {
	if (B[0] == 0 || B[C-1] == 0) return NULL;

	Grid result = newGrid(C);
	int cBall = 0;
	for (int col = 0; col < C; col++) {
		// Slide the balls into the columns one-by-one.
		while (B[col] > 0) {
			connect(result, cBall, col);
			B[col]--;
			cBall++;
		}
	}
	addRow(result);

	return result;
}

// Guides the ball dropping from C1 into C2.
void connect(Grid g, int src, int dest) {
	char slope;
	if (src > dest) slope = '/';
	else            slope = '\\';

	int row = 0;
	while (src != dest) {
		addSlope(g, row, src, slope);

		row++;
		src += (slope == '/') ? -1 : 1;
	}
}

// Adds the given slope to the given position in the grid.
void addSlope(Grid g, int row, int col, char slope) {
	if (row == g->nRows) addRow(g);

	Row r = g->rows;
	while (row > 0) {
		r = r->next;
		row--;
	}
	r->layout[col] = slope;
}

// Adds a row to the grid.
void addRow(Grid g) {
	Row new = malloc(sizeof(struct row));
	new->layout = malloc(g->width * sizeof(char));
	memset(new->layout, '.', g->width * sizeof(char));
	new->next = NULL;

	if (g->nRows == 0) {
		g->rows = new;
	} else {
		Row r = g->rows;
		for (int i = 1; i < g->nRows; i++) r = r->next;
		r->next = new;
	}
	g->nRows++;
}


Grid newGrid(int C) {
	Grid new = malloc(sizeof(struct grid));
	new->width = C;
	new->nRows = 0;
	new->rows = NULL;

	return new;
}

void freeGrid(Grid g) {
	Row r = g->rows;
	while (r != NULL) {
		Row n = r->next;
		free(r->layout);
		free(r);
		r = n;
	}
	free(g);
}
