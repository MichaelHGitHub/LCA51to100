#include "header.h"

int uniquePathsWithObstacles_r(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // A 2 dimensional array to save the number of path of each cell
    vector<vector<long>> scores(m, vector<long>(n, 0));

    // The bottom-right cell's score(destination cell)
    if (obstacleGrid[m - 1][n - 1] != 1)
    {
        scores[m - 1][n - 1] = 1;
    }

    // Fill out the right edge
    for (int i = m - 2; i >= 0; i--)
    {
        if (obstacleGrid[i][n - 1] != 1)
        {
            scores[i][n - 1] = scores[i + 1][n - 1];
        }
    }

    // Fill out the bottom edge
    for (int j = n - 2; j >= 0; j--)
    {
        if (obstacleGrid[m - 1][j] != 1)
        {
            scores[m - 1][j] = scores[m - 1][j + 1];
        }
    }

    // Fill out every cell else
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (obstacleGrid[i][j] != 1)
            {
                scores[i][j] = scores[i][j + 1] + scores[i + 1][j];
            }
        }
    }

    return scores[0][0];
}