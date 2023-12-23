#include <gtest/gtest.h>
#include "../figure-counter/strategy.h"
#include "../figure-counter/context.h"

std::vector<std::vector<char>> exampleMatrix = {
    {'X', 'O', 'O', 'O', 'O'},
    {'X', 'O', 'X', 'X', 'O'},
    {'O', 'X', 'O', 'X', 'O'},
    {'O', 'X', 'X', 'X', 'O'},
    {'O', 'O', 'O', 'O', 'X'},
};

TEST(FigureCounter, MockStrategy)
{
    auto figureMatrix = std::shared_ptr<FigureCounter::FigureMatrix>(new FigureCounter::FigureMatrixImpl<char, 'X'>(exampleMatrix));
    auto context = new FigureCounter::Context(
        figureMatrix,
        std::make_unique<FigureCounter::StrategyMock>());

    int count = context->findFigures();

    EXPECT_EQ(count, 1);
}
