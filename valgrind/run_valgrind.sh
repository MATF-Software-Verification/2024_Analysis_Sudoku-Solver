#!/usr/bin/env bash

set -xe

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
OUTPUT_FILE="$ROOT_DIR/valgrind/valgrind-output.txt"

python3 "$ROOT_DIR/unit_tests/run_tests.py"

valgrind \
  --tool=memcheck \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --log-file="$OUTPUT_FILE" \
  "$ROOT_DIR/unit_tests/build/SolverUnitTests"

echo "finished valgrind"
