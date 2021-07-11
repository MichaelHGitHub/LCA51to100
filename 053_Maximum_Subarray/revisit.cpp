#include "header.h"

int maxSubArray_r(vector<int>& nums)
{
    int sum = INT32_MIN;
    int phase_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        phase_sum += nums[i];
        sum = max(sum, phase_sum);

        if (phase_sum < 0)
        {
            phase_sum = 0;
        }
    }

    return sum;
}