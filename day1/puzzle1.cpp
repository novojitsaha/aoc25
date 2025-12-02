#include <string>
#include <vector>
#include <iostream>
#include <fstream>

int crackPassword(std::string filePath)
{
    std::fstream inFile(filePath);
    if (!inFile)
    {
        std::cerr << "Unable to open input file." << std::endl;
        return -1;
    }

    std::string ins;
    int password = 0;
    int position = 50;

    while (std::getline(inFile, ins))
    {
        std::string direction = ins.substr(0, 1);
        int n = std::stoi(ins.substr(1));

        position = direction == "L" ? (position - n) : (position + n);

        position = (position % 100);
        if (position < 0)
            position += 100;

        if (position == 0)
            password++;
    }
    return password;
}

int main(int argc, char *argv[])
{
    std::cout << crackPassword(argv[1]) << std::endl;
}