#include "header.h"

int uniquePaths_r(int m, int n)
{
    // An two-dimensional array to hold the path number of
    // each cell that can reach the bottom-right.
    vector<vector<int>> scores(m, vector<int>(n, 0));

    // Every cell on the right edge has only one way to 
    // reach bottom right.
    for (int r = m - 1; r >= 0; r--)
    {
        scores[r][n - 1] = 1;
    }

    // Every cell on the bottom edge has only one way to reach
    // bottom right.
    for (int c = n - 1; c >= 0; c--)
    {
        scores[m - 1][c] = 1;
    }

    // Every cell else: the number of the right-next cell plus the number of
    // the down-next cell.
    for (int r = m - 2; r >= 0; r--)
    {
        for (int c = n - 2; c >= 0; c--)
        {
            scores[r][c] = scores[r][c + 1] + scores[r + 1][c];
        }
    }

    return scores[0][0];
}