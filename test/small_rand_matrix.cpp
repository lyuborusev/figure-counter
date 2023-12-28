#include <gtest/gtest.h>
#include "../figure-counter/strategies/grid_traverse.h"
#include "../figure-counter/strategies/strategy_scan.h"
#include "../figure-counter/traverse/strategy_traverse.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, SmallRandomMatrix)
{
    TestInput::MatrixGenerator matrixGenerator;

    for (int i = 0; i < 1000; i++)
    {
        const int rowSize = 125;
        const int colSize = 75;

        const auto matrix = matrixGenerator.getMatrix(rowSize, colSize);

        auto contextBFS = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::Strategy::StrategyTraverse>(
                std::make_unique<FigureCounter::TraverseBFS>()));

        int countBFS = contextBFS->findFigures();

        auto contextScan = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::Strategy::StrategyScan>());

        int countScan = contextScan->findFigures();

        EXPECT_EQ(countBFS, countScan);
    }
}