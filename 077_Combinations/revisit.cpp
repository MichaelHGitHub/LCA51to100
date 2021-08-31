#include "header.h"

static void helper(vector<vector<int>>& result, vector<int>& entry, int cur, int n, int pos, int k);

vector<vector<int>> combine_r(int n, int k)
{
    vector<vector<int>> result;
    vector<int> entry(k, 0);
    helper(result, entry, 1, n, 0, k);

    return result;
}

void helper(vector<vector<int>>& result, vector<int>& entry, int cur, int n, int pos, int k)
{
    if (pos >= k)
    {
        result.push_back(entry);
        return;
    }

    for (int i = cur; i <= n; i++)
    {
        entry[pos] = i;
        helper(result, entry, i + 1, n, pos + 1, k);
        entry[pos] = 0;
    }
}