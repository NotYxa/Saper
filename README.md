**Sprawozdanie z projektu Minesweeper**

### 1. Cel Projektu
Celem projektu "Minesweeper" jest stworzenie gry komputerowej opartej na klasycznej grze "Saper". Program ma umożliwiać użytkownikowi:
- Wybranie poziomu trudności (lekki, średni, trudny),
- Odkrywanie pól z ukrytymi minami,
- Oznaczanie pól flagami w celu oznaczenia potencjalnych min,
- Zapis wyników w celu ich późniejszego przeglądu.
Gra jest przeznaczona do uruchamiania w linii poleceń i bazuje na dynamicznym zarządzaniu pamięcią oraz prostych mechanizmach interakcji z użytkownikiem.

---

### 2. Rozwiązanie Problemu
Program rozwiązuje problem implementacji gry typu "Saper" poprzez:
- **Dynamiczne zarządzanie planszą**: Funkcje do alokacji i inicjalizacji tablic dynamicznych reprezentujących planszę gry (widoczna i ukryta).
- **Obsługa interakcji z użytkownikiem**: Komendy `r` (odkryj pole) i `f` (oznacz pole flagą) umożliwiają proste sterowanie grą.
- **Obsługa wyniku gry**: Program umożliwia zapis wyniku gracza do pliku tekstowego w celu jego archiwizacji i późniejszego przeglądu.
- **Obsługa poziomów trudności**: W zależności od wyboru gracza tworzona jest plansza o różnych wymiarach oraz liczbie min.
- **Testowanie**: Oddzielny moduł testowy sprawdza poprawność kluczowych funkcji gry.

---

### 3. Szczegóły implementacyjne
Projekt składa się z następujących modułów:
- **`board.c` i `board.h`**:
  - Funkcje do alokacji, inicjalizacji i zwalniania planszy.
  - Obsługa widocznej i ukrytej warstwy planszy.
- **`game.c` i `game.h`**:
  - Logika gry, w tym odkrywanie pól, sprawdzanie warunku zwycięstwa oraz zarządzanie przebiegiem gry.
- **`io.c` i `io.h`**:
  - Funkcje wejścia/wyjścia, np. drukowanie planszy oraz obsługa wprowadzanych przez gracza komend.
- **`scores.c` i `scores.h`**:
  - Obsługa wyników gry, w tym zapis do pliku tekstowego.
- **`test.c`**:
  - Moduł testowy sprawdzający poprawność kluczowych funkcji (alokacja planszy, odkrywanie pól, warunki zwycięstwa).

Wykorzystano następujące techniki i biblioteki:
- Dynamiczne alokowanie pamięci za pomocą funkcji `malloc` i `free`.
- Obsługa argumentów linii poleceń za pomocą funkcji standardowych (np. `scanf`).
- Testowanie funkcji za pomocą `assert` w module testowym.

---

### 4. Sposób uruchomienia programu
Aby uruchomić program, należy:
1. **Skompilować kod**:
   - Użyć dostarczonego pliku `Makefile.mak` lub `Makefiletest.mak`, np.:
     ```bash
     make -f Makefile.mak
     ```
   - Alternatywnie, ręcznie skompilować program:
     ```bash
     gcc main.c board.c game.c io.c scores.c -o minesweeper
     ```
2. **Uruchomić grę**:
   - W systemie Windows uruchomić plik wykonywalny `minesweeper.exe`.
   - W systemie Linux uruchomić program:
     ```bash
     ./minesweeper
     ```
3. **Uruchomić testy**:
   - Kompilacja i uruchomienie testów:
     ```bash
     make -f Makefiletest.mak
     ./test
     ```

---

### 5. Wnioski i obserwacje
- Program poprawnie implementuje mechanikę gry "Saper", łącząc funkcjonalność z prostotą obsługi.
- Obsługa planszy w postaci tablic dynamicznych pozwala na elastyczne zarządzanie rozmiarem gry w zależności od poziomu trudności.
- Moduł testowy umożliwia szybkie sprawdzenie poprawności kluczowych funkcji, co jest szczególnie ważne podczas modyfikacji kodu.
- Rozwiązanie może być ulepszone poprzez:
  - Dodanie obsługi zaawansowanych opcji w linii poleceń (np. `--help`, `--difficulty`).
  - Implementację bardziej zaawansowanego systemu zapisu wyników, np. w formacie JSON.
  - Zaimplementowanie opcji cofania ruchów (undo).

Ogólnie projekt spełnia założone cele i stanowi solidną bazę dla dalszego rozwoju gry "Saper".

