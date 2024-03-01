#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <chrono>

// Definisi kelas Cell
class Cell
{
private:
    int value;

public:
    Cell() : value(0) {}
    int getValue() const { return value; }
    void setValue(int val) { value = val; }
    void clearValue() { value = 0; }
    bool isValid(int val) const { return value == val; }
};

// Definisi kelas SudokuBoard
class SudokuBoard
{
private:
    std::array<std::array<Cell, 9>, 9> cells;

public:
    Cell &getCell(int row, int col) { return cells[row][col]; }
    void setCell(int row, int col, int value) { cells[row][col].setValue(value); }
    void clearCell(int row, int col) { cells[row][col].clearValue(); }
    bool isCellEmpty(int row, int col) const { return cells[row][col].getValue() == 0; }
    bool isCellValid(int row, int col, int value) const
    {
        // Memeriksa apakah nilai valid dalam baris dan kolom yang sama
        for (int i = 0; i < 9; ++i)
        {
            if (cells[row][i].getValue() == value || cells[i][col].getValue() == value)
                return false;
        }
        // Memeriksa apakah nilai valid dalam kotak 3x3 yang sama
        int boxStartRow = row - row % 3;
        int boxStartCol = col - col % 3;
        for (int i = boxStartRow; i < boxStartRow + 3; ++i)
        {
            for (int j = boxStartCol; j < boxStartCol + 3; ++j)
            {
                if (cells[i][j].getValue() == value)
                    return false;
            }
        }
        return true;
    }
};

// Definisi kelas SudokuGame
class SudokuGame
{
private:
    SudokuBoard board;
    std::default_random_engine generator;

public:
    SudokuGame() : generator(std::chrono::system_clock::now().time_since_epoch().count()) {}

    void startGame()
    {
        // Kosongkan papan permainan
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                board.clearCell(row, col);
            }
        }
        // Isi papan dengan angka yang valid
        fillBoard();
    }

    bool solveGame()
    {
        // Kode untuk menyelesaikan permainan Sudoku
        // (Bisa menggunakan algoritma backtracking atau algoritma lain yang sesuai)
        // Di sini kita hanya mengembalikan false karena ini hanya contoh sederhana
        return false;
    }

    bool isBoardValid() const
    {
        // Kode untuk memeriksa kevalidan papan saat ini
        // (Misalnya, memeriksa setiap baris, kolom, dan kotak 3x3 apakah sudah valid)
        // Di sini kita hanya mengembalikan true karena ini hanya contoh sederhana
        return true;
    }

    bool isMoveValid(int row, int col, int num) const
    {
        // Kode untuk memeriksa kevalidan gerakan (penempatan nomor) yang diusulkan
        // Di sini kita hanya memeriksa apakah sel tersebut kosong
        return board.isCellEmpty(row, col) && board.isCellValid(row, col, num);
    }

    bool insertNumber(int row, int col, int num)
    {
        // Kode untuk memasukkan nomor ke sel tertentu pada papan permainan
        if (isMoveValid(row, col, num))
        {
            board.setCell(row, col, num);
            return true;
        }
        return false;
    }

    void removeNumber(int row, int col)
    {
        // Kode untuk menghapus nomor dari sel tertentu pada papan permainan
        board.clearCell(row, col);
    }

    bool isGameOver() const
    {
        // Kode untuk memeriksa apakah permainan telah selesai
        // (Misalnya, papan terisi penuh dan valid)
        // Di sini kita hanya mengembalikan false karena ini hanya contoh sederhana
        return false;
    }

    void resetGame()
    {
        // Kode untuk mengatur ulang permainan ke kondisi awal
        startGame();
    }

private:
    void fillBoard()
    {
        std::uniform_int_distribution<int> distribution(1, 9);
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                int num = distribution(generator);
                while (!board.isCellValid(row, col, num))
                {
                    num = distribution(generator);
                }
                board.setCell(row, col, num);
            }
        }
    }
};

int main()
{
    SudokuGame game;
    game.startGame();

    // Contoh penggunaan beberapa metode
    // (Perlu diatur sesuai dengan logika permainan yang sebenarnya)

    // Contoh: Memasukkan nomor ke dalam sel
    game.insertNumber(0, 0, 5);

    // Contoh: Menghapus nomor dari sel
    game.removeNumber(0, 0);

    return 0;
}
