#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define scr_width 600
#define scr_height 600

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Game of Life", NULL);
    SDL_Surface* screen
            = SDL_SetVideoMode(scr_width, scr_height, 0, SDL_SWSURFACE);
    if (!screen) {
        return EXIT_FAILURE;
    }
    Uint32 bgcolor = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
    if (SDL_FillRect(screen, &(screen->clip_rect), bgcolor) == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}