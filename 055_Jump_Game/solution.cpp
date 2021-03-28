#include "header.h"

// It is not hard to find that the only bad guys are 0, 
// all the rest of elements can jump a range from 1 to its 
// value steps.
// So, if we scan the array from right to left, when we 
// meet a 0-value-element, check elements before it to see
// if any element can jump over the current bad 0, if yes
// we jump to that element and continue our searching.
// if we finally reaches the beging of the array, we know 
// we can jump from first to last element. 
// Note: 
// very first/last 0-value element needs special check.

bool canJump(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return true;
    }

    bool result = false;

    int i = nums.size() - 1;
    while (i>= 0)
    {
        // the current element is 0
        if (nums[i] == 0)
        {
            int j = i - 1;

            // if nums[0] == 0, return false;
            if (j < 0)
            {
                result = false;
                break;
            }
            else
            {
                // Check if any element before the current 0-value-element
                // can jump over the current 0-value-element. 
                // Note: but for the very last 0 in the array, no need to 
                // jump-over, just need to jump-to.
                while (j >= 0 &&
                       ((i < nums.size() - 1 && nums[j] <= i - j) ||
                        (i == nums.size() - 1 && nums[j] < i - j)))
                {
                    --j;
                }

                // An element from which can jump over/to the current element
                // is not found. 
                if (j < 0)
                {
                    result = false;
                    break;
                }
                // Such an element is found, jump to the element before it,
                // keep our searching.
                else
                {
                    i = j - 1;
                }
            }
        }
        else
        {
           --i;
        }
    }

    // Reach the beginning of the array
    if (i < 0)
    {
        result = true;
    }

    return result;
}