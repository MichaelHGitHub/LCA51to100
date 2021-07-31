#include "header.h"

vector<vector<int>> generateMatrix_r(int n)
{
    vector<vector<int>> result(n, vector<int>(n, 0));

    int i = 1;
    int upper = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int r = upper;
    int c = left;

    while (upper <= bottom && left <= right)
    {
        while (c <= right)
        {
            result[r][c++] = i++;
        }
        ++upper;
        r = upper;
        c = right;

        while (r <= bottom)
        {
            result[r++][c] = i++;
        }
        --right;
        c = right;
        r = bottom;

        while (c >= left)
        {
            result[r][c--] = i++;
        }
        --bottom;
        r = bottom;
        c = left;

        while (r >= upper)
        {
            result[r--][c] = i++;
        }
        ++left;
        c = left;
        r = upper;
    }

    return result;
}