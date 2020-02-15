// Problem 22: Names scores
//
// Find the sum of the product of each name's the alphabetical value and alphabetical position.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 50

typedef struct name {
    char name[NAMELEN];
    struct name *next;
} name;

name *newName();
name *insertName(name *head, name *new);

int main(void) {
    name *head = NULL;
    name *new = NULL;
    FILE *fp = fopen("22.txt", "r");
    char c;
    unsigned long long sum = 0;
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == '"') {
            new = newName();
            for (int i = 0; (c = fgetc(fp)) != '"'; i++)
                new->name[i] = c;
            head = insertName(head, new);
        }
    }
    
    for (int i = 1; head != NULL; i++) {
        int alphaValue = 0;
        for (int j = 0; head->name[j] != '\0'; j++)
            alphaValue += head->name[j] - 'A' + 1;
        sum += alphaValue * i;
        
        new = head->next;
        free(head);
        head = new;
    }
    
    fclose(fp);
    
    printf("Problem 22 result: %llu\n", sum);
    
    return 0;
}

name *newName() {
    name *new = malloc(sizeof (name));
    for (int i = 0; i < NAMELEN; i++)
        new->name[i] = '\0';
    new->next = NULL;
    return new;
}

name *insertName(name *head, name *new) {
    if (head == NULL) {
        return new;
    } else if (strcmp(new->name, head->name) < 0) {
        new->next = head;
        return new;
    } else {
        head->next = insertName(head->next, new);
    }
}
