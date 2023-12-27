#include "visited_repo.h"
#include <algorithm>

namespace FigureCounter
{
    VisitedRepo::VisitedRepo(int colSize, int rowSize)
        : visited(colSize * rowSize, 0)
    {
    }

    bool VisitedRepo::isVisited(int index) const
    {
        return visited[index];
    }

    void VisitedRepo::addVisited(int index, int label)
    {
        visited[index] = label;
    }
}
