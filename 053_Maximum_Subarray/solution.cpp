#include "header.h"

//
// Loop through the array, for each element, after handling each 
// check and save the larget sum. 
// 1. if the previous sum is negative, then reset sum to 
// the current element. 
// 2. If the previous sum is not negative, then do sum += the element.
// 
int maxSubArray(vector<int>& nums)
{
    int sum = nums[0];
    int result = sum;
    for (int i = 1; i < nums.size(); i++)
    {
        // Reset sum if sum is negative
        if (sum < 0)
        {
            sum = nums[i];
        }
        else
        {
            // (sum + nums[i]) could be less than sum, 
            // but the previous sum is already saved in
            // result. so it's safe to do so. 
            sum += nums[i];
        }
        
        result = max(result, sum);
    }

    return result;
}