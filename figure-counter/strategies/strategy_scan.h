#pragma once

#include "../strategy.h"
#include "../utils/matrix.h"
#include "../utils/visited_repo.h"
#include <memory>

namespace FigureCounter::Strategy
{
    class StrategyScan : public FigureCountStrategy
    {
    public:
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const;
    };
}