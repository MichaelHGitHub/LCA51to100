#include "header.h"

static int countDiffWay(vector<int>& ways, int n, int start);

// Use an array to store intermediate result such that we can reduce recurrsion
int climbStairs2(int n)
{
    vector<int> ways(n + 1, 0);
    return countDiffWay(ways, n, 0);
}

int countDiffWay(vector<int>& ways, int n, int start)
{
    if (start > n)
    {
        return 0;
    }

    if (start == n)
    {
        ways[start] = 1;
    }
    else if (ways[start] == 0)
    {
        ways[start] = countDiffWay(ways, n, start + 1) + countDiffWay(ways, n, start + 2);
    }

    return ways[start];

}