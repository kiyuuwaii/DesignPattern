#ifndef INSERTNUMBERCOMMAND_H
#define INSERTNUMBERCOMMAND_H

#include "Command.h"
#include "SudokuBoard.h"

class InsertNumberCommand : public Command
{
private:
    SudokuBoard &board;
    int row, col, num;
    int prevValue;

public:
    InsertNumberCommand(SudokuBoard &board, int row, int col, int num);
    void execute() override;
    void undo() override;
};

#endif