#pragma once

int* InitBoard(int rows, int cols);
int Sim_BoardGetUpper(int* board, int i, int rows);
int Sim_BoardGetLower(int* board, int i, int rows);
int Sim_BoardGetLeft(int* board, int i, int rows);
int Sim_BoardGetRight(int* board, int i, int rows);
int Sim_Process(int* board, int rows, int cols);