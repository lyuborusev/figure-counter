#include <gtest/gtest.h>
#include "../figure-counter/strategy_traverse.h"
#include "../figure-counter/strategy_scan.h"
#include "../figure-counter/traverse/strategy_traverse.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, ExampleTestBFS)
{
    auto context = new FigureCounter::Context(
        std::make_unique<FigureCounter::MatrixType>(TestInput::getExampleMatrixOfChar(), 5, 5),
        std::make_unique<FigureCounter::StrategyTraverse>(
            std::make_unique<FigureCounter::TraverseBFS>()));

    int count = context->findFigures();

    EXPECT_EQ(count, 3);
}

TEST(FigureCounter, ExampleTestDFS)
{
    auto context = new FigureCounter::Context(
        std::make_unique<FigureCounter::MatrixType>(TestInput::getExampleMatrixOfChar(), 5, 5),
        std::make_unique<FigureCounter::StrategyTraverse>(
            std::make_unique<FigureCounter::TraverseDFS>()));

    int count = context->findFigures();

    EXPECT_EQ(count, 3);
}

TEST(FigureCounter, ExampleTestScan)
{
    auto context = new FigureCounter::Context(
        std::make_unique<FigureCounter::MatrixType>(TestInput::getExampleMatrixOfChar(), 5, 5),
        std::make_unique<FigureCounter::StrategyScan>(std::make_unique<FigureCounter::TraverseDFS>()));

    int count = context->findFigures();

    EXPECT_EQ(count, 3);
}
