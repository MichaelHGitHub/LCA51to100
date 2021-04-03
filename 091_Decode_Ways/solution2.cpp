#include <map>
#include "header.h"

// For each of the char in the string, there are two possibilities:
// decode single or double digits.Use dynamic programming, the 
// ways to reach current char is: 
// ways(current - 1) + ways(current - 2). 
// The number of ways[last_char] is the answer we need.
int numDecodings2(string s)
{
    vector<int> records(s.length(), 0);

    if (s[0] == '0')
    {
        return 0;
    }

    records[0] = 1;

    for (int i = 1; i < s.length(); i++)
    {
        int way1 = 0;
        int way2 = 0;

        if (s[i] >= '1' && s[i] <= '9')
        {
            // How many ways we can reach the current if we decode the current
            // char as single digit
            way1 = records[i - 1];
        }

        string two_dig = s.substr(i - 1, 2);
        if (two_dig >= "10" && two_dig <= "26")
        {
            // How many ways we can reach the cureent if we decode the current
            // char as double digits along with the previous char
            if (i > 1)
            {
                way2 = records[i - 2];
            }
            else
            {
                way2 = 1;
            }
        }

        // The total ways we can reach the current char
        records[i] = way1 + way2;

    }

    return records[s.length() - 1];
}

