#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, RandomMatrix)
{
    TestInput::MatrixGenerator matrixGenerator;

    for (int i = 0; i < 10; i++)
    {
        //const int rowSize = 125;
        //const int colSize = 75;

        const int rowSize = 15;
        const int colSize = 15;

        const auto matrix = matrixGenerator.getMatrix(rowSize, colSize);

        auto contextBFS = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::StrategyBFS>());

        int countBFS = contextBFS->findFigures();

        auto contextScan = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::StrategyScan>());

        int countScan = contextScan->findFigures();

        EXPECT_EQ(countBFS, countScan);
    }
}