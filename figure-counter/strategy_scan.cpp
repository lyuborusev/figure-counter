#include "strategy_scan.h"

#include <deque>
#include <vector>
#include <algorithm>

namespace FigureCounter
{
    StrategyScan::StrategyScan(std::unique_ptr<TraverseStrategy> _mergeFigureLabels)
        : mergeFigureLabels(std::move(_mergeFigureLabels))
    {
    }

    int StrategyScan::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        const int colSize = matrix->getColSize();
        const int rowSize = matrix->getRowSize();

        VisitedRepo visited(colSize, rowSize);

        int count = 0;
        int maxLabel = 1;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (matrix->isMarked(i * colSize + j))
                {
                    int labelUp = INT_MAX;
                    int labelLeft = INT_MAX;
                    if (j - 1 >= 0)
                    {
                        int index = i * colSize + (j - 1);
                        if (visited.isVisited(index))
                        {
                            labelLeft = visited.getLabel(index);
                        }
                    }

                    if (i - 1 >= 0)
                    {
                        int index = (i - 1) * colSize + j;
                        if (visited.isVisited(index))
                        {
                            labelUp = visited.getLabel(index);
                        }
                    }

                    if (labelUp != INT_MAX && labelLeft != INT_MAX)
                    {
                        // TOUCHING REGIONS UP AND DOWN, CONTINUE WITH THE BIGGER INDEZ
                        if (labelUp != labelLeft)
                        {
                            count--;
                        }

                        visited.addVisited(i * colSize + j, labelLeft);
                    }
                    else if (labelUp != INT_MAX || labelLeft != INT_MAX)
                    {
                        // JUST ONE
                        visited.addVisited(i * colSize + j, std::min(labelUp, labelLeft));
                    }
                    else
                    {
                        count++;
                        visited.addVisited(i * colSize + j, maxLabel++);
                    }
                }
            }
        }

        return count;
    }
}