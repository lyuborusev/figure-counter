#include "input_data.h"

namespace TestInput
{

// x o x o x o x
// x o o o o o x    
// x x x x x x x   
// 
// 
// 
        //    'X', 'O', 'O', 'O', 'O', /**/
        //    'X', 'O', 'X', 'X', 'O', /**/
        //    'O', 'X', 'O', 'X', 'O', /**/
        //    'O', 'X', 'X', 'X', 'O', /**/
        //    'O', 'O', 'O', 'O', 'X', /**/
        
    std::vector<char> getExampleMatrixOfChar()
    {
        return {
            'X', 'O', 'O', 'O', 'O', /**/
            'X', 'O', 'X', 'X', 'O', /**/
            'O', 'X', 'O', 'X', 'O', /**/
            'O', 'X', 'X', 'X', 'O', /**/
            'O', 'O', 'O', 'O', 'X', /**/
        };
    }

    MatrixGenerator::MatrixGenerator() : randEngine(42),
                                         distribMarked(0, 100),
                                         percentMarked(30)
    {
    }

    std::vector<char> MatrixGenerator::getMatrix(int rowSize, int colSize)
    {
        std::vector<char> matrix;
        matrix.resize(rowSize * colSize, 'O');

        for (auto it = matrix.begin(); it != matrix.end(); it++)
        {
            int randRoll = distribMarked(randEngine);
            if (randRoll < percentMarked)
            {

                *it = 'X';
            }
        }

        return matrix;
    }
}