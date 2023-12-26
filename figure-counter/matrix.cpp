#include "matrix.h"
#include <stdexcept>

namespace FigureCounter
{
    template <typename TElement, const TElement FULL>
    Matrix<TElement, FULL>::Matrix(std::vector<TElement> _data, int _rowSize, int _colSize)
        : data(_data),
          rowSize(_rowSize),
          colSize(_colSize)
    {
        if (data.size() != _rowSize * _colSize)
        {
            throw std::logic_error("Invalid Matrix data.");
        }
    }

    template <typename TElement, const TElement FULL>
    bool Matrix<TElement, FULL>::isMarked(int index)
    {
        return data[index] == FULL;
    }

    template <typename TElement, const TElement FULL>
    std::vector<int> Matrix<TElement, FULL>::getNeighbors(int index)
    {
        const std::vector<std::pair<int, int>> offsets = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}};

        const int row = index / colSize;
        const int col = index % colSize;

        std::vector<int> neighbors;
        for (auto offset : offsets)
        {
            const int rowOffset = row + offset.first;
            const int colOffset = col + offset.second;
            if (IsInBounds(0, rowSize, rowOffset) &&
                IsInBounds(0, colSize, colOffset))
            {
                neighbors.push_back(colOffset * colSize + rowOffset);
            }
        }

        return neighbors;
    }

    template <typename TElement, const TElement FULL>
    bool Matrix<TElement, FULL>::IsInBounds(int min, int max, int val)
    {
        return val >= min && val < max;
    }
    template <typename TElement, const TElement FULL>
    int Matrix<TElement, FULL>::getRowSize() const
    {
        return rowSize;
    }
    template <typename TElement, const TElement FULL>
    int Matrix<TElement, FULL>::getColSize() const
    {
        return colSize;
    }

    template class Matrix<char, 'X'>;
}