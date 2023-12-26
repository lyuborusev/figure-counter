#include "visited_repo.h"
#include <algorithm>

namespace FigureCounter
{
    VisitedRepo::VisitedRepo(int colSize, int rowSize)
        : visited(colSize * rowSize, false)
    {
    }

    bool VisitedRepo::isVisited(int index) const
    {
        return visited[index];
    }

    void VisitedRepo::addVisited(int index)
    {
        visited[index] = true;
    }
}
