#include <map>
#include "header.h"

static int decodeString(vector<int>& records, string& s, int start);

// For each of the char in the string, there are two possibilities:
// decode single or double digits.Use dynamic programming, the 
// ways to decode each char all the way to the end is: 
// ways(current + 1) + ways(current + 2). 
// The ways of ways[0] is the answer we need.
int numDecodings(string s)
{
    vector<int> records(s.length(), -1);
    return decodeString(records, s, 0);
}

static int decodeString(vector<int>& records, string& s, int start)
{
    // Decoding reaches the end, the path is correct.
    if (start == s.length())
    {
        return 1;
    }

    // If the current char hasn't been checked yet
    if (records[start] == -1)
    {
        records[start] = 0;

        if (s[start] >= '1' && s[start] <= '9')
        {
            // How many ways we can reach the end if we decode the current
            // char as single digit
            records[start] += decodeString(records, s, start + 1);
        }

        if (start < s.length() - 1)
        {
            string two_dig = s.substr(start, 2);

            if (two_dig >= "10" && two_dig <= "26")
            {
                // How many ways we can reach the end if we decode the current
                // char as double digits
                records[start] += decodeString(records, s, start + 2);
            }
        }
    }

    return records[start];
}