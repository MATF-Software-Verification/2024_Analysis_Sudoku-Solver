QT += testlib widgets
CONFIG += console c++17
CONFIG -= app_bundle

TEMPLATE = app
TARGET = SolverUnitTests

INCLUDEPATH += ../../external/Sudoku-Solver

SOURCES += \
    SolverUnitTests.cpp \
    ../../external/Sudoku-Solver/sudokusolver.cpp

HEADERS += \
    ../../external/Sudoku-Solver/sudokusolver.h

QMAKE_CXXFLAGS += --coverage -O0 -g
QMAKE_LFLAGS += --coverage