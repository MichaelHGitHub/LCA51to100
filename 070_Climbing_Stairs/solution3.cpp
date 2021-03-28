#include "header.h"

static int countDiffWay(vector<int>& ways, int n, int start);

int climbStairs3(int n)
{
    if (n < 3)
    {
        return n;
    }

    vector<int> ways(n + 1, 0);
    ways[n - 1] = 1;
    ways[n - 2] = 2;

    for (int i = 3; i <= n; i++)
    {
        ways[n - i] = ways[n - i + 1] + ways[n - i + 2];
    }

    return ways[0];
}

