#pragma once

#include <vector>

namespace FigureCounter
{
    template <typename TElement, const TElement FULL>
    class Matrix
    {
    public:
        typedef typename std::vector<TElement>::iterator Iterator;

        Matrix(std::vector<TElement> _data, int _rowSize, int _colSize);
        bool isMarked(Iterator iter);

        Iterator begin();
        Iterator end();

        std::vector<Iterator> getNeighbors(const Iterator &iter);

    private:
        bool IsInBounds(int min, int max, int val);

        std::vector<TElement> data;
        const int rowSize;
        const int colSize;
    };

    typedef Matrix<char, 'X'> MatrixType;
}