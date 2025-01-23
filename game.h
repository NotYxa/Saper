#ifndef GAME_H
#define GAME_H

char** allocateBoard(int rows, int cols);
void initVisibleBoard(int rows, int cols, char** visibleBoard);
void freeBoard(int rows, char** board);
int uncoverArea(int x, int y, int rows, int cols, char** board, char** visibleBoard);
int calculateScore(int uncoveredTiles, int timeSpent, int difficulty);

void startGame(int difficulty);  

#endif 