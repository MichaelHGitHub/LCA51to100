#include "header.h"

int calculatePathSum(vector<vector<int>>& sums, vector<vector<int>>& grid, int row, int col);

// Use DP. Allocate a 2 dimensional array(m X n) to save the smallest path sum
// of a cell from which we traverse to the destination(m-1, n-1).
// the smallest path sum of a cell sums[r][c] = grid[r][c] + (sums[r+1][c] + sums[r][c+1]).
int minPathSum(vector<vector<int>>& grid)
{
    vector<vector<int>> sums(grid.size(), vector<int>(grid[0].size(), -1));
    return calculatePathSum(sums, grid, 0, 0);
}

int calculatePathSum(vector<vector<int>>& sums, vector<vector<int>>& grid, int row, int col)
{
    if (row == grid.size() - 1 && col == grid[0].size() - 1)
    {
        sums[row][col] = grid[row][col];
        return sums[row][col];
    }

    if (sums[row][col] != -1)
    {
        return sums[row][col];
    }

    int sum_down = -1;
    int sum_right = -1;
    if (row < grid.size() - 1)
    {
        sum_down = calculatePathSum(sums, grid, row + 1, col);
    }

    if (col < grid[0].size() - 1)
    {
        sum_right = calculatePathSum(sums, grid, row, col + 1);
    }

    // Careful, the negative sum doesn't count, it means there is no path
    // in that direction.
    if (sum_down >= 0 && sum_right >= 0)
    {
        sums[row][col] = min(sum_down, sum_right) + grid[row][col];
    }
    else if(sum_down >= 0)
    {
        sums[row][col] =sum_down + grid[row][col];
    }
    else
    {
        sums[row][col] = sum_right + grid[row][col];
    }

    return sums[row][col];
}