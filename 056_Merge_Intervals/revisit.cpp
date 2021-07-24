#include <algorithm>
#include "header.h"

vector<vector<int>> merge_r(vector<vector<int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
        {
            return (a[0] < b[0]);
        }
    );

    int start = intervals[0][0];
    int end = intervals[0][1];

    vector<vector<int>> result;

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > end)
        {
            result.push_back({ start, end });
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else
        {
            end = max(end, intervals[i][1]);
        }
    }
    result.push_back({ start, end });

    return result;
}