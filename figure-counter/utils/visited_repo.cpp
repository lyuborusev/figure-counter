#include "visited_repo.h"
#include <algorithm>
#include <iostream>

namespace FigureCounter
{
    VisitedRepo::VisitedRepo(int _colSize, int _rowSize)
        : colSize(_colSize),
          rowSize(_rowSize),
          visited(colSize * rowSize, 0)
    {
    }

    bool VisitedRepo::isVisited(int index) const
    {
        return visited[index] > 0;
    }

    void VisitedRepo::addVisited(int index, int label)
    {
        visited[index] = label;
    }

    int VisitedRepo::getLabel(int index) const
    {
        return visited[index];
    }

    void VisitedRepo::display() const
    {
        std::cout << std::endl;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                int vis = visited[i * colSize + j];
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
    }
}
