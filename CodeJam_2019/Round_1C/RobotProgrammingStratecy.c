
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 502

typedef struct node Node;
struct node {
    char *program;
    int len;
    Node *next;
};

Node *newNode(char *program) {
    Node *new = malloc(sizeof(*new));
    new->program = strdup(program);
    new->len = strlen(new->program);
    new->next = NULL;
    return new;
}

Node *removeNode(Node *n, Node *head) {
    if (head == NULL) return NULL;
    if (n == head) {
        Node *next = n->next;
        free(n->program);
        free(n);
        return next;
    }
    head->next = removeNode(n, head->next);
    return head;
}

Node *addNode(Node *n, Node *head) {
    n->next = head;
    return n;
}

Node *removeDefeated(int moveIndex, char move, Node *head) {
    if (head == NULL) return NULL;
    head->next = removeDefeated(moveIndex, move, head->next);
    
    int defeated = 0;
    char headMove = head->program[moveIndex % head->len];
    if      (move == 'R' && headMove == 'S') defeated = 1;
    else if (move == 'P' && headMove == 'R') defeated = 1;
    else if (move == 'S' && headMove == 'P') defeated = 1;

    if (defeated) head = removeNode(head, head);
    return head;
}

void freeList(Node *head) {
    if (head == NULL) return;
    freeList(head->next);
    free(head->program);
    free(head);
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int A;
        scanf("%d", &A); getchar();

        Node *adversaries = NULL;

        for (int a = 0; a < A; a++) {
            char buf[BUF_LEN] = {0};
            fgets(buf, BUF_LEN, stdin);
            for (int i = 0; buf[i] != '\0'; i++) {
                if (buf[i] == '\n') buf[i] = '\0';
                if (buf[i] == '\0') break;
            }
            adversaries = addNode(newNode(buf), adversaries);
        }

        char myProgram[BUF_LEN] = {0};
        int possible = 1;

        for (int i = 0; i < 500 && possible && adversaries != NULL; i++) {
            int R, P, S;
            R = P = S = 0;
            for (Node *curr = adversaries; curr != NULL; curr = curr->next) {
                char c = curr->program[i % curr->len];
                switch (c) {
                    case 'R': R = 1; break;
                    case 'P': P = 1; break;
                    case 'S': S = 1; break;
                    default: return 1;
                }
            }
            
            if (R && P && S) possible = 0;
            else if (R && P) myProgram[i] = 'P';
            else if (P && S) myProgram[i] = 'S';
            else if (S && R) myProgram[i] = 'R';
            else if (R)      myProgram[i] = 'P';
            else if (P)      myProgram[i] = 'S';
            else if (S)      myProgram[i] = 'R';
            else             break; // No adversaries left.

            if (possible) adversaries = removeDefeated(i, myProgram[i], adversaries);
        }
        freeList(adversaries);

        printf("Case #%d: ", t);
        if (possible) printf("%s\n", myProgram);
        else          printf("IMPOSSIBLE\n");
    }

    return 0;
}
