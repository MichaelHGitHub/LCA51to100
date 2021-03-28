#include "header.h"

bool searchMatrix2(vector<vector<int>>& matrix, int target)
{
    bool result = false;
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int col = n - 1;
    
    while (row < m & col >= 0)
    {
        if (matrix[row][col] == target)
        {
            result = true;
            break;
        }
        else if (matrix[row][col] > target)
        {
            --col;
        }
        else
        {
            ++row;
        }
    }

    return result;
}