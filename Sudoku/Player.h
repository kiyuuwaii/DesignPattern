#ifndef PLAYER_H
#define PLAYER_H

#include "SudokuBoard.h"

class Player
{
public:
    int makeMove(const SudokuBoard &board);
    int removeNumber();
};

#endif // PLAYER_H
