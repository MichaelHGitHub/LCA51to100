#include "header.h"

static bool canJumpFromHere(vector<int>& nums, int here);

bool canJump2(vector<int>& nums)
{
    return canJumpFromHere(nums, 0);
}

bool canJumpFromHere(vector<int>& nums, int here)
{
    if (here == nums.size() - 1)
    {
        return here;
    }

    for (int i = 1; i <= nums[here]; i++)
    {
        if (canJumpFromHere(nums, here + i))
        {
            return true;
        }
    }

    return false;
}