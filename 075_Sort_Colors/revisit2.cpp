#include "header.h"

static void swap(vector<int>& nums, int i, int j)
{
    if (i != j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// Move 0 to left, 2 to right in one pass
void sortColors_r2(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int pos = left;

    while (left < right && pos <= right)
    {
        if (nums[pos] == 0 && pos > left)
        {
            swap(nums, left, pos);
            ++left;
        }
        else if (nums[pos] == 2 && pos < right)
        {
            swap(nums, pos, right);
            --right;
        }
        else
        {
            ++pos;
        }
    }
}