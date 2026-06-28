#include <QtTest/QtTest>

#define private public
#include "../../external/Sudoku-Solver/sudokusolver.h"
#undef private


class SolverUnitTests : public QObject{
    Q_OBJECT

private slots:
    void validInitialNumberShouldBeAllowedButCurrentlyFails();
    void duplicateInRowShouldBeRejected();
    void duplicateInColumnShouldBeRejected();
    void duplicateInBoxShouldBeRejected();
    void validPlacementShouldBeAllowed();
    void validPuzzleShouldBeSolved();
    void alreadySolvedPuzzleShouldRemainSolved();
    void unsolvablePuzzleShouldReturnFalse();
};
static std::vector<std::vector<int>> solvedPuzzle(){
    return {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };
}
void SolverUnitTests::validInitialNumberShouldBeAllowedButCurrentlyFails(){

    SudokuSolver solver;

    std::vector<std::vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    /*
        This test documents a bug in original implementation.
        isAlowed funciton compares the cell with itself.

        correct behavior should be true
    */
    QEXPECT_FAIL("", "Known bug: isAllowed compares the checked cell with itself.", Continue);
    QVERIFY(solver.isAllowed(board,0,0,5));

}

void SolverUnitTests::duplicateInRowShouldBeRejected(){

    SudokuSolver solver;
    std::vector<std::vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    QVERIFY(!solver.isAllowed(board, 0, 6, 5));
}

void SolverUnitTests::duplicateInColumnShouldBeRejected(){
    SudokuSolver solver;

    // 1 is duplicated in 4nd column
    std::vector<std::vector<int>> board = {
        {5,3,1,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,2,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    QVERIFY(!solver.isAllowed(board, 5, 3, 1));

}

void SolverUnitTests::duplicateInBoxShouldBeRejected(){
    SudokuSolver solver;

    // 6 is duplicated in first 3x3 box
    std::vector<std::vector<int>> board = {
        {5,3,1,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,2,6,0,0,0,0,0,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    QVERIFY(!solver.isAllowed(board, 2, 2, 6));

}

void SolverUnitTests::validPlacementShouldBeAllowed(){
    SudokuSolver solver;

    
    std::vector<std::vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    QVERIFY(solver.isAllowed(board, 0, 2, 4));

}
void SolverUnitTests::validPuzzleShouldBeSolved(){
    SudokuSolver solver;

    
    std::vector<std::vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    QVERIFY(solver.solvesudoku(board,0,0));
    QCOMPARE(board, solvedPuzzle());

}

void SolverUnitTests::alreadySolvedPuzzleShouldRemainSolved(){
    SudokuSolver solver;

    auto board = solvedPuzzle();

    QVERIFY(solver.solvesudoku(board,0,0));
    QCOMPARE(board, solvedPuzzle());
}
void SolverUnitTests::unsolvablePuzzleShouldReturnFalse(){
    SudokuSolver solver;

    std::vector<std::vector<int>> board = {
        {9,3,0,0,7,0,0,0,0},
        {0,1,2,3,4,5,6,7,8},
        {0,0,8,0,0,0,0,0,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,0,9}
    };
    QVERIFY(!solver.solvesudoku(board,0,0));
   
}
QTEST_MAIN(SolverUnitTests)
#include "SolverUnitTests.moc"