#include <algorithm>
#include "header.h"

// First sort the input arrays by the start value of each array
// then for each range, if end is larger than next start, it can be merged
// with picking the largest end among these two. if a range can't be merged,
// add the previous one we found, and reset start and end and keep on searching.
// add all search is done, add the very last range to result. 

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() == 1)
    {
        return intervals;
    }

    vector<vector<int>> result;
    std::sort(intervals.begin(), intervals.end());

    // First candidate range
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 0; i < intervals.size(); i++)
    {
        if (end >= intervals[i][0])
        {
            // the current rang can be merged with previous range
            // update the end
            end = max(intervals[i][1], end);
        }
        else
        {
            // the current range can't be merged with previous rang,
            // add the pevious range to the result

            result.push_back(vector<int>({ start, end }));
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Don't forget to add the last range
    result.push_back(vector<int>({ start, end }));

    return result;
}