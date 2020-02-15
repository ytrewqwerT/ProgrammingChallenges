
#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
typedef struct queue *Queue;
typedef struct leave *Leave;

struct node {
	int value;
	int required;
	int amount;
	Node next;
};

struct queue {
	Node head;
	Node tail;
};

Queue newqueue();
void enqueue(Queue q, int value, int required);
void freequeue(Queue q);
int dequeue(Queue q, int *value, int *required);
int compare(int N, int v1, int v2);

int roundsUp(int value, int N);

int main(void) {
	int T;
	scanf("%d", &T);
	for (int testCase = 1; testCase <= T; testCase++) {
		Queue dn = newqueue();
		Queue up = newqueue();
		int N, L;
		int value, required;
		int count = 0;

		scanf("%d %d", &N, &L);
		for (int i = 0; i < L; i++) {
			int C;
			scanf("%d", &C);
			count += C;

			if (roundsUp(C, N)) {
				enqueue(up, C, 0);
			} else {
				required = 0;
				while (!roundsUp(C+required, N)) required++;
				enqueue(dn, C, required);
			}
		}
		required = 0;
		while (!roundsUp(required, N)) required++;
		for (int i = 0; i < (N-L); i++) enqueue(dn, 0, required);
		

		while (count < N) {
			if (!dequeue(dn, &value, &required)) return EXIT_FAILURE;
			count += required;
			if (count > N) {
				enqueue(dn, value, required);
				count -= required;
				break;
			} else {
				enqueue(up, value + required, 0);
			}
		}

		int percent = 0;
		while (dequeue(up, &value, &required)) {
			percent += 100 * value / N;
			
			if (100 * value % N > 0) percent++;
		}
		while (dequeue(dn, &value, &required)) {
			percent += 100 * value / N;
		}
		while (count < N) {
			percent += 100 * 1 / N;
			count += 1;
		}

		printf("Case #%d: %d\n", testCase, percent);

		freequeue(dn);
		freequeue(up);
	}
}

Queue newqueue() {
	Queue q = malloc(sizeof(struct queue));
	q->head = q->tail = NULL;
	return q;
}

void freequeue(Queue q) {
	while (q->head != NULL) {
		q->tail = q->head->next;
		free(q->head);
		q->head = q->tail;
	}
	free(q);
}
Node addNode(Node head, int value, int required) {
	if (head == NULL || head->required > required) {
		Node new = malloc(sizeof(struct node));
		new->value = value;
		new->required = required;
		new->amount = 1;
		new->next = head;
		head = new;
	} else if (head->value == value) {
		head->amount++;
	} else {
		head->next = addNode(head->next, value, required);
	}
	return head;
}

void enqueue(Queue q, int value, int required) {
	q->head = addNode(q->head, value, required);
	if (q->tail == NULL) q->tail = q->head;
	else if (q->tail->next != NULL) q->tail = q->tail->next;
}

int dequeue(Queue q, int *value, int *required) {
	if (q->head == NULL) return 0;

	*value = q->head->value;
	*required = q->head->required;

	q->head->amount--;
	if (q->head->amount == 0) {
		Node del = q->head;
		q->head = q->head->next;
		if (q->head == NULL) q->tail == NULL;
		free(del);
	}
	return 1;
}

int roundsUp(int value, int N) {
	if (value == 0) return 0;

	int remainder = 100 * value % N;
	if (remainder == 0 || remainder >= N/2 + N%2) return 1;
	return 0;
}