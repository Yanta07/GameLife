#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define scr_width 600
#define scr_height 600

int main(void)
{
    SDL_DisplayMode displayMode;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 1;
    }
    int request = SDL_GetDesktopDisplayMode(0, &displayMode);
    SDL_Window* win = SDL_CreateWindow(
            "Hello World!",
            0,
            0,
            displayMode.w,
            displayMode.h,
            SDL_WINDOW_SHOWN);
    if (win == NULL) {
        return 1;
    }
    return 0;
}