#ifndef BOARD_H
#define BOARD_H

void initBoard(int rows, int cols, int mines, char **board);
void printBoard(int rows, int cols, char **visibleBoard);
void placeFlag(int x, int y, char **visibleBoard);
int uncoverTile(int x, int y, char **board, char **visibleBoard, int rows, int cols);
int checkWinCondition(int rows, int cols, char **board, char **visibleBoard);

#endif