// Problem 19: Counting Sundays
//
// Find how many Sundays fell on the first of the month during the twentieth century

#include <stdio.h>
#include <stdlib.h>

void nextSunday(int *date, int *month, int *year);

int main(void) {
    int year = 1900;
    int month = 1;
    int date = 7;
    int sundays = 0;
    
    while (year != 1901) {
        nextSunday(&date, &month, &year);
    }
    if (date == 1)
        sundays++;
    
    while (year <= 2000) {
        nextSunday(&date, &month, &year);
        if (date == 1)
            sundays++;
    }
    
    printf("Problem 19 result: %d\n", sundays);
    
    return 0;
}

void nextSunday(int *date, int *month, int *year) {
    *date += 7;
    switch (*month) {
        case 2:
            if ( (*year % 400 == 0) || ((*year % 4 == 0) && (*year % 100 != 0)) ) {
                if (*date > 29) {
                    *date -= 29;
                    (*month)++;
                }
            } else if (*date > 28) {
                *date -= 28;
                (*month)++;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (*date > 30) {
                *date -= 30;
                (*month)++;
            }
            break;
        default:
            if (*date > 31) {
                *date -= 31;
                (*month)++;
            }
            break;
    }
    if (*month > 12) {
        *month -= 12;
        (*year)++;
    }
}
