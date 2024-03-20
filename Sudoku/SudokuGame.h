#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H

#include "SudokuBoard.h"

class SudokuGame
{
private:
    SudokuBoard board;

public:
    SudokuGame();
    void initialize(Difficulty difficulty);
    void printBoard() const;
    bool insertNumber(int row, int col, int num);
    bool removeNumber(int row, int col);
    bool isMoveValid(int row, int col, int num) const;
    bool isGameOver() const;
    void resetGame();
    const SudokuBoard &getBoard() const;
};

#endif // SUDOKUGAME_H
