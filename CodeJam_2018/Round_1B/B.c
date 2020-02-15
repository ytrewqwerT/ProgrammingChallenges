
#include <stdio.h>
#include <stdlib.h>

typedef struct sign *Sign;

struct sign {
	int left;			// The absolute position to the left of the sign that the sign points to.
	int right;			// The absolute position to the right of the sign that the sign points to.
	Sign next;			// A pointer to the next sign.
};

int recursion(Sign head, int L, int R, int L1, int R1, int L2, int R2, int length);
Sign getSign();
void freeSigns(Sign head);

#define NOT_SET -1000000

int main(void) {
	int T; scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		int S; scanf("%d", &S);
		Sign list = getSign();
		Sign curr = list;
		for (int i = 1; i < S; i++) {
			curr->next = getSign();
			curr = curr->next;
		}
		



		printf("Case #%d: %d %d\n", testCase, maxLength, numMax);

		free(signs);
	}
}

int recursion(Sign head, int L, int R, int L1, int R1, int L2, int R2, int length) {
	if (head == NULL) return length;

	if (L1 == NOT_SET && R1 == NOT_SET)
		return recursion(head->next, L, R, head->left, head->right, R1, R2, 1);
	else if (L2 == NOT_SET && R2 == NOT_SET) {
		if (head->left != L1 || head->right != R1)
			return recursion(head->next, L, R, L1, R1, head->left, head->right, length + 1);
		else
			return recursion(head->next, L, R, L1, R1, L2, R2, length + 1);
	} else if (L == NOT_SET && R == NOT_SET) {
		// Values for L and R have not been decided yet.
		int left = head->left;
		int right = head->right;

		if (left != L1 && left != L2 || right != R1 && right != R2)
			return length;
		else if (left == L1 && right == R1 || left == L2 && right == R2)
			return recursion(head->next, L, R, L1, R1, L2, R2, length + 1);
		
		if (left != L1 || left != L2)



	} else if (L== NOT_SET || R == NOT_SET) {

	} else {
		if (head->left == L && head->right == R)
			return recursion(head->next, L, R, L1, R1, L2, R2, length + 1);
		return length;
	}
}

Sign getSign() {
	int D, A, B; scanf("%d %d %d", &D, &A, &B);
	Sign sign = malloc(sizeof(struct sign));
	sign->left  = D - B;
	sign->right = D + A;
	sign->next = NULL;
	return sign;
}

void freeSigns(Sign head) {
	if (head == NULL) return;
	freeSigns(head->next);
	free(head);
}