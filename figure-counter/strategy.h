#pragma once

#include <memory>

namespace FigureCounter
{

    class FigureMatrix
    {
    public:
        virtual bool isMarked(int i, int j) = 0;
    };

    class Strategy
    {
    public:
        virtual int getFigureCount(std::shared_ptr<FigureMatrix> matrix) = 0;
        virtual ~Strategy();
    };

    class StrategyMock : public Strategy
    {
    public:
        virtual int getFigureCount(std::shared_ptr<FigureMatrix> matrix);
    };
}