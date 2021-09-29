#include "header.h"
#include <map>

int countBST(map<pair<int,int>, int>& history, int begin, int end);

int numTrees_r(int n)
{
    map<pair<int, int>, int> history;
    return countBST(history, 1, n);
}

int countBST(map<pair<int, int>, int>& history, int begin, int end)
{
    if (begin > end)
    {
        return 0;
    }
    int count = 0;

    pair<int, int> range(begin, end);

    if (history.find(range) != history.end())
    {
        count = history[range];
    }
    else
    {
        for (int i = begin; i <= end; i++)
        {
            int count_left = countBST(history, begin, i - 1);
            int count_right = countBST(history, i + 1, end);

            if (count_left && count_right)
            {
                count += (count_left * count_right);
            }
            else if (count_left)
            {
                count += count_left;
            }
            else if (count_right)
            {
                count += count_right;
            }
            else
            {
                count++;
            }
        }

        history[range] = count;
    }
    return count;
}