#include <gtest/gtest.h>
#include "../figure-counter/strategy_traverse.h"
#include "../figure-counter/strategy_scan.h"
#include "../figure-counter/traverse/strategy_traverse.h"
#include "../figure-counter/context.h"
#include "input_data.h"

TEST(FigureCounter, MediumRandomMatrix)
{
    TestInput::MatrixGenerator matrixGenerator;

    for (int i = 0; i < 10; i++)
    {
        const int rowSize = 575;
        const int colSize = 525;

        const auto matrix = matrixGenerator.getMatrix(rowSize, colSize);

        auto contextBFS = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::StrategyTraverse>(
                std::make_unique<FigureCounter::TraverseBFS>()));

        int countBFS = contextBFS->findFigures();

        auto contextScan = new FigureCounter::Context(
            std::make_unique<FigureCounter::MatrixType>(matrix, rowSize, colSize),
            std::make_unique<FigureCounter::StrategyScan>(std::make_unique<FigureCounter::TraverseBFS>()));

        int countScan = contextScan->findFigures();

        EXPECT_EQ(countBFS, countScan);
    }
}