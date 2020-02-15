
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int sold[200] = {0};
		int frequency[200] = {0};
		
		int N; scanf("%d", &N);
		for (int person = 0; person < N; person++) {
			int likes[200] = {0};
			int D; scanf("%d", &D);
			int i;

			if (D == -1) return EXIT_SUCCESS;

			for (i = 0; i < D; i++) {
				scanf("%d", &likes[i]);
				frequency[likes[i]]++;
			}
			
			int toSell = -1;
			for (i = 0; i < D; i++) {
				if (sold[likes[i]] == 0) {
					toSell = likes[i++];
					break;
				}
			}

			while (i < D) {
				if (sold[likes[i]] == 0
					&& frequency[likes[i]] >= frequency[toSell]) {

					toSell = likes[i];
				}
				i++;
			}
			if (toSell != -1) {
				sold[toSell] = 1;
			}

			printf("%d\n", toSell);
			fflush(stdout);
		}
	}

	return EXIT_SUCCESS;
}
