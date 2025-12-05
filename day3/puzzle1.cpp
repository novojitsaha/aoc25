#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
size_t getMaxJoltage(std::string inputFile)
{
    std::fstream inFile(inputFile);

    if (!inFile)
    {
        std::cerr << "Error reading input file." << std::endl;
    }

    size_t totalJoltage = 0;

    std::string line;

    // t: n lines -> O(n); s: O(1) since the stack is strictly 
    // decreasing and therefore holds values between 1 and 9
    while (std::getline(inFile, line))
    {
        std::vector<int> vec;
        int firstMax = 0;
        int secondMax = 0;

        for (size_t i = 0; i < line.size() - 1; ++i)
        {
            int val = line[i] - '0';

            while (!vec.empty() && val > vec.back())
            {
                vec.pop_back();
            }
            vec.push_back(val);
        }
        firstMax = vec[0];

        int lastVal = line[line.size() - 1] - '0';

        secondMax = vec.size() == 1 ? lastVal : std::max(vec[1], lastVal);

        std::string joltStr = std::to_string(firstMax) + std::to_string(secondMax);
        int jolt = std::stoi(joltStr);
        totalJoltage += jolt;
    }

    return totalJoltage;
}

int main(int argc, char *argv[])
{
    std::cout << getMaxJoltage(argv[1]) << std::endl;
}