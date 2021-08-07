#include "header.h"

int minPathSum_r(vector<vector<int>>& grid)
{
    int m = grid.size(); 
    int n = grid[0].size();

    // An 2-D array to save the shortest path to bottom right of
    // each cell in grid
    vector < vector<int>> dp(m, vector<int>(n, 0));

    dp[m - 1][n - 1] = grid[m - 1][n - 1];

    // Calculate shortest path for the right edge cells.
    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
    }

    // Calculate shortest path for the bottom edge cells
    for (int j = n - 2; j >= 0; j--)
    {
        dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];
    }

    // Calculate shortest path for the other cells.
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
        }
    }

    return dp[0][0];
}