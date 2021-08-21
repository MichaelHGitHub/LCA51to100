#include "header.h"

static void helper(int& path_num, int i, int n);

int climbStairs_r(int n)
{
    int path_num = 0;

    helper(path_num, 0, n);

    return path_num;
}

void helper(int& path_num, int i, int n)
{
    if (i == n)
    {
        ++path_num;
    }
    else if (i > n)
    {
        return;
    }

    helper(path_num, i + 1, n);
    helper(path_num, i + 2, n);
}