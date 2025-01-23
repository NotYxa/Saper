#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scores.h"

// Maksymalna liczba wyników w pliku
#define MAX_SCORES 100

// Struktura reprezentująca wynik gracza
typedef struct {
    char name[50];
    int score;
} PlayerScore;

// Funkcja zapisująca wynik gracza do pliku
void saveScore(const char *playerName, int score) {
    FILE *file = fopen("scores.txt", "a");
    if (file == NULL) {
        perror("Blad otwarcia pliku do zapisu wynikow");
        return;
    }

    fprintf(file, "%s %d\n", playerName, score);
    fclose(file);
    printf("Wynik zostal zapisany!\n");
}

// Funkcja porównawcza do sortowania wyników (od największego do najmniejszego)
int compareScores(const void *a, const void *b) {
    PlayerScore *scoreA = (PlayerScore *)a;
    PlayerScore *scoreB = (PlayerScore *)b;
    return scoreB->score - scoreA->score;
}

// Funkcja wyświetlająca najlepsze 5 wyników
void printTopScores() {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Brak zapisanych wynikow.\n");
        return;
    }

    PlayerScore scores[MAX_SCORES];
    int count = 0;

    // Wczytaj wyniki z pliku
    while (fscanf(file, "%s %d", scores[count].name, &scores[count].score) == 2) {
        count++;
        if (count >= MAX_SCORES) break; // Ogranicz liczbę wyników do maksymalnej
    }
    fclose(file);

    // Posortuj wyniki
    qsort(scores, count, sizeof(PlayerScore), compareScores);

    // Wyświetl najlepsze 5 wyników
    printf("Najlepsze wyniki:\n");
    for (int i = 0; i < count && i < 5; i++) {
        printf("%d. %s - %d punktow\n", i + 1, scores[i].name, scores[i].score);
    }
}
int calculateScore(int uncoveredTiles, int timeSpent, int difficulty) {
    // Base score from uncovered tiles
    int baseScore = uncoveredTiles * 100;
    
    // Time penalty (reduces score the longer it takes)
    int timePenalty = timeSpent / 2;
    
    // Difficulty multiplier
    float difficultyMultiplier;
    switch(difficulty) {
        case 1: difficultyMultiplier = 1.0; break;    // Easy
        case 2: difficultyMultiplier = 1.5; break;    // Medium
        case 3: difficultyMultiplier = 2.0; break;    // Hard
        default: difficultyMultiplier = 1.0;
    }
    
    return (int)((baseScore - timePenalty) * difficultyMultiplier);
}