#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void initialize_grid(
        SDL_Renderer* renderer,
        int rows,
        int cols,
        int screen_width,
        int screen_height);
