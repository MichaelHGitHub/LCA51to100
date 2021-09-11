#include "header.h"

bool search_r(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    // First, let's divid the array into two sections by the original
    // nums[n-1] element.
    // And get rid of elements on the right side if it is equal to left
    // side so that later we can know if an element is in the first section
    // or second.
    while (right >= 0 && left != right && nums[left] == nums[right])
    {
        --right;
    }

    while (left <= right)
    {
        int mid = (right + left) / 2;

        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            if (nums[0] == target)
            {
                return true;
            }
            else if (nums[0] < target)
            {
                // target is in the first section
                right = mid - 1;
            }
            else
            {
                // target is in the second section

                if (nums[mid] >= nums[0])
                {
                    // mid is in the first section

                    left = mid + 1;
                }
                else
                {
                    // mid is in the second section

                    right = mid - 1;
                }
            }
        }
        else
        {
            if (nums[0] == target)
            {
                return true;
            }
            else if (nums[0] < target)
            {
                // target is in the first section

                if (nums[mid] >= nums[0])
                {
                    // mid is in the first section

                    left = mid + 1;
                }
                else
                {
                    // mide is in the second section 

                    right = mid - 1;
                }
            }
            else
            {
                // target is in the second section

                left = mid + 1;
            }
        }
    }
    return false;
}