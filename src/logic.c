#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int* InitBoard(int rows, int cols)
{
    int* returnity = (int*)calloc(rows * cols - 1, sizeof(int));
    if (!returnity) {
        printf("Allocation failure.");
        exit(1);
    }
    for (int i = 0; i < rows * cols - 1; i++) {
        returnity[i] = 0;
    }

    return returnity;
}

int Sim_BoardGetUpper(int* board, int i, int rows)
{
    if (i < rows) {
        return board[rows * rows - (rows - i)];
    }
    return board[i - rows];
}

int Sim_BoardGetLower(int* board, int i, int rows)
{
    if (i > rows * (rows - 1)) {
        return board[i - (rows * (rows - 1))];
    }
    return board[i + rows];
}

int Sim_BoardGetLeft(int* board, int i, int rows)
{
    if (i % rows == 0) {
        return board[i + rows - 1];
    }
    return board[i - 1];
}

int Sim_BoardGetRight(int* board, int i, int rows)
{
    if ((i + 1) % rows == 0) {
        return board[i - rows + 1];
    }
    return board[i + 1];
}

int Sim_Process(int* board, int rows, int cols)
{
    int* buf = InitBoard(rows, cols);
    if (buf == NULL) {
        return 1;
    }
    for (int i = 0; i < rows * cols - 1; i++) {
        buf[i] = board[i];
    }
    for (int i = 0; i < rows * cols - 1; i++) {
        int sum = 0;
        // sum += Sim_BoardGetUpper(buf, i, rows);
        // sum += Sim_BoardGetLower(buf, i, rows);
        // sum += Sim_BoardGetLeft(buf, i, rows);
        // sum += Sim_BoardGetRight(buf, i, rows);
        sum = buf[i - rows - 1] + buf[i - rows] + buf[i - rows + 1] + buf[i - 1]
                + buf[i + 1] + buf[i + rows - 1] + buf[i + rows]
                + buf[i + rows + 1];
        if (sum >= 2) {
            if (sum == 2 || sum == 3) {
                board[i] = 1;
            } else
                board[i] = 0;
        } else if (sum < 2) {
            board[i] = 0;
        }
    }
    return 0;
}