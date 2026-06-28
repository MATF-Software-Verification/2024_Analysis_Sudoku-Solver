#!/usr/bin/env bash

set -xe

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

cppcheck \
  --quiet \
  --inconclusive \
  --enable=all \
  --suppress=missingIncludeSystem \
  -DQ_OBJECT= \
  -Dslots= \
  -Dsignals= \
  --output-file="$SCRIPT_DIR/cppcheck-output.txt" \
  "$ROOT_DIR/external/Sudoku-Solver/main.cpp" \
  "$ROOT_DIR/external/Sudoku-Solver/sudokusolver.cpp" \
  "$ROOT_DIR/external/Sudoku-Solver/sudokusolver.h"

echo "finished cppcheck"
