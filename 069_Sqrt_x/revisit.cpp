#include "header.h"

int mySqrt_r(int x)
{
    int root = 1;
    int pre = root;

    while (true)
    {
        if (root == x / root)
        {
            break;
        }
        else if(root < x / root)
        {
            pre = root;
        }
        else
        {
            root = pre;
            break;
        }
        ++root;
    }

    return root;
}