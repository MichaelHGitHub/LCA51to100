#include "header.h"

//
// Loop through the array, for each element, after handling each 
// check and save the larget sum. 
// 1. If the previous sum is negative, then reset sum to 
// the current element. 
// 2. If the previous sum is not negative, then do sum += the element.
// 
int maxSubArray2(vector<int>& nums)
{
    int sum = nums[0];
    int result = sum;
    for (int i = 1; i < nums.size(); i++)
    {
        sum = max(nums[i], sum + nums[i]);
        result = max(result, sum);
    }

    return result;
}