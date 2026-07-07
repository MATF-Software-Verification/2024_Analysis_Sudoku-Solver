# 2024_Analysis_Sudoku-Solver

# 📝 O projektu

- Projekat **Sudoku-Solver** je aplikacija koja rešava 9x9 sudoku. Korisnik unosi nerešen sudoku, i aplikacija ga rešava preko rekurzije i backtracking-a. Projekat se može naći na adresi https://github.com/coutaditya/Sudoku-Solver.
- U okviru ovog rada predstavljena je analiza projekta Sudoku-Solver(main grana, hash kod commita: 5ba3229d09851dcc156f7328c6183c0bb44a0531). U radu je opisan postupak primene različitih alata za verifikaciju softvera, kao i dobijeni rezultati, pronađeni bagovi i zaključi izvedeni iz ove analize.


# 🔧 Alati koji su korišćeni:
* QtTest + lcov
* Cppcheck
* Clang-Tidy
* Valgrind - Memcheck
* Lizard
* Flawfinder

# 📝 Zaključak:

Najvažniji rezultat testiranja je pronalazak logičke greške u funkciji `isAllowed()`. Funkcija proverava da li se određeni broj već nalazi u redu, koloni ili 3x3 bloku, ali ne ignoriše trenutno polje koje se proverava. Zbog toga validan broj može biti pogrešno označen kao neispravan. Pored toga nema većih propusta koji mogu znatno uticati na funkcionalnost, ali ima prostora za napredak, na primer refaktorizacija funkcije `sudokuSolver()` zbog povezanosti GUI-ja i dela logike.

# Autor:

Danilo Matić 1058/2024