#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <cstdlib>

void parseInput(const std::string &inputFile, std::vector<std::vector<int>> &data)
{
    std::fstream inFile(inputFile);

    if (!inFile)
    {
        std::cerr << "Error opening input file." << std::endl;
        std::exit(1);
    }

    std::string line;

    int i = 0;
    while (std::getline(inFile, line))
    {
        std::vector<int> row;
        for (const char &c : line)
        {
            row.push_back(c);
        }
        data.push_back(row);
    }
}

int isAccessible(std::string inputFile)
{

    std::vector<std::vector<int>> data;
    parseInput(inputFile, data);

    int counter = 0;

    size_t numRows = data.size();
    size_t numCols = data[0].size();

    for (size_t i{0}; i < numCols; ++i)
    {
        for (size_t j{0}; j < numRows; ++j)
        {

            if (data[i][j] != '@')
                continue;

            int neighbourCount = 0;

            std::array<int, 8> dRow{-1, -1, -1, 0, 0, 1, 1, 1};
            std::array<int, 8> dCol{-1, 0, 1, -1, 1, -1, 0, 1};

            for (size_t d{0}; d < 8; ++d)
            {
                int ni = i + dRow[d];
                int nj = j + dCol[d];
                if (ni >= 0 && ni < numRows && nj >= 0 && nj < numCols)
                {

                    if (data[ni][nj] == '@')
                    {
                        neighbourCount++;
                    }
                }
            }

            if (neighbourCount < 4)
            {
                counter++;
            }
        }
    }
    return counter;
}

int main(int argc, char *argv[])
{
    std::cout << isAccessible(argv[1]) << std::endl;
}