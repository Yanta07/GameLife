#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void CreateGrid(
        SDL_Renderer* renderer,
        int rows,
        int cols,
        int screen_width,
        int screen_height);

SDL_Rect* InitCell(int xr, int yc, int cellwidth, int cellheight);
void ShowBoard(
        SDL_Renderer* renderer, int* b, int col, int row, int cellw, int cellh);
