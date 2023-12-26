#include "strategy.h"

#include <deque>
#include <vector>
#include <algorithm>

#include <iostream>

namespace FigureCounter
{
    Strategy::~Strategy() {}

    int StrategyMock::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        return 1;
    }

    int StrategyBFS::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        std::vector<MatrixType::Iterator> visited;

        int count = 0;
        for (auto iter = matrix->begin(); iter != matrix->end(); ++iter)
        {
            if (matrix->isMarked(iter) && std::find(visited.begin(), visited.end(), iter) == visited.end())
            {
                ++count;

                traverseFigureBFS(matrix, visited, iter);
            }
        }

        return count;
    }

    void StrategyBFS::traverseFigureBFS(const std::unique_ptr<MatrixType> &matrix, std::vector<MatrixType::Iterator> &visited, MatrixType::Iterator iter) const
    {
        std::deque<MatrixType::Iterator> elements;
        elements.push_back(iter);

        while (!elements.empty())
        {
            auto el = elements.front();
            elements.pop_front();

            visited.push_back(el);

            auto neighbours = matrix->getNeighbors(el);

            for (auto it : neighbours)
            {
                if (matrix->isMarked(it) && std::find(visited.begin(), visited.end(), it) == visited.end())
                {
                    elements.push_back(it);
                }
            }
        }
    }
}