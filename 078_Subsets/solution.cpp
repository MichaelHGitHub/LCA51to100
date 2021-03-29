#include "header.h"

static void buildCombination(vector<vector<int>>& result, vector<int>& combination, vector<int>& nums, int start, int k);

// In Problem 77, we already know how to get the combinations of 
// k numbers out of n numbers.
// Now we only need to get the combinations of 1 number out of n numbers,
// the combinations of 2 numbers out of n numbers. keep going until we get
// the combinations of n numbers out of n numbers. put them together, that's 
// the result we need.
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> combination;
    result.push_back(combination);

    // Here i represents the numbers we need each time to build the combinations
    for (int i = 1; i <= nums.size(); i++)
    {
        buildCombination(result, combination, nums, 0, i);
    }

    return result;
}

void buildCombination(vector<vector<int>>& result, vector<int>& combination, vector<int>& nums, int start, int k)
{
    if (k == 0)
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
        combination.push_back(nums[i]);
        buildCombination(result, combination, nums, i + 1, k - 1);
        combination.pop_back();
    }
}