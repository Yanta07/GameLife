#include "include/logic.h"
#include "include/visual.h"

int main()
{
    int paused = 1;
    //--------------------------------------
    const char* title = "Game of life";
    const int screen_width = 640;
    const int screen_height = screen_width;
    int rows = 10;
    int cols = rows;
    int cell_width = screen_width / rows;
    int cell_height = screen_height / cols;
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
    while (done == SDL_FALSE) {
        SDL_PollEvent(&event);
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
            } else if (
                    event.key.keysym.sym == SDLK_RSHIFT
                    || event.key.keysym.sym == SDLK_LSHIFT) {
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            DirectPress(event, board, cell_width, cell_height, rows);
            break;

        default:
            if (paused == 0 && SDL_Ticks() % 100 == 0) {
                Sim_ShowBoard(
                        renderer,
                        board,
                        cols,
                        rows,
                        cell_width,
                        cell_height,
                        screen_width,
                        screen_height);
                Sim_Process(board, rows, cols);
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
