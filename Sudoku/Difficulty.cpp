#include "Difficulty.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

std::vector<std::vector<int>> DifficultyManager::loadTemplate(Difficulty difficulty)
{
    std::string filename;
    switch (difficulty)
    {
    case Difficulty::EASY:
        filename = "easy_template.txt";
        break;
    case Difficulty::MEDIUM:
        filename = "medium_template.txt";
        break;
    case Difficulty::HARD:
        filename = "hard_template.txt";
        break;
    }
    return loadTemplateFromFile(filename);
}

std::vector<std::vector<int>> DifficultyManager::loadTemplateFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<int>> templateSudoku;
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<int> row;
        if (line.empty() || line.substr(0, 4) == "Grid")
        {
            continue;
        }

        row.clear();
        for (char c : line)
        {
            if (isdigit(c))
            {
                row.push_back(c - '0');
            }
            else if (c != ' ')
            {
                // Handle invalid characters if needed
                std::cerr << "Invalid character in file: " << filename << std::endl;
                return {};
            }
        }
        templateSudoku.push_back(row);
    }
    file.close();
    return templateSudoku;
}

void DifficultyManager::randomizePuzzle(std::vector<std::vector<int>> &templateSudoku)
{
    srand(time(nullptr));

    // Randomize each row
    for (std::vector<int> &row : templateSudoku)
    {
        std::random_shuffle(row.begin(), row.end());
    }

    // Randomize each column
    for (size_t i = 0; i < templateSudoku.size(); ++i)
    {
        std::vector<int> col;
        for (size_t j = 0; j < templateSudoku[i].size(); ++j)
        {
            col.push_back(templateSudoku[j][i]);
        }
        std::random_shuffle(col.begin(), col.end());
        for (size_t j = 0; j < templateSudoku[i].size(); ++j)
        {
            templateSudoku[j][i] = col[j];
        }
    }
}
