#pragma once

#include "matrix.h"

namespace FigureCounter
{
    class VisitedRepo
    {
    public:
        bool isVisited(const MatrixType::Iterator &iter) const;
        void addVisited(const MatrixType::Iterator &iter);

    private:
        std::vector<MatrixType::Iterator> visited;
    };
}