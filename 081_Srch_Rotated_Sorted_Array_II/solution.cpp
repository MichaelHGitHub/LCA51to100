#include "header.h"

// An variant of binary search
bool search(vector<int>& nums, int target)
{
    bool result = false;
    int left = 0; 
    int right = nums.size() - 1;

    while (right >= left)
    {
        // Check edges
        if (nums[left] == target)
        {
            result = true;
            break;
        }

        if (nums[right] == target)
        {
            result = true;
            break;
        }

        // make edges unique
        if (left < nums.size() - 1 && nums[left] == nums[left + 1])
        {
            ++left;
            continue;
        }

        if (right > 0 && nums[right] == nums[right - 1])
        {
            --right;
            continue;
        }

        int mid = (right + left) / 2;

        // If nums[mid] doesn't equal to target, then we need to 
        // know where the mid is: before pivot or after pivot.
        if (nums[mid] == target)
        {
            result = true;
            break;
        }
        // Mid is before pivot
        else if (nums[mid] > nums[left])
        {
            // Search left part only when n[left] < target < n[mid]
            if (nums[left] < target && nums[mid] > target)
            {
                right = mid - 1;
                
            }
            else
            {
                left = mid + 1;
            }

        }
        // Mid is after pivot
        else
        {
            // Search right part only when n[mid] < target < n[right]
            if (nums[right] > target && nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return result;
}