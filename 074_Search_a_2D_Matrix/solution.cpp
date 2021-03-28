#include "header.h"

// 2D array is a folded version of 1D array, so we can do binary
// search on 2D array with a little mapping from 1d space to 2d space.
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    bool result = false;
    int m = matrix.size();
    int n = matrix[0].size();
    int len = m * n;

    int left = 0; 
    int right = len - 1;

    while (right >= left)
    {
        int mid = (right + left) / 2;

        // Map 1D index to 2D indexes.
        int row = mid / n;
        int col = mid % n ;

        if (matrix[row][col] == target)
        {
            result = true;
            break;
        }
        else if (matrix[row][col] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }

    return result;
}