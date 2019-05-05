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

void CreateGridBoard(
        SDL_Renderer* renderer, int rows, int cols, int swidth, int sheight);

void ShowBoard(
        SDL_Renderer* renderer,
        int* b,
        int col,
        int row,
        int cellw,
        int cellh,
        int screen_width,
        int screen_height);
void ClearWin(SDL_Renderer* renderer);
SDL_Rect* InitCell(int xr, int yc, int cellwidth, int cellheight);

void DirectPress(
        SDL_Event event, int* board, int cell_width, int cell_height, int rows);
