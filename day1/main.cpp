#include <fstream>
#include <iostream>
#include <string>

size_t readFromFilePart1(const std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    unsigned int previousDepth = 0;
    size_t count = 0;
    while (std::getline(infile, line))
    {
        unsigned int depth = std::stoi(line);
        if (depth > previousDepth && previousDepth != 0)
            count++;
        previousDepth = depth;
    }
    return count;
}

size_t readFromFilePart2(const std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    unsigned int currentDepth = 0;
    unsigned int previousDepth = 0;
    unsigned int oldDepth = 0;
    unsigned int oldSum = 0;
    size_t count = 0;
    while (std::getline(infile, line))
    {
        unsigned int depth = std::stoi(line);
        oldDepth = previousDepth;
        previousDepth = currentDepth;
        currentDepth = depth;

        if (currentDepth != 0 && previousDepth != 0 && oldDepth != 0)
        {
            unsigned int sum = currentDepth + previousDepth + oldDepth;
            if (sum > oldSum && oldSum != 0)
                count++;
            oldSum = sum;
        }
    }
    return count;
}

int main()
{
    size_t countPart1 = readFromFilePart1("../input");
    size_t countPart2 = readFromFilePart2("../input");
    std::cout << "How many measurements are larger than the previous measurement?" << std::endl;
    std::cout << "Answer part 1: " << countPart1 << std::endl;
    std::cout << "Answer part 2: " << countPart2 << std::endl;
    return 0;
}
