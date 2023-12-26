#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, BFSStrategy)
{
    auto context = new FigureCounter::Context(
        std::make_unique<FigureCounter::MatrixType>(TestInput::getExampleMatrixOfChar(), 5, 5),
        std::make_unique<FigureCounter::StrategyBFS>());

    int count = context->findFigures();

    EXPECT_EQ(count, 3);
}
