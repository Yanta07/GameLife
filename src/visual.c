#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"

void initialize_grid(
        SDL_Renderer* renderer, int rows, int cols, int swidth, int sheight)
{
    static SDL_Point line[1];
    for (int i = 1; i < rows; i++) {
        line[0].x = i * swidth / rows;
        line[0].y = 0;
        line[1].x = i * swidth / rows;
        line[1].y = sheight;
        SDL_RenderDrawLines(renderer, line, POINTS_COUNT);
    }
    for (int i = 1; i < cols; i++) {
        line[0].y = i * sheight / cols;
        line[0].x = 0;
        line[1].y = i * sheight / cols;
        line[1].x = swidth;
        SDL_RenderDrawLines(renderer, line, POINTS_COUNT);
    }
}
