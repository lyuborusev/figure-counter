#include "strategy.h"

#include <deque>
#include <vector>
#include <algorithm>

#include <iostream>

namespace FigureCounter
{
    int StrategyScan::getFigureCount(const std::unique_ptr<MatrixType> &matrix) const
    {
        const int colSize = matrix->getColSize();
        const int rowSize = matrix->getRowSize();

        std::vector<int> visited(colSize * rowSize, 0);
        /*
                std::cout << std::endl;
                for (int i = 0; i < rowSize; i++)
                {
                    for (int j = 0; j < colSize; j++)
                    {
                        std::cout << visited[i + colSize + j];
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
        */
        int labelCount = 0;
        std::vector<int> labels;

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
                        int jUp = j - 1;
                        if (visited[i * colSize + jUp] > 0)
                        {
                            labelUp = visited[i * colSize + jUp];
                        }
                    }

                    if (i - 1 >= 0)
                    {
                        int iLeft = i - 1;
                        if (visited[iLeft * colSize + j] > 0)
                        {
                            labelLeft = visited[iLeft * colSize + j];
                        }
                    }

                    if (labelUp != INT_MAX && labelLeft != INT_MAX)
                    {
                        // MERGE
                        if (labelUp != labelLeft)
                        {
                            int label = std::min(labelUp, labelLeft);
                               auto iter = std::find(labels.begin(), labels.end(), label);
                               if (iter != labels.end())
                               {
                                   labels.erase(iter);
                               }
                            labelCount--;

                            int newLabel = std::max(labelUp, labelLeft);
                            std::replace(visited.begin(), visited.end(), label, newLabel);
                        }

                        visited[i * colSize + j] = std::max(labelUp, labelLeft);
                    }
                    else if (labelUp != INT_MAX || labelLeft != INT_MAX)
                    {
                        // JUST ONE
                        visited[i * colSize + j] = std::min(labelUp, labelLeft);
                    }
                    else
                    {
                        // NEW
                        labelCount++;

                        // labels.push_back(maxLabel);
                        visited[i * colSize + j] = maxLabel++;
                    }
                }
            }
        }
        /*
                for (int i = 0; i < rowSize; i++)
                {
                    for (int j = 0; j < colSize; j++)
                    {
                        char c = matrix->isMarked(i * colSize + j) == true ? 'X' : ' ';
                        std::cout << c << '\t';
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                std::cout << std::endl;

                for (int i = 0; i < rowSize; i++)
                {
                    for (int j = 0; j < colSize; j++)
                    {
                        int vis = visited[i * colSize + j];
                        if (vis > 0)
                        {
                            std::cout << vis;
                        }
                        else
                        {
                            std::cout << ' ';
                        }

                        std::cout << '\t';
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;

                std::cout << std::endl;
                for (int i = 0; i < labels.size(); i++)
                {
                    std::cout << labels[i] << ' ';
                }
                std::cout << std::endl;
        */
        return labelCount;
    }
}