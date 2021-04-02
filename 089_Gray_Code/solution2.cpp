#include "header.h"

static void getGrayCode(vector<int>& result, int n);

// Through obsevation, we know that for a given n, there are 2^n numbers
// of gray codes. we can allocate the space in advance to reduce over head.
// The gray codes of n can be formed by: codes(n-1) + (codes(n-1) | (1 << (n - 1)));
// Again, this is quite easy to be found if you write the results of n = [1, 2, 3]
// in binary format. 
vector<int> grayCode2(int n)
{
    int code_nums = 1 << n;
    vector<int> result(code_nums, 0);

    getGrayCode(result, n);

    return result;
}


void getGrayCode(vector<int>& result, int n)
{
    if (n == 1)
    {
        result[0] = 0;
        result[1] = 1;
        return;
    }

    // Get gray codes for n-1 first.
    getGrayCode(result, n - 1);

    int offset = 1 << (n - 1);
    int pre_code_nums = offset;
    for (int i = pre_code_nums - 1; i >= 0; i--)
    {
        // All these fancy calculation just to make the result order
        // the same as the ones showing in the examples. There are simpler
        // ways to do it.  but it doesn't affect performance anyway.
        result[2 * pre_code_nums - 1 - i] = result[i] | offset;
    }
}