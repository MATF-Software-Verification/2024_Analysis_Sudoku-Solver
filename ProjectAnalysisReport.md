# Izveštaj analize projekta

## Testiranje i pokrivenost koda

Za testiranje projekta korišćen je **QtTest** framework, jer je analizirani projekat implementiran u C++ jeziku uz Qt biblioteku. Testovi su smešteni u direktorijum `unit_tests`, dok je originalni projekat zadržan neizmenjen u direktorijumu `external/Sudoku-Solver`.

### Pokretanje testova

Testovi se pokreću python skriptom:

```bash
python3 unit_tests/run_tests.py
```

### Testirani slučajevi

| Test | Opis |
|---|---|
|`duplicateInRowShouldBeRejected` | Proverava da li će se odbiti broj koji već postoji u tom redu. |
|`duplicateInColumnShouldBeRejected` | Proverava da li će se odbiti broj koji već postoji u toj koloni. |
|`duplicateInBoxShouldBeRejected` | Proverava da li će se odbiti broj koji već postoji u tom 3x3 boxu. |
|`validPlacementShouldBeAllowed` | Proverava da li validan broj može biti unet u prazno polje. |
|`validPuzzleShouldBeSolved` | Proverava da li solver uspešno rešava validnu Sudoku tabelu. |
|`alreadySolvedPuzzleShouldRemainSolved` | Proverava da li već rešena tabela ostaje neizmenjena. |
|`unsolvablePuzzleShouldReturnFalse` | Proverava da li  će nerešiva tabela biti odbijena. | 
|`validInitialNumberShouldBeAllowedButCurrentlyFails` | Dokumentuje grešku u funkciji `isAllowed()` gde prilikom provere da li se zadati broj nalazi u koloni/redu/bloku ne ignoriše trenutno polje koje se proverava. |

### Rezultat izvršavanja testova

Na slici ispod prikazan je rezultat izvršavanja testova.

![Rezultat testova](images/qt_tests_result.png)

### Pokrivenost Koda

Uz testove je praćena i pokrivenost koda pomoću alata **lcov**. Pokrivenost je merena nakon izvršavanja automatizovanih testova, tako da metrika predstavlja stvarno izvršene delove koda.

Izveštaj pokrivenosti generisan je komandama:

```bash
lcov --capture --directory unit_tests/build --output-file unit_tests/build/coverage.info
lcov --remove unit_tests/build/coverage.info '/usr/*' '*/unit_tests/*' --output-file unit_tests/build/coverage.filtered.info
genhtml unit_tests/build/coverage.filtered.info --output-directory unit_tests/coverage_html
```
Na slici ispod prikazan je HTML izveštaj alata `lcov`.

![LCOV izveštaj pokrivenosti](images/lcov_coverage_report.png)

Visoka pokrivenost linija pokazuje da su testovi izvršili najveći deo algoritamskog koda. Funkcijska pokrivenost je niža jer nije pokrivena UI funkcija `solveSudoku()`, koja predstavlja Qt slot povezan sa korisničkim interfejsom.

