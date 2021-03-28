#include "header.h"

// Loop through the input ranges. 
// Before new range is inserted:
// For each range, the new range has three probabilites:
// 1. new range should be inserted before the current range without overlap
//      In this case add new range to result, and add current range.
// 2. new range should be place somewhere after the current range without overlap
//      In this case, add only the current range to result
// 3. There are overlap in the new range and the current range. 
//      In this case, find mininum low boundary and maximum high boundary
//      add the merged range to result.
// After new range is inserted:
// check if the high boundary of the last range in result has overlap 
// with the current range, if yes, merge them, otherwise just 
// add current range to result. 
// Note: It's so easy to forget to check if new range is 
// actually inserted after the looping of input ranges. 
// If still not inserted, add new range as the last range
// in the result. 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> result;
    bool inserted = false;

    if (intervals.size() == 0)
    {
        result.push_back(newInterval);
        return result;
    }

    for (int i = 0; i < intervals.size(); i++)
    {
        if (!inserted)
        {
            // The new range should be placed somewhere after the current range
            if (newInterval[0] > intervals[i][1])
            {
                result.push_back(intervals[i]);
            }
            // the new range should be inserted before the current range
            else if (newInterval[1] < intervals[i][0])
            {
                result.push_back(newInterval);
                result.push_back({ intervals[i]});
                inserted = true;
            }
            // There is overlap between the new range and the current range
            else
            {
                int start = min(newInterval[0], intervals[i][0]);
                int end = max(newInterval[1], intervals[i][1]);
                result.push_back({ start, end });
                inserted = true;
            }
        }
        else
        {
            // Check if the last range in result had overlap with current range
            if (result[result.size() - 1][1] >= intervals[i][0])
            {
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
    }

    // If new range hasn't been added, add it.
    if (!inserted)
    {
        result.push_back(newInterval);
        inserted = true;
    }
    return result;
}

