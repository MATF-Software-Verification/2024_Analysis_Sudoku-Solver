#!/usr/bin/env python3

import subprocess
import shutil
from pathlib import Path

ROOT_DIR = Path(__file__).resolve().parents[1]
PROJECT_DIR = ROOT_DIR / "external" / "Sudoku-Solver"
TEST_DIR = ROOT_DIR / "unit_tests" / "tests"

BUILD_DIR = ROOT_DIR / "unit_tests" / "build"

def run(command, cwd=ROOT_DIR):
	print(f"[RUN] {' '.join(command)}")
	subprocess.run(command, cwd=cwd, check=True)


def main():

	if BUILD_DIR.exists():
		shutil.rmtree(BUILD_DIR)
	
	BUILD_DIR.mkdir(parents=True, exist_ok=True)

	run(["qmake", str(TEST_DIR / "SolverUnitTests.pro")], BUILD_DIR)

	run(["make", "-j"], BUILD_DIR)
	run([str(BUILD_DIR / "SolverUnitTests")], BUILD_DIR)
	
	#This is template for now.
if __name__ == "__main__":
	main()
