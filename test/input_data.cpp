#include "input_data.h"

namespace TestInput
{
    std::vector<std::vector<char>> getExampleMatrixOfChar()
    {
        return {
            {'X', 'O', 'O', 'O', 'O'},
            {'X', 'O', 'X', 'X', 'O'},
            {'O', 'X', 'O', 'X', 'O'},
            {'O', 'X', 'X', 'X', 'O'},
            {'O', 'O', 'O', 'O', 'X'},
        };
    }
    std::vector<std::vector<int>> getExampleMatrixOfInt()
    {
        return {
            {1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1},
        };
    }
}