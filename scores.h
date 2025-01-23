#ifndef SCORES_H
#define SCORES_H

/**
 * @brief Zapisuje wynik gracza do pliku wyników.
 * @param playerName Imię gracza.
 * @param score Wynik gracza.
 */
void saveScore(const char *playerName, int score);

/**
 * @brief Wyświetla najlepsze 5 wyników zapisane w pliku.
 */
void printTopScores();
int calculateScore(int uncoveredTiles, int timeSpent, int difficulty);
#endif // SCORES_H
