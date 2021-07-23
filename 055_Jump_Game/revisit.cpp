#include "header.h"

bool canJump_r(vector<int>& nums)
{
    int farthest = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (farthest >= i)
        {
            farthest = max(farthest, nums[i] + i);
        }
    }
    return (farthest >= nums.size() - 1);
}