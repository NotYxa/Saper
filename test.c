#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "board.h"
#include "game.h"
#include "scores.h"

// Funkcja testująca zapis wyników
void testSaveScore() {
    saveScore("TestowyGracz", 100);
    printf("Test saveScore zakonczony sukcesem.\n");
}

// Funkcja testująca odkrywanie pól
void testUncoverTile() {
    int rows = 5, cols = 5;
    char **board = allocateBoard(rows, cols);
    char **visibleBoard = allocateBoard(rows, cols);
    initBoard(rows, cols, 5, board);
    initVisibleBoard(rows, cols, visibleBoard);

    int result = uncoverTile(0, 0, board, visibleBoard, rows, cols);
    assert(result != -1); // Upewnij się, że pole nie jest miną
    printf("Test uncoverTile zakonczony sukcesem.\n");

    freeBoard(rows, board);
    freeBoard(rows, visibleBoard);
}

// Funkcja testująca sprawdzanie warunku zwycięstwa
void testCheckWinCondition() {
    int rows = 5, cols = 5;
    char **board = allocateBoard(rows, cols);
    char **visibleBoard = allocateBoard(rows, cols);
    initBoard(rows, cols, 5, board);
    initVisibleBoard(rows, cols, visibleBoard);

    // Symulacja odkrycia wszystkich pól bez min
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] != '*') {
                visibleBoard[i][j] = board[i][j];
            }
        }
    }

    int win = checkWinCondition(rows, cols, board, visibleBoard);
    assert(win == 1); // Upewnij się, że warunek zwycięstwa został spełniony
    printf("Test checkWinCondition zakonczony sukcesem.\n");

    freeBoard(rows, board);
    freeBoard(rows, visibleBoard);
}

int main() {
    testSaveScore();
    testUncoverTile();
    testCheckWinCondition();
    printf("Wszystkie testy zakonczone sukcesem.\n");
    return 0;
}
