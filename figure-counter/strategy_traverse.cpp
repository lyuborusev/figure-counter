#include "strategy_traverse.h"

#include <deque>
#include <vector>
#include <algorithm>

#include <iostream>

namespace FigureCounter
{
    StrategyTraverse::StrategyTraverse(std::unique_ptr<TraverseStrategy> _traverseStrategy)
        : traverseStrategy(std::move(_traverseStrategy))
    {
    }

    int StrategyTraverse::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        const int colSize = matrix->getColSize();
        const int rowSize = matrix->getRowSize();

        VisitedRepo visited(colSize, rowSize);

        int count = 0;
        int size = colSize * rowSize;
        for (int index = 0; index < size; index++)
        {
            if (matrix->isMarked(index) && !visited.isVisited(index))
            {
                ++count;

                traverseStrategy->traverse(matrix, visited, index, count);
            }
        }

        return count;
    }
}