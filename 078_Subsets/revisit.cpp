#include "header.h"

static void helper(vector<vector<int>>& result, vector<int>& entry, vector<int>& nums, int pos, int cur, int size);

vector<vector<int>> subsets_r(vector<int>& nums)
{
    vector<vector<int>> result;

    // Loop the size from 1 to nums size
    for (int i = 1; i <= nums.size(); i++)
    {
        vector<int> entry(i, 0);
        helper(result, entry, nums, 0, 0, i);
    }
    // Add an empty combination
    result.push_back(vector<int>());

    return result;
}

void helper(vector<vector<int>>& result, vector<int>& entry, vector<int>& nums, int pos, int cur, int size)
{
    if (cur == size)
    {
        result.push_back(entry);
        return;
    }

    // Pick up one element and keep on going.
    for (int i = pos; i < nums.size(); i++)
    {
        entry[cur] = nums[i];
        helper(result, entry, nums, i + 1, cur + 1, size);
        entry[cur] = 0;
    }
}