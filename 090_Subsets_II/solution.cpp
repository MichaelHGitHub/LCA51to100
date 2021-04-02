#include <algorithm>
#include "header.h"

static void buildSet(vector<vector<int>>& result, vector<int>& combination, vector<int>& nums, int start, int n);

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> combination;

    sort(nums.begin(), nums.end());

    // Find the combination of i numbers of elements.
    for (int i = 0; i <= nums.size(); i++)
    {
        buildSet(result, combination, nums, 0, i);
    }

    return result;
}

void buildSet(vector<vector<int>>& result, vector<int>& combination, vector<int>& nums, int start, int n)
{
    if (n == 0)
    {
        result.push_back(combination);
        return;
    }

    if (start > nums.size() - 1)
    {
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        // Every start should be picked up. Only when the current element
        // is not start, we check duplication because if start is part of 
        // the prevous combination, the latter same element will definitely 
        // generate duplication.
        if (i != start && nums[i] == nums[i - 1])
        {
            continue;
        }

        combination.push_back(nums[i]);
        buildSet(result, combination, nums, i + 1, n - 1);
        combination.pop_back();
    }
}