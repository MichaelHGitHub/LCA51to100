#include "header.h"

static int findPath(vector<vector<int>>& path_grid, vector<vector<int>>& obstacleGrid, int row, int col);

// Base on Algorithm 63(unique path), just need to handle one more thing:
// check if obstacleGrid[row][col] = 0, if yes, the path possibility for that
// cell is 0.
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    vector<vector<int>> path_grid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    return findPath(path_grid, obstacleGrid, 0, 0);
}

int findPath(vector<vector<int>>& path_grid, vector<vector<int>>& obstacleGrid, int row, int col)
{
    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1)
    {
        if (obstacleGrid[row][col] == 1)
        {
            path_grid[row][col] = 0;
        }
        else
        {
            path_grid[row][col] = 1;
        }
        
        return path_grid[row][col];
    }

    // If the element is an obstacle, no need to proceed, the later
    // useful elements will be covered by other path. 
    if (obstacleGrid[row][col] == 1)
    {
        path_grid[row][col] = 0;
        return 0;
    }

    if (path_grid[row][col] != -1)
    {
        return path_grid[row][col];
    }

    int right_path = 0;
    int down_path = 0;

    if (row < obstacleGrid.size() - 1)
    {
        down_path = findPath(path_grid, obstacleGrid, row + 1, col);
    }

    if (col < obstacleGrid[0].size() - 1)
    {
        right_path = findPath(path_grid, obstacleGrid, row, col + 1);
    }

    path_grid[row][col] = right_path + down_path;

    return path_grid[row][col];
}