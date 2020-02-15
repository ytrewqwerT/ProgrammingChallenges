// Problem 23: Non-abundant sums
//
// Find the sum of all positive integers which cannot be written as the sum of two abundant numbers

#include <stdio.h>
#include <stdlib.h>

typedef struct abundantNum {
    int num;
    struct abundantNum *next;
    struct abundantNum *prev;
} abundantNum;

abundantNum *newNum(int num);
int factorSum(int num);

int main(void) {
    int sum = 0;
    abundantNum *head = NULL;
    abundantNum *tail = NULL;
    abundantNum *node = NULL;
    abundantNum *item = NULL;
    
    for (int i = 1; i <= 28123; i++) {
        if (factorSum(i) > i) {
            node = newNum(i);
            if (head == NULL)
                head = tail = node;
            else {
                node->prev = tail;
                tail = tail->next = node;
            }
        }
    }
    
    for (int i = 1; i <= 28123; i++) {
        int sentinel = 0;
        item = head;
        node = tail;
        while (item->num <= node->num) {
            int n = item->num + node->num;
            if (n == i) {
                sentinel = 1;
                break;
            } else if (n < i) {
                item = item->next;
            } else if (n > i) {
                node = node->prev;
            }
            if (node == NULL || item == NULL || item->num > node->num)
                break;
        }
        if (sentinel == 0)
            sum += i;
    }
    
    while (head != NULL) {
        tail = head->next;
        free(head);
        head = tail;
    }
    
    printf("Problem 23 result: %d\n", sum);
    
    return 0;
}

abundantNum *newNum(int num) {
    abundantNum *new = malloc(sizeof (abundantNum));
    new->num = num;
    new->next = NULL;
    new->prev = NULL;
}

int factorSum(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}
