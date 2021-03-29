#include "header.h"

static void buildCombination(vector<vector<int>>& result, vector<int>& combine, int n, int k);

vector<vector<int>> combine(int n, int k) {

    vector<vector<int>> result;
    vector<int> combine;

    buildCombination(result, combine, n, k);

    return result;
}

void buildCombination(vector<vector<int>>& result, vector<int>& combine, int n, int k)
{
    if (k == 0)
    {
        result.push_back(combine);
        return;
    }

    // Include the current number and continue to build the rest of the 
    // set. Once the current number is used, skip it and use next number.
    for (int i = n; i > 0; i--)
    {
        combine.push_back(i);
        buildCombination(result, combine, i - 1, k - 1);
        combine.pop_back();
    }
}