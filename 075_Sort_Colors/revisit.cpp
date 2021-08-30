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

void sortColors_r(vector<int>& nums)
{
    // move 0 to the begining
    int insert = 0;
    int pos = insert + 1;
    while(insert < nums.size() && pos < nums.size())
    {
        if (nums[insert] == 0)
        {
            ++insert;
            ++pos;
        }
        else
        {
            if (nums[pos] != 0)
            {
                ++pos;
            }
            else
            {
                if (nums[insert] != nums[pos])
                {
                    swap(nums, insert, pos);
                }
                ++insert;
                ++pos;
            }
        }
    }

    // move 1 after 0
    pos = insert + 1;
    while (insert < nums.size() && pos < nums.size())
    {
        if (nums[insert] == 1)
        {
            ++insert;
            ++pos;
        }
        else
        {
            if (nums[pos] != 1)
            {
                ++pos;
            }
            else
            {
                if (nums[insert] != nums[pos])
                {
                    swap(nums, insert, pos);
                }
                ++insert;
                ++pos;
            }
        }
    }
}