#include <iostream>
#include "SudokuGame.h"
#include "Player.h"
#include "Difficulty.h"

int main()
{
    SudokuGame game;
    Player player;

    int difficultyChoice;
    std::cout << "Choose the difficulty level:" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> difficultyChoice;

    // Inisialisasi permainan dengan tingkat kesulitan yang dipilih
    switch (difficultyChoice)
    {
    case Difficulty::EASY:
        game.initialize(Difficulty::EASY);
        break;
    case Difficulty::MEDIUM:
        game.initialize(Difficulty::MEDIUM);
        break;
    case Difficulty::HARD:
        game.initialize(Difficulty::HARD);
        break;
    default:
        std::cout << "Invalid choice. Generating an easy Sudoku board by default." << std::endl;
        game.initialize(Difficulty::EASY);
        break;
    }

    game.printBoard();

    // Memulai permainan
    while (!game.isGameOver())
    {
        int choice;
        std::cout << "1. Insert Number" << std::endl;
        std::cout << "2. Remove Number" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            // Meminta pemain untuk membuat langkah
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
            // Meminta pemain untuk menghapus nomor
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
