#include "header.h"

void setZeroes(vector<vector<int>>& matrix)
{
    vector<bool> rows(matrix.size(), false);
    vector<bool> cols(matrix[0].size(), false);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (int i = 0; i < rows.size(); i++)
    {
        if (rows[i])
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < cols.size(); j++)
    {
        if (cols[j])
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}