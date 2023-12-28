#pragma once

#include "../matrix.h"
#include "../strategy.h"
#include "../visited_repo.h"
#include "element_queue.h"
#include <memory>

namespace FigureCounter
{
    class TraverseStrategy : public IStrategy
    {
    public:
        virtual void traverse(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, int index, int label) const = 0;
    };

    template <typename ElementQueue>
    class Traverse : public TraverseStrategy
    {
    public:
        virtual void traverse(const std::unique_ptr<MatrixType> &matrix, VisitedRepo &visited, int index, int label) const;
    };

    typedef Traverse<QueueFIFOType> TraverseBFS;
    typedef Traverse<QueueStackType> TraverseDFS;
}