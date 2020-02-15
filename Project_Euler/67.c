// Problem 67: Maximum path sum II
//
// Find the maximum total from top to bottom of the provided triangle

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *triangle = malloc(sizeof (int));
    int triangleSize = 0;
    int triangleHeight = 0;
    
    int n = 0;
    while (scanf("%d", &triangle[n]) == 1) {
        n++;
        triangleSize++;
        if (n == triangleSize) {
            triangle = realloc(triangle, (2 * triangleSize) * sizeof (int));
        }
    }
    
    n = 0;
    for (int i = 1; n < triangleSize; i++) {
        n += i;
        triangleHeight++;
    }
    
    int currNode;
    while (triangleHeight > 0) {
        triangleSize -= triangleHeight;
        triangleHeight -= 1;
        currNode = triangleSize - triangleHeight;
        
        while (currNode < triangleSize) {
            if (triangle[currNode + triangleHeight] > triangle[currNode + triangleHeight + 1]) {
                triangle[currNode] += triangle[currNode + triangleHeight];
            } else {
                triangle[currNode] += triangle[currNode + triangleHeight + 1];
            }
            currNode++;
        }
    }
    
    printf("Problem 67 result: %d\n", triangle[0]);
    
    return 0;
}