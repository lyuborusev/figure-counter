#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"

TEST(FigureCounter, MockStrategy)
{
    auto context = new FigureCounter::Context(
        std::make_unique<FigureCounter::MatrixType>(std::vector<char>({}), 0, 0),
        std::make_unique<FigureCounter::StrategyMock>());

    int count = context->findFigures();

    EXPECT_EQ(count, 1);
}
