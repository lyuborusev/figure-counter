#pragma once

#include <vector>
#include <random>

namespace TestInput
{
    std::vector<char> getExampleMatrixOfChar();

    class MatrixGenerator
    {
    public:
        MatrixGenerator();
        std::vector<char> getMatrix(int rowSize, int colSize);

    private:
        std::mt19937 randEngine;
        std::uniform_int_distribution<> distribMarked;
        const int percentMarked;
    };
}