#!/usr/bin/env bash

set -xe

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
OUTPUT_FILE="$ROOT_DIR/clang_tidy/clang-tidy-output.txt"

QT_HEADERS="$(qmake -query QT_INSTALL_HEADERS)"

clang-tidy \
  "$ROOT_DIR/external/Sudoku-Solver/sudokusolver.cpp" \
  "$ROOT_DIR/external/Sudoku-Solver/main.cpp" \
  --checks="bugprone-*,performance-*,readability-*,modernize-*,-modernize-use-trailing-return-type" \
  --header-filter="$ROOT_DIR/external/Sudoku-Solver/.*" \
  -- \
  -x c++ \
  -std=c++17 \
  -I"$ROOT_DIR/external/Sudoku-Solver" \
  -I"$QT_HEADERS" \
  -I"$QT_HEADERS/QtCore" \
  -I"$QT_HEADERS/QtGui" \
  -I"$QT_HEADERS/QtWidgets" \
  > "$OUTPUT_FILE" 2>&1

echo "finished clang-tidy" >> "$OUTPUT_FILE"