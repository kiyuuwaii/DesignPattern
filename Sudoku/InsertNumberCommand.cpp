#include "InsertNumberCommand.h"

InsertNumberCommand::InsertNumberCommand(SudokuBoard &board, int row, int col, int num)
    : board(board), row(row), col(col), num(num), prevValue(0) {}

void InsertNumberCommand::execute()
{
    prevValue = board.getValue(row, col);
    board.setValue(row, col, num);
}

void InsertNumberCommand::undo()
{
    board.setValue(row, col, prevValue);
}