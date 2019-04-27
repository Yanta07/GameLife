#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define scr_width 600
#define scr_height 600

int main(void)
{
    SDL_DisplayMode displayMode;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 1;
    }
    SDL_GetDesktopDisplayMode(0, &displayMode);
    SDL_Window* win = SDL_CreateWindow(
            "Game of life",
            0,
            0,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_SHOWN);
    if (win == NULL) {
        return 1;
    }
    SDL_Renderer* ren = SDL_CreateRenderer(
            win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        return 1;
    }

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN) {
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
            }
        }
    }
    return 0;
}