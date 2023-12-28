#pragma once

#include "matrix.h"
#include "strategy.h"
#include "traverse/strategy_traverse.h"
#include "visited_repo.h"
#include <memory>

namespace FigureCounter
{
    class StrategyScan : public FigureCountStrategy
    {
    public:
        StrategyScan(std::unique_ptr<TraverseStrategy> _mergeFigureLabels);
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const;

    private:
        std::unique_ptr<TraverseStrategy> mergeFigureLabels;
    };
}