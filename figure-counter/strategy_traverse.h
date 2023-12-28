#pragma once

#include "matrix.h"
#include "strategy.h"
#include "traverse/strategy_traverse.h"
#include "visited_repo.h"
#include <memory>

namespace FigureCounter
{
    class StrategyTraverse : public FigureCountStrategy
    {
    public:
        StrategyTraverse(std::unique_ptr<TraverseStrategy> _traverseStrategy);
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const;

    private:
        std::unique_ptr<TraverseStrategy> traverseStrategy;
    };

}