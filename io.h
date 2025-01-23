#ifndef IO_H
#define IO_H

/**
 * @brief Odczytuje polecenie gracza.
 * @param command Wskaźnik na zmienną, w której zostanie zapisane polecenie ('f' lub 'o').
 * @param x Wskaźnik na współrzędną wiersza.
 * @param y Wskaźnik na współrzędną kolumny.
 */
void readPlayerCommand(char *command, int *x, int *y);

/**
 * @brief Wczytuje planszę i ruchy gracza z pliku.
 * @param filename Ścieżka do pliku.
 * @param board Plansza gry, która zostanie załadowana z pliku.
 * @param visibleBoard Widoczna plansza gracza, która zostanie załadowana z pliku.
 * @return 1, jeśli plik został pomyślnie wczytany, w przeciwnym razie 0.
 */
int loadGameFromFile(const char *filename, char **board, char **visibleBoard);

/**
 * @brief Zapisuje aktualny stan gry do pliku.
 * @param filename Ścieżka do pliku.
 * @param board Plansza gry, którą należy zapisać.
 * @param visibleBoard Widoczna plansza gracza, którą należy zapisać.
 * @param rows Liczba wierszy planszy.
 * @param cols Liczba kolumn planszy.
 * @return 1, jeśli zapis zakończył się sukcesem, w przeciwnym razie 0.
 */
int saveGameToFile(const char *filename, char **board, char **visibleBoard, int rows, int cols);

#endif // IO_H
