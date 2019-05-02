#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int* InitBoard(int rows, int cols)
{
    int* returnity = (int*)calloc(rows * cols - 1, sizeof(int));
    if (!returnity) {
        printf("Allocation failure.");
        exit(1);
    }
    for (int i = 0; i < rows * cols - 1; i++) {
        returnity[i] = 0;
    }

    return returnity;
}