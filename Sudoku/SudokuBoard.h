#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <vector>
#include "Difficulty.h"
#include "Cell.h"

class SudokuBoard
{
private:
    std::vector<std::vector<Cell>> board;

public:
    SudokuBoard();
    void setValue(int row, int col, int val);
    int getValue(int row, int col) const;
    void setFixed(int row, int col, bool fix);
    bool isFixed(int row, int col) const;
    bool isValid(int row, int col, int num) const;
    bool solve();
    void generate();
    void generate(int difficulty); // Tambahkan overload untuk generate dengan difficulty
    bool isFull() const;
    void reset();
    const std::vector<std::vector<Cell>> &getBoard() const;
};

#endif
