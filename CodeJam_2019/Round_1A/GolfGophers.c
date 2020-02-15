
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int value;
    struct node *next;
    struct node *prev;
};

Node *newNode(int value) {
    Node *new = malloc(sizeof(*new));
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

// Free this and all following nodes in the list
void freeList(Node *n) {
    if (n == NULL) return;
    if (n->prev != NULL) n->prev->next = NULL;
    freeList(n->next);
    free(n);
}

int process(int sumRet[19], int max) {
    Node *possible = NULL;
    
    // Generate possibilities using r_18
    for (int i = 0; 18*i + sumRet[0] <= max; i++) {
        Node *new = newNode(18*i + sumRet[0]);
        new->next = possible;
        if (possible != NULL)
            possible->prev = new;
        possible = new;
    }

    // Remove possibilities by comparing to r_i for i=2..17
    for (int i = 1; i < 7; i++) {
        Node *curr = possible;
        while (curr != NULL) {
            if ( (curr->value - sumRet[i]) % (18-i) != 0 ) {
                // Remove the node
                if (curr->prev == NULL)
                    possible = curr->next;
                else
                    curr->prev->next = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = curr->prev;
                
                Node *temp = curr;
                curr = curr->next;
                free(temp);
            } else {
                curr = curr->next;
            }
        }
        if (possible->next == NULL) break;  // Only one possibility left
    }
    
    int result = possible->value;
    freeList(possible);
    return result;
}

int main(void) {
    int T, N, M;
    scanf("%d %d %d", &T, &N, &M); getchar();
    for (int t = 0; t < T; t++) {
        int guess = 1;
        int sumRet[7] = {0};
        int temp;
        for (int n = 0; n < 7; n++) {
            // Set all blades equal
            for (int i = 0; i < 18; i++)
                printf("%d ", 18-n);
            putchar('\n');
            fflush(stdout);

            // Sum the returned numbers to get a minimum
            for (int i = 0; i < 18; i++) {
                scanf("%d", &temp);
                if (temp == -1) exit(1);
                sumRet[n] += temp;
            }
        }
        printf("%d\n", process(sumRet, M));
        fflush(stdout);
        scanf("%d", &temp); getchar();
        if (temp == -1) exit(1);
    }
    return 0;
}
