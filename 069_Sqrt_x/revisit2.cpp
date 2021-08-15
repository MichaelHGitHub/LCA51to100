#include "header.h"

int mySqrt_r2(int x)
{
    int left = 1;
    int right = x;
    int root = 0;

    while (left <= right)
    {
        int mid = ((double)left + right) / 2;
        int remain = x / mid;
        if (remain == mid)
        {
            root = mid;
            break;
        }
        else if (remain > mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (right < left)
    {
        return right;
    }
    else
    {
        return root;
    }
}