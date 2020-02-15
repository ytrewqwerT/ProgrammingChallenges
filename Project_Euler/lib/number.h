// Defines the intStruct type:
//   An intStruct type is an arbitrary-precision unsigned integer that relies on a linked list.
//   Memory is dynamically allocated as necessary to store the number.
//   Each node in the list represents 3 digits in base 10.
//     i.e. The nodes in the list can be considered to be individual digits that make up a base 1000 number.
//

#include "number.c"

typedef struct bigInt {
    long value;
    struct bigInt *next;
    struct bigInt *previous;
} intStruct;


intStruct *new_intStruct();
void delete_intStruct(intStruct *a);
intStruct *copy_intStruct(intStruct *a);
void overflow_intStruct(intStruct *a);

intStruct *add_intStruct(intStruct *a, intStruct *b);
intStruct *subtract_intStruct(intStruct *a, intStruct *b);
intStruct *multiply_intStruct(intStruct *a, intStruct *b);
intStruct *divide_intStruct(intStruct *a, intStruct *b);
intStruct *modulus_intStruct(intStruct *a, intStruct *b);