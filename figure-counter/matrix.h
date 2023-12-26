#pragma once

#include <vector>

namespace FigureCounter
{
    template <typename TElement, const TElement FULL>
    class Matrix
    {
    public:
        Matrix(std::vector<TElement> _data, int _rowSize, int _colSize);
        bool isMarked(int index);

        std::vector<int> getNeighbors(int index);

        int getRowSize() const;
        int getColSize() const;

    private:
        bool IsInBounds(int min, int max, int val);

        std::vector<TElement> data;
        const int rowSize;
        const int colSize;
    };

    typedef Matrix<char, 'X'> MatrixType;
}