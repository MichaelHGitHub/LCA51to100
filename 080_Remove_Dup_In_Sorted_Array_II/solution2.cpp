#include "header.h"

// Two pointers
// Pointer-1: the next place where a validate element should go to.
// Pointer-2: the element that is being checked.
// No matter what value the previous two elements before pointer-1, 
// they are all good. 
// As pointer-2 is always ahead of or the same as pointer-1, 
// if nums[Pointer-1 - 2] == nums[Pointer-2], nums[Pointer-1 - 1] 
// must equal to nums[Pointer-2] as well, then nums[Pointer-2] is not 
// valid, otherwise need to be picked up and place it to nums[Pointer-1].
int removeDuplicates2(vector<int>& nums)
{

    if (nums.size() < 3)
    {
        return nums.size();
    }

    int index = 2;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[index - 2] != nums[i])
        {
            nums[index] = nums[i];
            ++index;
        }
    }

    return index;
}