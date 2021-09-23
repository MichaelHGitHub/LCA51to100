#include "header.h"
#include <algorithm>

void subSet(vector<vector<int>>& result, vector<int>& entry, int count, int posInEntry, vector<int>& nums, int posInNums);

vector<vector<int>> subsetsWithDup_r(vector<int>& nums)
{
    // group duplicate elements in order to get rid of duplicate set
    // in results
    std::sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    // Loop the numbers of elements we need for one set.
    for (int i = 0; i <= nums.size(); i++)
    {
        vector<int> entry(i, 0);
        subSet(result, entry, i, 0, nums, 0);
    }

    return result;
}

void subSet(vector<vector<int>>& result, vector<int>& entry, int count, int posInEntry, vector<int>& nums, int posInNums)
{
    // One set is ready
    if (count == posInEntry)
    {
        result.push_back(entry);
        return;
    }

    // No enough element for one set.
    if (count - posInEntry > nums.size() - posInNums)
    {
        return;
    }

    for (int i = posInNums; i < nums.size(); i++)
    {
        // Skip element that is duplicate as previous one
        if (i > posInNums && nums[i] == nums[i - 1])
        {
            continue;
        }

        entry[posInEntry] = nums[i];
        subSet(result, entry, count, posInEntry + 1, nums, i + 1);
        entry[posInEntry] = 0;
    }
}