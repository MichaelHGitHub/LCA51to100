#include "header.h"

// Three pointers
// Pointer-1: the next place where a validate element should go to.
// Pointer-2: the start of the phase of the same number(s).
// Pointer-3: one place after the phase of the same number(s).
// In the case where a phase of numbers is determined, pick up  1 or 2 
// valid elements, depending on the the gap between pointer-2 and
// pointer-3, and replace them to the place of Pointer-1.
int removeDuplicates(vector<int>& nums)
{
    int start = 0;
    int end = 1;
    int index = 0;
    int move = 0;

    while (end < nums.size())
    {
        // Search the end of the same number phase
        if (nums[start] == nums[end])
        {
            ++end;
            continue;
        }

        // Pick up valid elements
        move = min(end - start, 2);
        for (int i = 0; i < move; i++)
        {
            nums[index++] = nums[start++];
        }

        start = end;
        ++end;
    }

    // Don't forget the last phase, which is not handled in the above
    // loop
    while (start < end)
    {
        move = min(end - start, 2);
        for (int i = 0; i < move; i++)
        {
            nums[index++] = nums[start++];
        }
        break;
    }

    return index;
}