#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/visual.h"

void CreateGrid(
        SDL_Renderer* renderer, int rows, int cols, int swidth, int sheight)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
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

SDL_Rect* InitCell(int xr, int yc, int cellwidth, int cellheight)
{
    struct SDL_Rect* cell = malloc(sizeof(SDL_Rect));
    cell->x = cellwidth * xr;
    cell->y = cellheight * yc;
    cell->w = cellwidth;
    cell->h = cellheight;
    return cell;
}

void Sim_ShowBoard(
        SDL_Renderer* renderer,
        int* b,
        int col,
        int row,
        int cellw,
        int cellh,
        int screen_width,
        int screen_height)
{
    ClearWin(renderer);
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < col * row - 1; i++) {
        if (b[i] == ON) {
            SDL_Rect* cell = InitCell(i % row, i / row, cellw, cellh);
            SDL_RenderFillRect(renderer, cell);
        }
    }
    CreateGrid(renderer, row, col, screen_width, screen_height);
    SDL_RenderPresent(renderer);
}

void ClearWin(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 170, 150, 170, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void CreateGridBoard(
        SDL_Renderer* renderer, int rows, int cols, int swidth, int sheight)
{
    ClearWin(renderer);
    CreateGrid(renderer, rows, cols, swidth, sheight);
    SDL_RenderPresent(renderer);
}

void DirectPress(
        SDL_Event event, int* board, int cell_width, int cell_height, int rows)
{
    if (event.button.button == SDL_BUTTON_LEFT) {
        int tx = event.button.x / cell_width;
        int ty = event.button.y / cell_height;
        switch (board[tx + ty * rows]) {
        case ON:
            board[tx + ty * rows] = OFF;
            break;
        case OFF:
            board[tx + ty * rows] = ON;
            break;
        }
    }
    SDL_Delay(50);
}