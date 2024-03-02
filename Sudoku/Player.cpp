#include "Player.h"
#include <iostream>

int Player::makeMove(const SudokuBoard &board)
{
    int row, col, num;
    std::cout << "Enter row, column, and number (1-9) to insert: ";
    std::cin >> row >> col >> num;
    if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 0 && num <= 9)
    {
        return (row * 100) + (col * 10) + num;
    }
    else
    {
        return -1;
    }
}

int Player::removeNumber()
{
    int row, col;
    std::cout << "Enter row and column to remove: ";
    std::cin >> row >> col;
    return (row * 10) + col;
}