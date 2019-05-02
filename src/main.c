#include "include/common.h"
#include "include/visual.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

const char* title = "Game of life";
const int screen_width = 640;
const int screen_height = 480;

int main()
{
    int rows = 10;
    int cols = 10;
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        if (SDL_CreateWindowAndRenderer(
                    screen_width, screen_height, 0, &window, &renderer)
            == 0) {
            SDL_bool done = SDL_FALSE;
            SDL_SetWindowTitle(window, title);
            while (!done) {
                SDL_Event event;
                SDL_SetRenderDrawColor(
                        renderer, 110, 110, 110, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(
                        renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                initialize_grid(
                        renderer, rows, cols, screen_width, screen_height);
                SDL_RenderPresent(renderer);
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}
