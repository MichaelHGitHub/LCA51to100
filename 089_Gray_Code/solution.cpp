#include "header.h"

static void getGrayCode(vector<vector<int>>& codes, int code_nums);

// Through obsevation, we know that for a given n, there are 2^n numbers
// of gray codes. we can allocate the space in advance to reduce over head.
// The gray codes of n can be formed by: codes(n-1) + ( each of codes(n-1) + 1 bit at the beginning);
// Again, this is quite easy to be found if you write the results of n = [1, 2, 3]
// in binary format. 
// Steps:
// 1. Build the bits( stored in vector)
// 2. Calculate each number by converting bits to decimal.
vector<int> grayCode(int n)
{
    int code_nums = 1 << n;

    // Save codes in bits format
    vector<vector<int>> codes(code_nums, vector<int>());

    getGrayCode(codes, code_nums);

    vector<int> result(code_nums, 0);

    for (int i = 0; i < codes.size(); i++)
    {
        int number = 0;

        for (int j = 0; j < codes[i].size(); j++)
        {
            number += (codes[i][j] * (1 << j));
        }

        result[i] = number;
    }
    return result;
}


static void getGrayCode(vector<vector<int>>& codes, int code_nums)
{
    if (code_nums == 2)
    {
        codes[0].push_back(0);
        codes[1].push_back(1);
        return;
    }

    int pre_code_nums = code_nums >> 1;

    getGrayCode(codes, pre_code_nums);

    for (int i = pre_code_nums - 1; i >= 0; i--)
    {
        // Copy the result codes(n - 1), fill in the other half of the result first
        codes[2*pre_code_nums - 1 - i].assign(codes[i].begin(), codes[i].end());
        // Add one bit (0 and 1) to the existing result of n -1. 
        // The bits are in reverse order, highest bit is at the end of the vector
        codes[2 * pre_code_nums - 1 - i].push_back(1);
        codes[i].push_back(0);
    }
}