#pragma once

#include <memory>
#include <vector>
#include "strategy.h"

namespace FigureCounter
{
    class Context
    {
    public:
        explicit Context(std::shared_ptr<FigureMatrix> _matrix, std::unique_ptr<Strategy> &&_strategy);
        int findFigures() const;

    private:
        std::shared_ptr<FigureMatrix> matrix;
        std::unique_ptr<Strategy> strategy;
    };

    template <typename TElement, const TElement FULL>
    class FigureMatrixImpl : public FigureMatrix
    {
    public:
        FigureMatrixImpl(std::vector<std::vector<TElement>> _data) : data(_data)
        {
        }
        virtual bool isMarked(int i, int j)
        {
            return data[i][j] == FULL;
        }

    private:
        std::vector<std::vector<TElement>> data;
    };
}
