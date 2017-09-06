#include "sudokuJudger.h"
#include "sudokuGenerator.h"
#include "sudokuPrinter.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Error occurs when parsing arguments." << endl;
        cout << "Usage: sudoku.exe -c [N]" << endl;
        return 1;
    }

    int solutionNumber = atoi(argv[2]);

    SudokuGenerator sudokuGenerator;
    SudokuPrinter sudokuPrinter;

    bool signal = false;

    for (int i = 0; i < solutionNumber; i++) {
        signal = sudokuGenerator.Generator();
        if (signal) {
            sudokuPrinter.Printer(sudokuGenerator.solution);
        } else {
            cout << "Error occurs when applying sudokuGenerator." << endl;
            return 1;
        }
    }

    return 0;
}