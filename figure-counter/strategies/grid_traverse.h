#pragma once

#include "../strategy.h"
#include "../utils/matrix.h"
#include "../utils/visited_repo.h"
#include "../traverse/strategy_traverse.h"
#include <memory>

namespace FigureCounter::Strategy
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