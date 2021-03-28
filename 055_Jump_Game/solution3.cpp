#include "header.h"

// Start from right searching towards left.
// Find the last jumpping-point from which you jump and
// can reach the last element.
// If the last jumping-point finally reaches the beginging,
// that means you can jump from first to the last element. 

bool canJump3(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return true;
    }

    bool result = false;

    int lastJumpFrom = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i + nums[i] >= lastJumpFrom)
        {
            lastJumpFrom = i;
        }

    }

    if (lastJumpFrom == 0)
    {
        result = true;
    }

    return result;
}