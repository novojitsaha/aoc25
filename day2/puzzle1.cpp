#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

void parseRanges(std::string &inputFile, std::vector<std::string> &ranges)
{
    std::string line;
    std::fstream file(inputFile);

    if (file)
    {
        std::getline(file, line);
    }
    else
    {
        std::cerr << "Error reading input file." << std::endl;
    }

    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ','))
    {
        ranges.push_back(token);
    }
}

unsigned long long sumInvalidId(std::string inputFile)
{
    std::vector<std::string> ranges;
    parseRanges(inputFile, ranges);

    unsigned long long sum = 0;
    for (const std::string &range : ranges)
    {
        size_t dash_pos = range.find('-');
        unsigned long long start = std::stoull(range.substr(0, dash_pos));
        unsigned long long end = std::stoull(range.substr(dash_pos + 1));

        for (size_t i = start; i <= end; ++i)
        {
            std::string numString = std::to_string(i);
            if (numString.size() % 2 == 0)
            {
                size_t mid = numString.size() / 2;
                std::string firstHalf = numString.substr(0, mid);
                std::string secondHalf = numString.substr(mid);

                if (firstHalf == secondHalf)
                {
                    unsigned long long num = std::stoull(numString);
                    sum += num;
                }
            }
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    std::cout << sumInvalidId(argv[1]) << std::endl;
}
