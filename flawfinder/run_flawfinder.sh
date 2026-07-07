#!/usr/bin/env bash

set -xe

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
OUTPUT_FILE="$ROOT_DIR/flawfinder/flawfinder-output.html"

flawfinder \
  --html \
  "$ROOT_DIR/external/Sudoku-Solver/main.cpp" \
  "$ROOT_DIR/external/Sudoku-Solver/sudokusolver.cpp" \
  "$ROOT_DIR/external/Sudoku-Solver/sudokusolver.h" \
  > "$OUTPUT_FILE"

echo "finished flawfinder" >> "$OUTPUT_FILE"
