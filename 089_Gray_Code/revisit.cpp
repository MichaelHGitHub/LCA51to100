#include "header.h"

void getGrayCode(vector<int>& result, int n);

vector<int> grayCode_r(int n)
{
    vector<int> result( 1 << n, 0);
    getGrayCode(result, n);
    return result;
}

void getGrayCode(vector<int>& result, int n)
{
    if (0 == n)
    {
        return;
    }

    getGrayCode(result, n - 1);

    int m = 1 << (n - 1);
    for (int i = m - 1, j = m; i >= 0; i--, j++)
    {
        result[j] = result[i] | m;
    }
}