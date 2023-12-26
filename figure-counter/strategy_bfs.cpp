#include "strategy.h"

#include <deque>
#include <vector>
#include <algorithm>

#include <iostream>

namespace FigureCounter
{
    int StrategyBFS::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        VisitedRepo visited;

        int count = 0;
        for (auto iter = matrix->begin(); iter != matrix->end(); ++iter)
        {
            if (matrix->isMarked(iter) && !visited.isVisited(iter))
            {
                ++count;

                traverseFigureBFS(matrix, visited, iter);
            }
        }

        return count;
    }

    void StrategyBFS::traverseFigureBFS(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, MatrixType::Iterator iter) const
    {
        std::deque<MatrixType::Iterator> elements;
        elements.push_back(iter);

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