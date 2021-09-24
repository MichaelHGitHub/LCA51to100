#include "header.h"

int numDecodings_r(string s)
{
    int ways_pre = 1;
    int ways_pre_pre = 1;
    int ways = 0;
    int digit_pre = -1;

    for (int i = 0; i < s.length(); i++)
    {
        int digit = s[i] - '0';

        if (0 == digit)
        {
            if (digit_pre < 1 || digit_pre > 2)
            {
                ways = 0;
                break;
            }
            else
            {
                ways = ways_pre_pre;
            }

        }
        else if (digit > 6)
        {
            if (1 == digit_pre)
            {
                ways = ways_pre_pre + ways_pre;
            }
            else
            {
                ways = ways_pre;
            }
        }
        else
        {
            if (digit_pre < 1 || digit_pre > 2)
            {
                ways = ways_pre;
            }
            else
            {
                ways = ways_pre_pre + ways_pre;
            }
        }

        digit_pre = digit;
        ways_pre_pre = ways_pre;
        ways_pre = ways;
    }

    return ways;
}