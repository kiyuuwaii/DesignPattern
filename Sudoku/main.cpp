#include <iostream>
#include "SudokuGame.h"
#include "Player.h"

int main()
{
    SudokuGame game;
    Player player;

    game.initialize();
    game.printBoard();

    while (!game.isGameOver())
    {
        int choice;
        std::cout << "1. Insert Number" << std::endl;
        std::cout << "2. Remove Number" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int move = player.makeMove(game.getBoard());
            if (move != -1)
            {
                int row = move / 100;
                int col = (move / 10) % 10;
                int num = move % 10;
                if (game.insertNumber(row - 1, col - 1, num))
                {
                    std::cout << "Number inserted successfully!" << std::endl;
                    game.printBoard();
                }
                else
                {
                    std::cout << "Invalid move! Please try again." << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid move! Please try again." << std::endl;
            }
        }
        else if (choice == 2)
        {
            int move = player.removeNumber();
            int row = move / 10;
            int col = move % 10;
            if (game.removeNumber(row - 1, col - 1))
            {
                std::cout << "Number removed successfully!" << std::endl;
                game.printBoard();
            }
            else
            {
                std::cout << "Invalid move! Please try again." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }

    std::cout << "Congratulations! You have solved the Sudoku puzzle." << std::endl;

    return 0;
}
