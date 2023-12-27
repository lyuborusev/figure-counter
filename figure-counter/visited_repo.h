#pragma once

#include "matrix.h"

namespace FigureCounter
{
    class VisitedRepo
    {
    public:
        VisitedRepo(int colSize, int rowSize);
        bool isVisited(int index) const;
        void addVisited(int index, int label);

    private:
    public:
        std::vector<int> visited;
    };
}