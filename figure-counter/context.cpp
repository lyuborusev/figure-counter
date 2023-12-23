#include "context.h"

#include <memory>

namespace FigureCounter
{

    Context::Context(std::shared_ptr<FigureMatrix> _matrix, std::unique_ptr<Strategy> &&_strategy)
        : matrix(std::move(_matrix)),
          strategy(std::move(_strategy))
    {
    }

    int Context::findFigures() const
    {
        int res = strategy->getFigureCount(matrix);
        return res;
    }
}