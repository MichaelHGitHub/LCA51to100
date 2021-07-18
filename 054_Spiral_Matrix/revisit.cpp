#include "header.h"

vector<int> spiralOrder_r(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> result(rows * cols, 0);

    // Define boundaries
    int upper = 0, bottom = rows - 1, left = 0, right = cols - 1;
    // Define indices to retrieve elements
    int i = 0, r = 0, c = 0;

    while (left <= right && upper <= bottom)
    {
        // First go right
        while (c <= right)
        {
            result[i++] = matrix[r][c++];
        }
        c = right;
        ++r;
        ++upper;

        // Second go down
        while (r <= bottom)
        {
            result[i++] = matrix[r++][c];
        }
        r = bottom;
        --c;
        --right;

        // Then go left, check if repeating the path of going right
        while (r >= upper && c >= left)
        {
            result[i++] = matrix[r][c--];
        }
        c = left;
        --r;
        --bottom;

        // Finally go up, check if repeating the path of going down
        while (c <= right && r >= upper)
        {
            result[i++] = matrix[r--][c];
        }
        r = upper;
        ++c;
        ++left;
    }
    return result;
}