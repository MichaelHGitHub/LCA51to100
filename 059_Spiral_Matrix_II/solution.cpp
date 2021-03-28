#include "header.h"

// Go around the edge of the square, fill in numbers, then increase/decrease
// lower/upper, left/right edges, keep going until all cells are filled.
vector<vector<int>> generateMatrix(int n)
{
    int lower_edge = 0;
    int upper_edge = n - 1;
    int left_edge = 0;
    int right_edge = n- 1;
    int num = 0;

    vector<vector<int>> result(n, vector<int>(n, 0));

    while (upper_edge >= lower_edge && left_edge <= right_edge)
    {
        // First row
        for (int col = left_edge; col <= right_edge; col++)
        {
            result[lower_edge][col] = ++num;
        }

        // Last column
        for (int row = lower_edge + 1; row <= upper_edge; row++)
        {
            result[row][right_edge] = ++num;
        }

        // Last row, when last row is the first row, it is already filled
        if (upper_edge > lower_edge)
        {
            for (int col = right_edge - 1; col >= left_edge; col--)
            {
                result[upper_edge][col] = ++num;
            }
        }

        // First column, when first column is the last column, it is already
        // filled.
        if (right_edge > left_edge)
        {
            // Note: when row=lower, it was filled at the beginning of the around
            for (int row = upper_edge - 1; row > lower_edge; row--)
            {
                result[row][left_edge] = ++num;
            }
        }

        ++lower_edge;
        --upper_edge;
        ++left_edge;
        --right_edge;
    }

    return result;
}