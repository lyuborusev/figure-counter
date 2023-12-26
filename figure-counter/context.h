#pragma once

#include <memory>
#include <vector>
#include "strategy.h"
#include <iostream>

namespace FigureCounter
{
    class Context
    {
    public:
        explicit Context(std::unique_ptr<MatrixType> _matrix, std::unique_ptr<Strategy> &&_strategy);
        int findFigures() const;

    private:
        std::unique_ptr<MatrixType> matrix;
        std::unique_ptr<Strategy> strategy;
    };
}
