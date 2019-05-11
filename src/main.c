#include "include/common.h"
#include "include/logic.h"
#include "include/visual.h"

int main()
{
    unsigned int lastTime = 0, currentTime, screen_width = 640,
                 screen_height = screen_width, rows = 10, cols = rows,
                 cell_width = screen_width / rows,
                 cell_height = screen_height / cols, paused = 1;
    //--------------------------------------
    const char* title = "Game of life";
    int* board = InitBoard(rows, cols);
    //--------------
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return 1;
    SDL_bool done = SDL_FALSE;
    SDL_Event event;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    //--------------------------------------------------------------------
    window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screen_width,
            screen_height,
            SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    CreateGridBoard(renderer, rows, cols, screen_width, screen_height);
    while (SDL_PollEvent(&event) || done == SDL_FALSE) {
        switch (event.type) {
        case SDL_QUIT:
            done = SDL_TRUE;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_RETURN) {
                if (paused == 0) {
                    paused = 1;
                } else {
                    paused = 0;
                }
            } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                done = SDL_TRUE;
            } else if (event.key.keysym.sym == SDLK_LSHIFT) {
                Sim_Process(board, rows, cols);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            DirectPress(event, board, cell_width, cell_height, rows);
            break;

        default:
            if (paused == 0) {
                currentTime = SDL_GetTicks();
                if (currentTime > lastTime + FPS) {
                    lastTime = currentTime;
                    Sim_ShowBoard(
                            renderer,
                            board,
                            cols,
                            rows,
                            cell_width,
                            cell_height,
                            screen_width,
                            screen_height);
                }
            } else {
                Sim_ShowBoard(
                        renderer,
                        board,
                        cols,
                        rows,
                        cell_width,
                        cell_height,
                        screen_width,
                        screen_height);
            }
            break;
        }
    }
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
