#include <map>
#include "header.h"

static int getTreeNumOfRange(map<pair<int, int>, int>& history, int start, int end);

// Recursively get the combination number for each node and the 
// root while its left side nodes as its left decendants and right
// side nodes as its right decendants.
// Use a map to store the history so that we can greatly reduce
// duplicated calculation.
int numTrees(int n)
{
    map<pair<int, int>, int> history;
    return getTreeNumOfRange(history, 1, n);
}

int getTreeNumOfRange(map<pair<int, int>, int>& history, int start, int end)
{
    if (start > end)
    {
        return 1;
    }

    int count = 0;
    for (int i = start; i <= end; i++)
    {
        int left_num = 0;
        int right_num = 0;
        pair<int, int> left_pair(start, i - 1);
        pair<int, int> right_pair(i + 1, end);

        if (history.find(left_pair) != history.end())
        {
            left_num = history[left_pair];
        }
        else
        {
            left_num = getTreeNumOfRange(history, start, i - 1);
            history[left_pair] = left_num;
        }

        if (history.find(right_pair) != history.end())
        {
            right_num = history[right_pair];
        }
        else
        {
            right_num = getTreeNumOfRange(history, i + 1, end);
            history[right_pair] = right_num;
        }

        count += left_num * right_num;
    }

    history[pair<int, int>(start, end)] = count;
    return count;
}