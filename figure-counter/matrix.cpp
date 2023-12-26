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
    bool Matrix<TElement, FULL>::isMarked(Iterator iter)
    {
        return *iter == FULL;
    }

    template <typename TElement, const TElement FULL>
    typename Matrix<TElement, FULL>::Iterator Matrix<TElement, FULL>::begin()
    {
        return data.begin();
    }

    template <typename TElement, const TElement FULL>
    typename Matrix<TElement, FULL>::Iterator Matrix<TElement, FULL>::end()
    {
        return data.end();
    }

    template <typename TElement, const TElement FULL>
    std::vector<typename Matrix<TElement, FULL>::Iterator> Matrix<TElement, FULL>::getNeighbors(const typename Matrix<TElement, FULL>::Iterator &iter)
    {
        const std::vector<std::pair<int, int>> offsets = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}};

        const int index = iter - data.begin();
        const int row = index / colSize;
        const int col = index % colSize;

        std::vector<typename Matrix<TElement, FULL>::Iterator> neighbors;
        for (auto offset : offsets)
        {
            const int rowOffset = row + offset.first;
            const int colOffset = col + offset.second;
            if (IsInBounds(0, rowSize, rowOffset) &&
                IsInBounds(0, colSize, colOffset))
            {
                neighbors.push_back(data.begin() + colOffset * colSize + rowOffset);
            }
        }

        return neighbors;
    }

    template <typename TElement, const TElement FULL>
    bool Matrix<TElement, FULL>::IsInBounds(int min, int max, int val)
    {
        return val >= min && val < max;
    }

    template class Matrix<char, 'X'>;
}