#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"
#include "board.h"
#include "io.h"
#include "scores.h"

// Funkcja alokująca pamięć na planszę
char** allocateBoard(int rows, int cols) {
    char** board = (char**)malloc(rows * sizeof(char*));
    if (!board) return NULL;
    
    for (int i = 0; i < rows; i++) {
        board[i] = (char*)malloc(cols * sizeof(char));
        if (!board[i]) {
            freeBoard(i, board);
            return NULL;
        }
    }
    return board;
}

// Funkcja inicjalizująca widoczną planszę
void initVisibleBoard(int rows, int cols, char** visibleBoard) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visibleBoard[i][j] = '#'; // Znak oznaczający niewidoczne pole
        }
    }
}

// Funkcja zwalniająca pamięć planszy
void freeBoard(int rows, char** board) {
    if (!board) return;
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
}

// Funkcja obsługująca zapis wyniku
static void handleScoreSaving(int score) {
    printf("Czy chcesz zapisac swój wynik? (t/n): ");
    while (getchar() != '\n');
    char saveChoice = getchar();
    
    if (saveChoice == 't' || saveChoice == 'T') {
        char playerName[50];
        printf("Podaj swoje imie (maks. 49 znakow): ");
        while (getchar() != '\n');
        fgets(playerName, sizeof(playerName), stdin);
        playerName[strcspn(playerName, "\n")] = 0;
        saveScore(playerName, score);
    }
}

// Funkcja rozpoczynająca grę
void startGame(int difficulty) {
    char **board, **visibleBoard;
    int rows, cols, mines;

    switch (difficulty) {
        case 1: // Łatwy poziom
            rows = 9;
            cols = 9;
            mines = 10;
            break;
        case 2: // Średni poziom
            rows = 16;
            cols = 16;
            mines = 40;
            break;
        case 3: // Trudny poziom
            rows = 16;
            cols = 30;
            mines = 99;
            break;
        default:
            printf("Nieprawidlowy poziom trudnosci!\n");
            return;
    }

    board = allocateBoard(rows, cols);
    visibleBoard = allocateBoard(rows, cols);
    if (!board || !visibleBoard) {
        printf("Blad alokacji pamieci!\n");
        return;
    }

    initBoard(rows, cols, mines, board);
    initVisibleBoard(rows, cols, visibleBoard);

    int gameOver = 0;
    int uncoveredTiles = 0;
    time_t startTime = time(NULL);

    while (!gameOver) {
        printBoard(rows, cols, visibleBoard);
        
        char command;
        int x, y;
        printf("\nPodaj polecenie (r x y - odkryj, f x y - oznacz flaga): ");
        scanf(" %c %d %d", &command, &x, &y);

        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            printf("Nieprawidlowe wspolrzedne!\n");
            continue;
        }

        if (command == 'r') {
            int result = uncoverTile(x, y, board, visibleBoard, rows, cols);
            if (result == -1) {
                time_t endTime = time(NULL);
                int timeSpent = (int)difftime(endTime, startTime);
                int score = calculateScore(uncoveredTiles, timeSpent, difficulty);
                
                for(int i = 0; i < rows; i++)
                    for(int j = 0; j < cols; j++)
                        visibleBoard[i][j] = board[i][j];
                
                printBoard(rows, cols, visibleBoard);
                printf("\nKoniec gry! Trafifes na mine!\n");
                printf("Twoj wynik: %d\n", score);
                printf("Czas gry: %d sekund\n", timeSpent);
                
                handleScoreSaving(score);
                gameOver = 1;
            } else {
                uncoveredTiles += result;
                if (checkWinCondition(rows, cols, board, visibleBoard)) {
                    time_t endTime = time(NULL);
                    int timeSpent = (int)difftime(endTime, startTime);
                    int score = calculateScore(uncoveredTiles, timeSpent, difficulty);
                    
                    printf("\nGratulacje! Wygrales!\n");
                    printf("Twoj wynik: %d\n", score);
                    printf("Czas gry: %d sekund\n", timeSpent);
                    
                    handleScoreSaving(score);
                    gameOver = 1;
                }
            }
        } else if (command == 'f') {
            placeFlag(x, y, visibleBoard);
        } else {
            printf("Nieprawidlowe polecenie!\n");
        }
    }

    freeBoard(rows, board);
    freeBoard(rows, visibleBoard);
}
