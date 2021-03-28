#include "header.h"

// Binary search
int mySqrt2(int x)
{
    if (x < 2)
    {
        return x;
    }

    int left = 1;
    int right = x;
    int root = 1;

    while (right >= left)
    {
        root = left + (right - left) / 2;

        if (x / root == root)
        {
            break;
        }
        // root is still small, increase left
        else if (x / root > root)
        {
            left = root + 1;
        }
        // root is too big, decrease right
        else
        {
            right = root - 1;
        }
    }

    if (x / root == root)
    {
        return root;
    }
    // now left > right, that means one step before, left=right 
    // that's actually the value we need
    else
    {
        return left - 1;
    }
}