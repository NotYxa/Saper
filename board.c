#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

// Sprawdza poprawnosc wspolrzednych na planszy
static int isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Ustawia lub usuwa flage na polu
void placeFlag(int x, int y, char **visibleBoard) {
    if (visibleBoard[x][y] == '#') {
        visibleBoard[x][y] = 'F';
    } else if (visibleBoard[x][y] == 'F') {
        visibleBoard[x][y] = '#';
    }
}

// Inicjalizuje plansze gry
void initBoard(int rows, int cols, int mines, char **board) {
    // Inicjalizacja pustej planszy
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = '0';
        }
    }

    // Losowe rozmieszczenie min
    srand(time(NULL));
    int minesPlaced = 0;
    while (minesPlaced < mines) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            minesPlaced++;
        }
    }

    // Obliczanie liczb
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == '*') continue;
            
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (isValid(ni, nj, rows, cols) && board[ni][nj] == '*') {
                        count++;
                    }
                }
            }
            board[i][j] = count + '0';
        }
    }
}

void printBoard(int rows, int cols, char **visibleBoard) {
    // Drukowanie naglowka z numerami kolumn
    printf("    "); // Odstep dla numerow wierszy
    for (int j = 0; j < cols; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Drukowanie linii separatora
    printf("   +"); // Odstep dla numerow wierszy
    for (int j = 0; j < cols; j++) {
        printf("---");
    }
    printf("\n");

    // Drukowanie planszy z numerami wierszy
    for (int i = 0; i < rows; i++) {
        printf("%2d |", i); // Numer wiersza
        for (int j = 0; j < cols; j++) {
            printf(" %c ", visibleBoard[i][j]);
        }
        printf("\n");
    }

    // Drukowanie koncowej linii separatora
    printf("   +");
    for (int j = 0; j < cols; j++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("%2d |", i); // Numer wiersza
        for (int j = 0; j < cols; j++) {
            printf(" %c ", visibleBoard[i][j]);
        }
        printf("\n");
    }
}

// Odkrywa pole na planszy
int uncoverTile(int x, int y, char **board, char **visibleBoard, int rows, int cols) {
    if (!isValid(x, y, rows, cols) || visibleBoard[x][y] != '#')
        return 0;

    visibleBoard[x][y] = board[x][y];

    if (board[x][y] == '*')
        return -1;  // Koniec gry

    if (board[x][y] == '0') {
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) continue;
                uncoverTile(x + di, y + dj, board, visibleBoard, rows, cols);
            }
        }
    }
    return 1;
}

// Sprawdza warunek wygranej
int checkWinCondition(int rows, int cols, char **board, char **visibleBoard) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] != '*' && visibleBoard[i][j] == '#')
                return 0;
        }
    }
    return 1;
}