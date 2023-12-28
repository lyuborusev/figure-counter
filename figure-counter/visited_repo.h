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
        int getLabel(int index) const;

        void display() const;

    private:
        const int colSize;
        const int rowSize;

        std::vector<int> visited;
    };
}