
#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B) ( A < B ? A : B )
#define MAX(A, B) ( A < B ? B : A )

typedef unsigned int Word;
typedef struct node {
    Word value;
    Word amount;
    struct node *next;
} Node;
typedef struct queue {
    Node *head;
    Node *tail;
} *Queue;

Queue newqueue();
void freequeue(Queue q);
void enqueue(Queue q, Word value);
Word dequeue(Queue q);
void printqueue(Queue q);


int main(void)
{
    Word T, N, K;
    Word L, R;
    scanf("%d", &T);

    for (int testCase = 1; testCase < T+1; testCase++) {
        scanf("%d %d", &N, &K);

        Queue q = newqueue();
        enqueue(q, N);

        for (Word n = 0; n < K; n++) {
            // Find spot for person to occupy and occupy it.
            Word largest = dequeue(q);
            largest -= 1;
            
            switch (largest) {
            case 0:
                L = 0;
                R = 0;
                break;
            case 1:
                L = 0;
                R = 1;
                enqueue(q, R);
                break;
            default:
                L = largest / 2;
                R = largest / 2 + largest % 2;
                enqueue(q, R);
                enqueue(q, L);
            }
        }
        printf("Case #%d: %d %d\n", testCase, MAX(L, R), MIN(L, R));
        freequeue(q);
    }

    return EXIT_SUCCESS;
}

Queue newqueue()
{
    Queue new = malloc(sizeof(struct queue));
    new->head = new->tail = NULL;
    return new;
}

void freequeue(Queue q)
{
    while(q->head != NULL) {
        q->tail = q->head;
        q->head = q->head->next;
        free(q->tail);
    }
    free(q);
}

void enqueue(Queue q, Word value)
{
    for (Node *curr = q->head; curr != NULL; curr = curr->next) {
        if (curr->value == value) {
            curr->amount++;
            return;
        }
    }

    if (q->tail == NULL) {
        q->head = q->tail = malloc(sizeof(Node));
    } else {
        q->tail->next = malloc(sizeof(Node));
        q->tail = q->tail->next;
    }
    
    q->tail->next = NULL;
    q->tail->value = value;
    q->tail->amount = 1;
}

Word dequeue(Queue q)
{
    if (q->head->amount > 1) {
        q->head->amount--;
        return q->head->value;
    }
    Node *oldHead = q->head;
    Word value = oldHead->value;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = q->head;
    free(oldHead);
    return value;
}

void printqueue(Queue q)
{
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue state: [%d %d]", q->head->value, q->head->amount);
    for (Node *curr = q->head->next; curr != NULL; curr = curr->next) {
        printf(" [%d %d]", curr->value, curr->amount);
    }
    putchar('\n');
}