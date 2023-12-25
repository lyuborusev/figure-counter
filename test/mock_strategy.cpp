#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"

TEST(FigureCounter, MockStrategy)
{
    auto figureMatrix = std::shared_ptr<FigureCounter::FigureMatrix>(new FigureCounter::FigureMatrixImpl<char, 'X'>({}));
    auto context = new FigureCounter::Context(
        figureMatrix,
        std::make_unique<FigureCounter::StrategyMock>());

    int count = context->findFigures();

    EXPECT_EQ(count, 1);
}
