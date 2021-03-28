#include "header.h"

// Step by step move forward. 
// low and high boundary move toward each other by 1 respectively.
// Boundary check when move over the edges. 
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;

    int low_row = 0;
    int high_row = matrix.size() -1;
    int low_col = 0;
    int high_col = matrix[0].size() - 1;

    while(high_row >= low_row && high_col >= low_col)
    {
        int cur_row = low_row;
        int cur_col = low_col;

        int row_step = 0;
        int col_step = 1;

        // Fill the first element of each round
        result.push_back(matrix[cur_row][cur_col]);
        cur_row += row_step;
        cur_col += col_step;

        // Start from the second element, when it reaches the first
        // element again, the current round if finished.
        while (!(cur_row == low_row && cur_col == low_col))
        {
            if (cur_col == high_col + 1)
            {
                // Have to check this to avoid redoing in single row
                // case
                if (cur_row < high_row)
                {
                    cur_col = high_col;
                    ++cur_row;
                    row_step = 1;
                    col_step = 0;
                }
                else
                {
                    break;
                }
            }

            if (cur_row == high_row + 1)
            {
                // have to check to avoid redoing in single column case
                if (cur_col > low_col)
                {
                    cur_row = high_row;
                    --cur_col;
                    row_step = 0;
                    col_step = -1;
                }
                else
                {
                    break;
                }
            }

            if (cur_col == low_col - 1)
            {
                // Have to check this to avoid redoing in single row
                // case
                if (cur_row > low_row)
                {
                    cur_col = low_col;
                    --cur_row;
                    row_step = -1;
                    col_step = 0;
                }
                else
                {
                    break;
                }
            }

            // Reaches the starting element in the current round
            if (cur_row <= low_row && cur_col == low_col)
            {
                break;
            }

            result.push_back(matrix[cur_row][cur_col]);

            cur_row += row_step;
            cur_col += col_step;
        }

        ++low_row;
        --high_row;
        ++low_col;
        --high_col;

   }

    return result;
}