
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HORIZONTAL 0
#define VERTICAL 1

typedef struct map Map;
typedef struct hint Hint;
typedef struct qItem QItem;

struct map {
	int row, col;
	char **grid;
	Hint **rowHints;
	Hint **colHints;
};

struct hint {
	int val;
	Hint *next;
	Hint *prev;
};

struct qItem {
	int dir;
	int rowcolnum;
	QItem *next;
};


/* ---------- Map Creation ----------*/
Hint *stringToHint(char *str) {
	Hint *curr;
	Hint *next;
	
	int index;
	int hintValue;

	index = 0;
	curr = next = NULL;
	while (str[index] != '\0') {
		if (str[index] >= '0' && str[index] <= '9') {
			next = malloc(sizeof(Hint));
			sscanf(&(str[index]), "%d", &(next->val));

			if (curr != NULL) curr->next = next;
			next->prev = curr;
			next->next = NULL;
			curr = next;

			while (str[index] >= '0' && str[index] <= '9') index++;
		} else {
			index++;
		}
	}

	while (curr != NULL && curr->prev != NULL) curr = curr->prev;
	return curr;
}

Map *getInput() {
	Map *m = malloc(sizeof(Map));
	
	scanf("%d\n", &(m->col));
	scanf("%d\n", &(m->row));
	
	m->grid = malloc(m->row * sizeof(int *));
	for (int i = 0; i < m->row; i++) {
		m->grid[i] = malloc(m->col * sizeof(char));
		memset(m->grid[i], 0, m->col * sizeof(char));
	}

	m->rowHints = malloc(m->row * sizeof(Hint *));
	m->colHints = malloc(m->col * sizeof(Hint *));
	memset(m->rowHints, 0, m->row * sizeof(Hint *));
	memset(m->colHints, 0, m->col * sizeof(Hint *));

	char buf[512];
	
	fgets(buf, 512, stdin);
	m->colHints[0] = stringToHint(strtok(buf, "\""));
	for (int i = 1; i < m->col; i++) {
		strtok(NULL, "\"");
		m->colHints[i] = stringToHint(strtok(NULL, "\""));
	}
	
	fgets(buf, 512, stdin);
	m->rowHints[0] = stringToHint(strtok(buf, "\""));
	for (int i = 1; i < m->row; i++) {
		strtok(NULL, "\"");
		m->rowHints[i] = stringToHint(strtok(NULL, "\""));
	}

	return m;
}

void showMap(Map *m) {
	printf("\nCols: %d\n", m->col);
	for (int i = 0; i < m->col; i++) {
		for (Hint *h = m->colHints[i]; h != NULL; h = h->next)
			printf("%d ", h->val);
		putchar('\n');
	}
	printf("\nRows: %d\n", m->row);
	for (int i = 0; i < m->row; i++) {
		for (Hint *h = m->rowHints[i]; h != NULL; h = h->next)
			printf("%d ", h->val);
		putchar('\n');
	}
}

/* ---------- Map Solver ---------- */
void checkRow(Map *m, int rowNum, QItem *q) {
	Hint *h = m->rowHints[rowNum];

	int i = 0;
	
}

void checkCol(Map *m, int colNum) {

}

void checkLine(Map *m, QItem *q) {

}

int main(void) {
	Map *m = getInput();
	printf("\n...");
	getchar();
	showMap(m);
	


	return 0;
}
