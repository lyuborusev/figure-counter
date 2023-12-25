#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, MatrixTypeChar)
{
    auto figureMatrix = std::shared_ptr<FigureCounter::FigureMatrix>(new FigureCounter::FigureMatrixImpl<char, 'X'>(TestInput::getExampleMatrixOfChar()));
    auto context = new FigureCounter::Context(
        figureMatrix,
        std::make_unique<FigureCounter::StrategyMock>());

    int count = context->findFigures();

    EXPECT_EQ(count, 1);
}

TEST(FigureCounter, MatrixTypeInt)
{
    auto figureMatrix = std::shared_ptr<FigureCounter::FigureMatrix>(new FigureCounter::FigureMatrixImpl<int, 1>(TestInput::getExampleMatrixOfInt()));
    auto context = new FigureCounter::Context(
        figureMatrix,
        std::make_unique<FigureCounter::StrategyMock>());

    int count = context->findFigures();

    EXPECT_EQ(count, 1);
}
