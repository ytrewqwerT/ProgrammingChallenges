// Time taken: 50 minutes

#include <stdio.h>

void decrement(char *N, int digits, int pos);

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		char N[20] = {0};
		int digits = 0;
		N[0] = getchar();
		while (N[0] < '0' || N[0] > '9') {N[0] = getchar();}
		while (N[digits] >= '0' && N[digits] <= '9') {
			N[++digits] = getchar();
		}
		for (int i = digits-1; i > 0; i--) {
			while (N[i] < N[i-1]) decrement(N, digits, i);
		}

		printf("Case #%d: ", testCase);
		int j = 0;
		while (N[j] == '0') j++;
		while (j < digits) {
			putchar(N[j]);
			j++;
		}
		putchar('\n');
	}

	return 1;
}

void decrement(char *N, int digits, int pos)
{
	N[pos]--;
	if (N[pos] < '0') {
		decrement(N, digits, pos-1);
	} else {
		for (int i = pos+1; i < digits; i++) {N[i] = '9';}
	}
}