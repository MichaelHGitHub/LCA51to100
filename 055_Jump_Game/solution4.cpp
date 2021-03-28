#include "header.h"

// This is from someone's post on leetcode
// it can prolong the dist along the way, so that it can 
// jump over the 0 ahead of it. clever.
bool canJump4(vector<int>& nums)
{
    int dist = nums[0];
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        dist = max(dist, nums[i]);

        if (dist <= 0 && i != n - 1)
            return false;

        dist--;
    }

    return true;
}