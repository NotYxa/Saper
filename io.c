#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// Funkcja odczytująca polecenie gracza
void readPlayerCommand(char *command, int *x, int *y) {
    printf("Wpisz komende (f x y) aby postawic/usunac flage albo (o x y) aby odslonic pole): ");
    scanf(" %c %d %d", command, x, y);
}

// Funkcja wczytująca planszę i ruchy gracza z pliku
int loadGameFromFile(const char *filename, char **board, char **visibleBoard) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("blad w otwieraniu pliku");
        return 0;
    }

    int rows, cols;
    fscanf(file, "%d %d\n", &rows, &cols);

    // Wczytanie planszy gry
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, " %c", &board[i][j]);
        }
    }

    // Wczytanie widocznej planszy
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, " %c", &visibleBoard[i][j]);
        }
    }

    fclose(file);
    return 1;
}

// Funkcja zapisująca aktualny stan gry do pliku
int saveGameToFile(const char *filename, char **board, char **visibleBoard, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("blad w otwieraniu pliku");
        return 0;
    }

    // Zapis wymiarów planszy
    fprintf(file, "%d %d\n", rows, cols);

    // Zapis planszy gry
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%c ", board[i][j]);
        }
        fprintf(file, "\n");
    }

    // Zapis widocznej planszy
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%c ", visibleBoard[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 1;
}
