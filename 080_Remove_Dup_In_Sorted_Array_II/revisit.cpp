#include "header.h"

int removeDuplicates_r(vector<int>& nums)
{
    int new_pos = 1;
    int old_pos = 1;
    int count = 1;

    while (new_pos < nums.size() && old_pos < nums.size())
    {
        if (nums[new_pos - 1] != nums[old_pos])
        {
            count = 1;
            nums[new_pos++] = nums[old_pos++];
        }
        else
        {
            if (count < 2)
            {
                ++count;
                nums[new_pos++] = nums[old_pos++];
            }
            else
            {
                ++count;
                ++old_pos;
            }
        }
    }
    return new_pos;
}