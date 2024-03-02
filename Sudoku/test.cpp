#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Cell
{
private:
    int value;
    bool fixed;

public:
    Cell() : value(0), fixed(false) {}

    int getValue() const
    {
        return value;
    }

    void setValue(int val)
    {
        value = val;
    }

    bool isFixed() const
    {
        return fixed;
    }

    void setFixed(bool fix)
    {
        fixed = fix;
    }
};

class SudokuBoard
{
private:
    std::vector<std::vector<Cell>> board;

public:
    SudokuBoard()
    {
        // Initialize the board with empty cells
        board.resize(9, std::vector<Cell>(9));
    }

    void setValue(int row, int col, int val)
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
        {
            board[row][col].setValue(val);
        }
    }

    int getValue(int row, int col) const
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
        {
            return board[row][col].getValue();
        }
        return 0; // Return 0 if coordinates are out of bounds
    }

    void setFixed(int row, int col, bool fix)
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
        {
            board[row][col].setFixed(fix);
        }
    }

    bool isFixed(int row, int col) const
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
        {
            return board[row][col].isFixed();
        }
        return false; // Return false if coordinates are out of bounds
    }

    bool isValid(int row, int col, int num) const
    {
        // Check row and column
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i].getValue() == num || board[i][col].getValue() == num)
            {
                return false;
            }
        }

        // Check 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; ++i)
        {
            for (int j = startCol; j < startCol + 3; ++j)
            {
                if (board[i][j].getValue() == num)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve()
    {
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                if (board[row][col].getValue() == 0)
                {
                    for (int num = 1; num <= 9; ++num)
                    {
                        if (isValid(row, col, num))
                        {
                            board[row][col].setValue(num);
                            if (solve())
                            {
                                return true;
                            }
                            board[row][col].setValue(0);
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void generate()
    {
        srand(time(nullptr));
        solve(); // Solve an empty board
        for (int i = 0; i < 81 * 0.4; ++i)
        { // Randomly remove 40% of the numbers
            int row = rand() % 9;
            int col = rand() % 9;
            if (!board[row][col].isFixed())
            {
                board[row][col].setValue(0);
            }
        }
    }

    bool isFull() const
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j].getValue() == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void reset()
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                board[i][j].setValue(0);
            }
        }
    }

    const std::vector<std::vector<Cell>> &getBoard() const
    {
        return board;
    }
};

class SudokuGame
{
private:
    SudokuBoard board;

public:
    SudokuGame() {}

    void initialize()
    {
        board.generate();
    }

    void printBoard() const
    {
        for (int i = 0; i < 9; ++i)
        {
            if (i % 3 == 0 && i != 0)
            {
                std::cout << "---------------------" << std::endl;
            }
            for (int j = 0; j < 9; ++j)
            {
                if (j % 3 == 0 && j != 0)
                {
                    std::cout << "| ";
                }
                if (board.getValue(i, j) == 0)
                {
                    std::cout << ". ";
                }
                else
                {
                    std::cout << board.getValue(i, j) << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    bool insertNumber(int row, int col, int num)
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9 && num >= 0 && num <= 9)
        {
            if (!board.isFixed(row, col) && board.getValue(row, col) == 0)
            {
                board.setValue(row, col, num);
                return true;
            }
        }
        return false;
    }

    bool removeNumber(int row, int col)
    {
        if (row >= 0 && row < 9 && col >= 0 && col < 9)
        {
            if (!board.isFixed(row, col))
            {
                board.setValue(row, col, 0);
                return true;
            }
        }
        return false;
    }

    bool isMoveValid(int row, int col, int num) const
    {
        return board.isValid(row, col, num);
    }

    bool isGameOver() const
    {
        return board.isFull();
    }

    void resetGame()
    {
        board.reset();
    }

    const SudokuBoard &getBoard() const
    {
        return board;
    }
};

class Player
{
public:
    int makeMove(const SudokuBoard &board)
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

    int removeNumber()
    {
        int row, col;
        std::cout << "Enter row and column to remove: ";
        std::cin >> row >> col;
        return (row * 10) + col;
    }
};

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
