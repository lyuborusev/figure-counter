#pragma once

#include "matrix.h"
#include "visited_repo.h"
#include <memory>

namespace FigureCounter
{
    class IStrategy
    {
    public:
        virtual ~IStrategy();
    };

    class FigureCountStrategy : public IStrategy
    {
    public:
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const = 0;
    };
}