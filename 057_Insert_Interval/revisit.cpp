#include "header.h"

vector<vector<int>> insert_r(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    if (intervals.size() == 0)
    {
        return vector<vector<int>>({ newInterval });
    }

    int start = intervals[0][0];
    int end = intervals[0][1];

    bool merged = false;
    vector<vector<int>> result;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (!merged)
        {
            if (newInterval[1] < start)
            {
                // New range goes before the current range.
                merged = true;
                result.push_back({ newInterval });
            }
            else if (newInterval[0] <= end)
            {
                // New range gets merged with current range.
                merged = true;
                start = min(start, newInterval[0]);
                end = max(end, newInterval[1]);
            }
        }

        if (intervals[i][0] > end)
        {
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else
        {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
        }
    }

    if (!merged)
    {
        // Last range hasn't tried to merge with new range.
        if (newInterval[1] < start)
        {
            // New range goes before the current range.
            merged = true;
            result.push_back({ newInterval });
        }
        else if (newInterval[0] <= end)
        {
            // New range gets merged with current range.
            merged = true;
            start = min(start, newInterval[0]);
            end = max(end, newInterval[1]);
        }
        else
        {
            // New range goes to the very end
            result.push_back({ start, end });
            start = newInterval[0];
            end = newInterval[1];
        }
    }
    result.push_back({ start, end });
    return result;
}