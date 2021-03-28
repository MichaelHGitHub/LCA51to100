#include "header.h"

static void countDiffWay(int& path, int n, int start);

int climbStairs(int n)
{
    int path = 0;
    countDiffWay(path, n, 0);

    return path;
}

void countDiffWay(int& path, int n, int start)
{
    if (start == n)
    {
        path++;
        return;
    }
    else if (start > n)
    {
        return;
    }

    countDiffWay(path, n, start + 2);
    countDiffWay(path, n, start + 1);
}