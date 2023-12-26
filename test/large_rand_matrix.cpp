#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, LargeRandomMatrix)
{
    TestInput::MatrixGenerator matrixGenerator;

    for (int i = 0; i < 1; i++)
    {
        const int rowSize = 15000;
        const int colSize = 7000;

        const auto matrix = matrixGenerator.getMatrix(rowSize, colSize);

        auto context = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::StrategyBFS>());

        int count = context->findFigures();

        EXPECT_EQ(count, 0);
    }
}
