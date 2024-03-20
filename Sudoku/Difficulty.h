#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <vector>
#include <string>

enum class Difficulty
{
    EASY,
    MEDIUM,
    HARD
};

class DifficultyManager
{
public:
    static std::vector<std::vector<int>> loadTemplate(Difficulty difficulty);

private:
    static std::vector<std::vector<int>> loadTemplateFromFile(const std::string &filename);
    static void randomizePuzzle(std::vector<std::vector<int>> &puzzle);
};

#endif // DIFFICULTY_H
