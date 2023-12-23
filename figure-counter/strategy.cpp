#include "strategy.h"

namespace FigureCounter
{
    Strategy::~Strategy() {}

    int StrategyMock::getFigureCount(std::shared_ptr<FigureMatrix> matrix)
    {
        return 1;
    }
}