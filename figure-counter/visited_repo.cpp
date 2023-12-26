#include "visited_repo.h"
#include <algorithm>

namespace FigureCounter
{
    bool VisitedRepo::isVisited(const MatrixType::Iterator &iter) const
    {
        return std::find(visited.begin(), visited.end(), iter) != visited.end();
    }

    void VisitedRepo::addVisited(const MatrixType::Iterator &iter)
    {
        visited.push_back(iter);
    }
}
