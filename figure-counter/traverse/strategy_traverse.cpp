#include "strategy_traverse.h"
#include <deque>
#include <stack>

namespace FigureCounter
{
    template <typename ElementQueue>
    void Traverse<ElementQueue>::traverse(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, int index, int label) const
    {
        ElementQueue elementQueue;
        elementQueue.addElement(index);

        while (!elementQueue.empty())
        {
            auto el = elementQueue.nextElement();

            visited.addVisited(el, label);

            auto neighbours = matrix->getNeighbors(el);

            for (auto it : neighbours)
            {
                if (matrix->isMarked(it) && !visited.isVisited(it))
                {
                    elementQueue.addElement(it);
                }
            }
        }
    }

    template class Traverse<QueueFIFOType>;
    template class Traverse<QueueStackType>;
}