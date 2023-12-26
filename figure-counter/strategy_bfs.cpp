#include "strategy.h"

#include <deque>
#include <vector>
#include <algorithm>

#include <iostream>

namespace FigureCounter
{
    int StrategyBFS::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
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

                traverseFigureBFS(matrix, visited, index);
            }
        }

        return count;
    }

    void StrategyBFS::traverseFigureBFS(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, int index) const
    {
        std::deque<int> elements;
        elements.push_back(index);

        while (!elements.empty())
        {
            auto el = elements.front();
            elements.pop_front();

            visited.addVisited(el);

            auto neighbours = matrix->getNeighbors(el);

            for (auto it : neighbours)
            {
                if (matrix->isMarked(it) && !visited.isVisited(it))
                {
                    elements.push_back(it);
                }
            }
        }
    }
}