#include "header.h"

bool searchMatrix_r(vector<vector<int>>& matrix, int target)
{
    // First find the row using binary search.
    int row = 0;
    int begin = 0;
    int end = matrix.size() - 1;
    while (begin <= end)
    {
        int mid = (end + begin) / 2;
        if (matrix[mid][0] == target)
        {
            return true;
        }
        else if (matrix[mid][0] < target)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    row = begin - 1;
    // Adjust row index
    row = max(row, 0);
    row = min(row, (int)(matrix.size() - 1));

    // Search the target in the determined row using binary search again.
    begin = 0;
    end = matrix[row].size() - 1;
    while (begin <= end)
    {
        int mid = (end + begin) / 2;
        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] < target)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return false;
}