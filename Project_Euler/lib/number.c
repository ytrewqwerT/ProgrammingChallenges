
#include <stdlib.h>
#include "number.h"

// Returns a new intStruct node.
intStruct *new_intStruct() {
    intStruct *node = malloc(sizeof (intStruct));
    node->value = 0;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

// Deletes an intStruct integer (including freeing memory).
void delete_intStruct(intStruct *a) {
    intStruct *node = a;
    intStruct *next;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
}

// Returns a copy of a.
intStruct *copy_intStruct(intStruct *a) {
    intStruct *copy = new_intStruct();
    copy->value = a->value;
    a = a->next;
    
    intStruct *copyRef = copy;
    while (a != NULL) {
        copyRef->next = new_intStruct();
        copyRef->next->previous = copyRef;
        copyRef = copyRef->next;
        copyRef->value = a->value;
        a = a->next;
    }
    return copy;
}

// Checks for and carries over any overflow (or underflow) in a digit.
// Underflows resulting in a negative number replaces the number with -1.
void overflow_intStruct(intStruct *a) {
    while (a->value >= 1000) {
        if (a->next == NULL) {
            a->next = new_intStruct();
            a->next->previous = a;
        }
        a->next->value += 1;
        a->value -= 1000;
        if (a->value < 1000) {
            a = a->next;
        }
    }
    
    while (a->value < 0) {          // What to do if a->next == NULL (i.e. the number should be negative)?
        a->next->value -= 1;
        a->value += 1000;
        if (a->value >= 0) {
            a = a->next;
        }
    }
}

// Returns a + b.
intStruct *add_intStruct(intStruct *a, intStruct *b) {
    intStruct *result = copy_intStruct(a);
    intStruct *resultRef = result;
    
    resultRef->value += b->value;
    overflow_intStruct(resultRef);
    
    while (b->next != NULL) {
        if (resultRef->next == NULL) {
            resultRef->next = new_intStruct();
            resultRef->next->previous = resultRef;
        }
        resultRef = resultRef->next;
        b = b->next;
        resultRef->value += b->value;
        overflow_intStruct(resultRef);
    }
    
    return result;
}

// Returns a - b.
intStruct *subtract_intStruct(intStruct *a, intStruct *b) {
    intStruct *result = copy_intStruct(a);
    intStruct *resultRef = result;
    
    resultRef->value -= b->value;
    overflow_intStruct(resultRef);
    
    while (b->next != NULL) {
        if (resultRef->next == NULL) {
            resultRef->next = new_intStruct();
            resultRef->next->previous = resultRef;
        }
        resultRef = resultRef->next;
        b = b->next;
        resultRef->value -= b->value;
        overflow_intStruct(resultRef);
    }
    
    return result;
}

// Returns a * b.
intStruct *multiply_intStruct(intStruct *a, intStruct *b) {
    intStruct *result = copy_intStruct(a);
    intStruct *resultRef = result;
    intStruct *bRef = b;
    
    int i = 0;
    while (bRef != NULL) {
        resultRef->value *= bRef->value;
        overflow_intStruct(resultRef);
        for (int j = 0; j < 3 * i; j++) {
            resultRef->value *= 10;
            overflow_intStruct(resultRef);
        }
        
        bRef = bRef->next;
        i++;
    }
}

// Returns the floor of a / b.
intStruct *divide_intStruct(intStruct *a, intStruct *b);

// Returns the a % b.
intStruct *modulus_intStruct(intStruct *a, intStruct *b);