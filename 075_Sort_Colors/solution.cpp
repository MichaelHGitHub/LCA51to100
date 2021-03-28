#include "header.h"

void swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 
// Since there are only 0, 1, 2 in the array, 
// it is simpler to sort the array than to sort a 
// regular int array. No need to do typical sorting algorithm.
// Use three pointers, left, right and index, which moves from
// left to right.
// Traverse the array from left to right, swap 0 to left and 
// 2 to right, leave 1 in the middle.
void sortColors(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return;
    }

    int left = 0;
    int right = nums.size() - 1;

    int i = left;
    while (i >= 0 && i < nums.size() && i <= right)
    {
        if (i > left && nums[i] == 0)
        {
            swap(nums, i, left);
            ++left;
            i = left;
            continue;
        }

        if (i < right && nums[i] == 2)
        {
            swap(nums, i, right);
            --right;
            continue;
        }

        // nums[i] is 1, check next one
        ++i;
    }
}