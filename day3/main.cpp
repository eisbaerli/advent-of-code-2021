#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <valarray>

size_t readFromFilePart1(const std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    std::vector<unsigned int> zeros;
    zeros.resize(12);
    std::vector<unsigned int> ones;
    ones.resize(12);
    while (std::getline(infile, line))
    {
        for (std::string::size_type i = 0; i < line.size(); ++i)
        {
            if (line[i] == '0')
                zeros[i]++;
            else
                ones[i]++;
        }
    }

    unsigned int gammaRate = 0;
    unsigned int epsilonRate = 0;

    std::reverse(zeros.begin(), zeros.end());
    std::reverse(ones.begin(), ones.end());

    for (unsigned int i = 0; i < zeros.size(); ++ i)
    {
        if (ones[i] > zeros[i])
            gammaRate += std::pow(2,i);
        else
            epsilonRate += std::pow(2,i);
    }
    return gammaRate * epsilonRate;
}

void extractZerosAndOnes(const std::vector<std::vector<unsigned int>> &input,
                         unsigned int i,
                         unsigned int &ones,
                         unsigned int &zeros)
{
    ones= 0;
    zeros= 0;
    for (const auto& l : input)
    {
        if (l[i] == 0)
            zeros++;
        else
            ones++;
    }
}

size_t readFromFilePart2(const std::string& filename)
{
    std::ifstream infile(filename);
    std::vector<std::vector<unsigned int> > input;
    std::string line;
    while (std::getline(infile, line))
    {
        std::vector<unsigned int> lineInput;
        lineInput.resize(12);
        for (std::string::size_type i = 0; i < line.size(); ++i)
        {
            if (line[i] == '0')
            {
                lineInput[i] = 0;
            }
            else
            {
                lineInput[i] = 1;
            }
        }
        input.push_back(lineInput);
    }

    auto oxygen = input;
    auto co2 = input;
    for (unsigned int i = 0; i < line.size(); ++ i)
    {
        unsigned int oxygenOnes = 0;
        unsigned int oxygenZeros = 0;
        extractZerosAndOnes(oxygen, i, oxygenOnes, oxygenZeros);

        unsigned int co2Ones = 0;
        unsigned int co2Zeros = 0;
        extractZerosAndOnes(co2, i, co2Ones, co2Zeros);

        if (oxygenOnes >= oxygenZeros)
        {
            if (oxygen.size() > 1)
            oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [&i](const auto& lineInput){return lineInput[i] == 0;}), oxygen.end());
        }
        else
        {
            if (oxygen.size() > 1)
            oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [&i](const auto& lineInput){return lineInput[i] == 1;}), oxygen.end());
        }

        if (co2Zeros <= co2Ones)
        {
            if (co2.size() > 1)
            co2.erase(std::remove_if(co2.begin(), co2.end(), [&i](const auto& lineInput){return lineInput[i] == 1;}), co2.end());
        }
        else
        {
            if (co2.size() > 1)
            co2.erase(std::remove_if(co2.begin(), co2.end(), [&i](const auto& lineInput){return lineInput[i] == 0;}), co2.end());
        }
    }

    unsigned int oxygenRating = 0;
    std::reverse(oxygen[0].begin(), oxygen[0].end());
    for (unsigned int i = 0; i < oxygen[0].size(); ++i)
        oxygenRating += oxygen[0][i] * std::pow(2,i);

    unsigned int co2Rating = 0;
    std::reverse(co2[0].begin(), co2[0].end());
    for (unsigned int i = 0; i < co2[0].size(); ++i)
        co2Rating += co2[0][i] * std::pow(2,i);
    return oxygenRating * co2Rating;
}

int main()
{
    size_t countPart1 = readFromFilePart1("../input");
    size_t countPart2 = readFromFilePart2("../input");
    std::cout << "What is the power consumption of the submarine?" << std::endl;
    std::cout << "Answer part 1: " << countPart1 << std::endl;
    std::cout << "What is the life support rating of the submarine?" << std::endl;
    std::cout << "Answer part 2: " << countPart2 << std::endl;
    return 0;
}
