#pragma once

#include "matrix.h"
#include <memory>

namespace FigureCounter
{
    class Strategy
    {
    public:
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const = 0;
        virtual ~Strategy();
    };

    class StrategyMock : public Strategy
    {
    public:
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const;
    };

    class StrategyBFS : public Strategy
    {
    public:
        virtual int getFigureCount(const std::unique_ptr<MatrixType> &matrix) const;
        void traverseFigureBFS(const std::unique_ptr<MatrixType> &matrix, std::vector<MatrixType::Iterator> &visited, MatrixType::Iterator iter) const;
    };
}