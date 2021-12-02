#include <fstream>
#include <iostream>
#include <string>

size_t readFromFilePart1(const std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    unsigned int depth = 0;
    unsigned int horizontal = 0;
    while (std::getline(infile, line))
    {
        std::size_t found = line.find("forward");
        if (found != std::string::npos)
        {
            unsigned int forward = std::stoi(line.substr(line.find_first_of("0123456789")));
            horizontal += forward;
        }

        found = line.find("down");
        if (found != std::string::npos)
        {
            unsigned int down = std::stoi(line.substr(line.find_first_of("0123456789")));
            depth += down;
        }

        found = line.find("up");
        if (found != std::string::npos)
        {
            unsigned int up = std::stoi(line.substr(line.find_first_of("0123456789")));
            depth -= up;
        }
    }
    return depth * horizontal;
}

size_t readFromFilePart2(const std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    unsigned int depth = 0;
    unsigned int horizontal = 0;
    unsigned int aim = 0;
    while (std::getline(infile, line))
    {
        std::size_t found = line.find("forward");
        if (found != std::string::npos)
        {
            unsigned int forward = std::stoi(line.substr(line.find_first_of("0123456789")));
            horizontal += forward;
            depth += aim * forward;
        }

        found = line.find("down");
        if (found != std::string::npos)
        {
            unsigned int down = std::stoi(line.substr(line.find_first_of("0123456789")));
            aim += down;
        }

        found = line.find("up");
        if (found != std::string::npos)
        {
            unsigned int up = std::stoi(line.substr(line.find_first_of("0123456789")));
            aim -= up;
        }
    }
    return depth * horizontal;
}

int main()
{
    size_t countPart1 = readFromFilePart1("../input");
    size_t countPart2 = readFromFilePart2("../input");
    std::cout << "What do you get if you multiply your final horizontal position by your final depth?" << std::endl;
    std::cout << "Answer part 1: " << countPart1 << std::endl;
    std::cout << "Answer part 2: " << countPart2 << std::endl;
    return 0;
}
