#include "header.h"

int maxSubArray_r2(vector<int>& nums)
{
    vector<int> sums(nums.size(), 0);
    sums[0] = nums[0];
    int result = sums[0];

    for (int i = 1; i < sums.size(); i++)
    {
        sums[i] = max(nums[i], nums[i] + sums[i - 1]);
        result = max(result, sums[i]);
    }

    return result;
}