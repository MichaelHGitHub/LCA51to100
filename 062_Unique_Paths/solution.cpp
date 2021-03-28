#include "header.h"

int findPathes(vector<vector<int>>& grid, int m, int n, int row, int col);

// Use DP. Allocate a 2 dimensional array(m X n) to save the possibilities
// of a cell from which traverse to the destination(m-1, n-1).
// the possibilities of a cell c[row][col] = c[row+1][col] + c[row][col+1].
int uniquePaths(int m, int n)
{
    if (m == 1 && n == 1)
    {
        return 1;
    }

    vector<vector<int>> grid(m, vector<int>(n, -1));
    return findPathes(grid, m, n, 0, 0);
}

int findPathes(vector<vector<int>>& grid, int m, int n, int row, int col)
{
    // from destination to destination, one possibility.
    if (row == m - 1 && col == n - 1 )
    {
        grid[row][col] = 1;
        return 1;
    }

    // If we already know the possibilites of cell, no need to calculate again.
    if (grid[row][col] != -1)
    {
        return grid[row][col];
    }

    int path_down = 0;
    int path_right = 0;
    if (row < m-1)
    {
        path_down = findPathes(grid, m, n, row + 1, col);
    }

    if (col < n-1)
    {
        path_right = findPathes(grid, m, n, row, col + 1);
    }

    grid[row][col] = path_down + path_right;

    return grid[row][col];
}