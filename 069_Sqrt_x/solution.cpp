#include "header.h"

// Use a seed that can grow the root faster than increament by 1 each time.
// Check if (x/(root + seed) > (root + seed)), if yes, grow the 
// seed by multiplying 2, otherwise reset the seed to 1 until find the 
// root.
int mySqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }

    int root = 1;
    int seed = 1;

    // Use division to avoid out of int range
    while (x / root > root)
    {
        // Find the exact root
        if (x / (root + seed) == (root + seed))
        {
            root += seed;
            break;
        }
        // Root+seed is still too small, grow the seed
        else if (x / (root + seed) > (root + seed))
        {
            root += seed;
            seed *= 2;
        }
        // Root+seed is too big, reset seed to 1
        else if( seed > 1)
        {
            seed = 1;
        }
        // Root+seed is too big, and seed is already 1, root is found
        else
        {
            break;
        }
    }

    return root;
}