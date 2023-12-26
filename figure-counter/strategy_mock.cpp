#include "strategy.h"

namespace FigureCounter
{
    int StrategyMock::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        return 1;
    }
}