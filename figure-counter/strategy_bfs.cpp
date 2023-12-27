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
            if (matrix->isMarked(index) && visited.isVisited(index) == 0)
            {
                ++count;

                traverseFigureBFS(matrix, visited, index, count);
            }
        }
        /*
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                int vis = visited.visited[i * colSize + j];
                if (vis > 0)
                {
                    std::cout << vis;
                }
                else
                {
                    std::cout << ' ';
                }

                std::cout << '\t';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */
        return count;
    }

    void StrategyBFS::traverseFigureBFS(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, int index, int label) const
    {
        std::deque<int> elements;
        elements.push_back(index);

        while (!elements.empty())
        {
            auto el = elements.front();
            elements.pop_front();

            visited.addVisited(el, label);

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