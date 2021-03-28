#include "header.h"

// Handle each edge in the current rectangle.
// low and high boundary move toward each other by 1 respectively.
// Boundary check when move over the edges. 
vector<int> spiralOrder2(vector<vector<int>>& matrix)
{
    vector<int> result;

    int low_row = 0;
    int high_row = matrix.size() - 1;
    int low_col = 0;
    int high_col = matrix[0].size() - 1;

    while (high_row >= low_row && high_col >= low_col)
    {
        int cur_row = low_row;
        int cur_col = low_col;

        // First row
        for (int i = low_col; i <= high_col; i++)
        {
            result.push_back(matrix[low_row][i]);
        }

        // last column
        for (int i = low_row + 1; i <= high_row; i++)
        {
            result.push_back(matrix[i][high_col]);
        }

        // Last row, check boundary for single row case
        if (high_row > low_row)
        {
            for (int i = high_col - 1; i >= low_col; i--)
            {
                result.push_back(matrix[high_row][i]);
            }
        }

        // First column, check for single column case
        if (high_col > low_col)
        {
            for (int i = high_row - 1; i > low_row; i--)
            {
                result.push_back(matrix[i][low_col]);
            }
        }

        ++low_row;
        --high_row;
        ++low_col;
        --high_col;
    }

    return result;
}