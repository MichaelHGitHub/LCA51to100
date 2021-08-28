#include "header.h"

void setZeroes_r(vector<vector<int>>& matrix)
{
    bool find_mark = false;
    bool erase_the_row = false;
    int mark_row = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        erase_the_row = false;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (0 == matrix[i][j])
            {
                if (find_mark && i != mark_row)
                {
                    erase_the_row = true;
                    matrix[mark_row][j] = 0;
                }
                else
                {
                    erase_the_row = false;
                    find_mark = true;
                    mark_row = i;
                }
            }
        }

        if (erase_the_row)
        {
            for (int k = 0; k < matrix[i].size(); k++)
            {
                matrix[i][k] = 0;
            }
        }
    }

    if (find_mark)
    {
        for (int j = 0; j < matrix[mark_row].size(); j++)
        {
            if (0 == matrix[mark_row][j])
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int k = 0; k < matrix[mark_row].size(); k++)
        {
            matrix[mark_row][k] = 0;
        }
    }
}