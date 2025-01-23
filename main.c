#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "game.h"
#include "io.h"
#include "scores.h"

int main(void) {  // Usunięto nieużywane parametry
    int difficulty;
    printf("Wybierz poziom trudnosci (1 = Latwy, 2 = Sredni, 3 = Trudny): ");
    if (scanf("%d", &difficulty) != 1) {
        printf("Nieprawidlowe dane wejsciowe!\n");
        return 1;
    }

    if (difficulty < 1 || difficulty > 3) {
        printf("Nieprawidlowy poziom trudnosci!\n");
        return 1;
    }

    startGame(difficulty);  // Usunięto sprawdzanie, ponieważ startGame jest funkcją void

    printf("Koniec gry! Czy chcesz zobaczyc najlepsze wyniki? (t/n): ");
    char choice;
    while (getchar() != '\n'); // Wyczyść bufor wejściowy
    scanf("%c", &choice);

    if (choice == 't' || choice == 'T') {
        printTopScores();
    }

    return 0;
}