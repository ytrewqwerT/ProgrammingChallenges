
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkWord(char *word, char **words, int numWords);

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int N, L; scanf("%d %d", &N, &L);
		getchar();
		char **words = malloc(N*sizeof(char *));

		char *word = malloc((L+1)*sizeof(char));
		for (int i = 0; i < N; i++) {
			fgets(word, L+1, stdin);
			getchar();
			words[i] = strdup(word);
		}

		word = strdup(words[0]);
		// Starting from the last character, check every possible permutation.
		for (int i = L-1; i >= 0; i++) {
			
		}

		printf("Case #%d: ", testCase);
	}

	return EXIT_SUCCESS;
}

// Returns 1 if already taken, 0 if not.
int checkWord(char *word, char **words, int numWords) {
	for (int i = 0; i < numWords; i++)
		if (strcmp(word, words[i]) == 0)
			return 1;
	return 0;
}